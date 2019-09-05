//https://www.dreamincode.net/forums/topic/59656-color-text-in-c-programming/page__p__394955&#entry394955

#pragma once

#include <visualize/visualize.hh>

#include <stdio.h>
#include <string>
#include <iostream>

namespace CLIProteinViewer {
namespace color {

namespace MagicNumbers {
  //attr
  constexpr int  RESET =    0;
  constexpr int  BRIGHT =   1;
  constexpr int  DIM =      2;
  constexpr int  UNDERLINE= 3;
  constexpr int  BLINK =    4;
  constexpr int  REVERSE =  7;
  constexpr int  HIDDEN =   8;

  //fg/bg
  constexpr int  BLACK =    0;
  constexpr int  RED =      1;
  constexpr int  GREEN =    2;
  constexpr int  YELLOW =   3;
  constexpr int  BLUE =     4;
  constexpr int  MAGENTA =  5;
  constexpr int  CYAN =     6;
  constexpr int  WHITE =    7;

  constexpr int DIMGAP = 100;//gap to designate dimming
}

struct Color {
  Color() :
    r( 0 ),
    g( 0 ),
    b( 0 ),
    code( 0 )
  {}

  Color( int R, int G, int B, int Code ) :
    r( R ),
    g( G ),
    b( B ),
    code( Code )
  {}

  Color( Color const & src ):
    r( src.r ),
    g( src.g ),
    b( src.b ),
    code( src.code )
  {}

  int r;
  int g;
  int b;
  int code;

  bool is_system() const { return code < 16; }
};

struct CustomColorMatcher {
  std::vector< Color > colors;

  void add_color( int r, int g, int b, int code ){
    colors.emplace_back( r, g, b, code );
  }

  int determine_closest_code( int r, int g, int b, bool must_be_system = false ) const {
    int closest_code = 0;
    float closest_score = 9999999999999999;

    //std::cout << r << " " << g << " " << b << std::endl;
    for( unsigned i = 0; i < colors.size(); ++i ){
      Color const & c = colors[ i ];
      if( must_be_system && ! c.is_system() ) break;

      float const r_diff = c.r - r;
      float const g_diff = c.g - g;
      float const b_diff = c.b - b;
      float const diff_sq = (r_diff*r_diff) + (g_diff*g_diff) + (b_diff*b_diff);

      //std::cout << diff_sq << " " << closest_code << std::endl;

      if( diff_sq < closest_score ){
	closest_score = diff_sq;
	closest_code = c.code;
      }
    }

    return closest_code;
  }

  unsigned int num_colors() const { return colors.size(); }
};


void textcolor(int attr, int fg, int bg) {
  char command[13];

  /* Command is the control command to the terminal */
  sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
  printf("%s", command);
}

void print_nearest_color( int r, int g, int b ){
  static CustomColorMatcher ccm;
  if( ccm.num_colors() == 0 ){
    ccm.add_color( 0, 0, 0, MagicNumbers::BLACK );
    ccm.add_color( 255, 0, 0, MagicNumbers::RED );
    ccm.add_color( 0, 255, 0, MagicNumbers::GREEN );
    ccm.add_color( 0, 0, 255, MagicNumbers::BLUE );
    ccm.add_color( 255, 0, 255, MagicNumbers::MAGENTA );
    ccm.add_color( 255, 255, 0, MagicNumbers::YELLOW );
    ccm.add_color( 0, 255, 255, MagicNumbers::CYAN );
    ccm.add_color( 255, 255, 255, MagicNumbers::WHITE );

    //TODO:
    ccm.add_color( 127, 0, 0, MagicNumbers::RED + MagicNumbers::DIMGAP );
    ccm.add_color( 0, 127, 0, MagicNumbers::GREEN + MagicNumbers::DIMGAP );
    ccm.add_color( 0, 0, 127, MagicNumbers::BLUE + MagicNumbers::DIMGAP );
    ccm.add_color( 127, 0, 127, MagicNumbers::MAGENTA + MagicNumbers::DIMGAP );
    ccm.add_color( 127, 127, 0, MagicNumbers::YELLOW + MagicNumbers::DIMGAP );
    ccm.add_color( 0, 127, 127, MagicNumbers::CYAN + MagicNumbers::DIMGAP );
    ccm.add_color( 127, 127, 127, MagicNumbers::WHITE + MagicNumbers::DIMGAP );

  }
  int code = ccm.determine_closest_code( r, g, b );
  bool dim = code > MagicNumbers::DIMGAP;

  if( dim ){    
    textcolor( MagicNumbers::DIM, code - MagicNumbers::DIMGAP, MagicNumbers::BLACK );
  } else {
    textcolor( MagicNumbers::BRIGHT, code, MagicNumbers::BLACK);
  }

  //printf( std::to_string(code).c_str() );
  printf( "X" );

  //reset
  textcolor( MagicNumbers::RESET, MagicNumbers::WHITE, MagicNumbers::BLACK );
}

void print_nearest_color( visualize::Pixel const & p ){
  print_nearest_color( p.r, p.g, p.b );
}

/*
  int main() {
  //char special_char = '◼︎';
  textcolor(BRIGHT, RED, BLACK);
  std::cout << "X";
  textcolor(BRIGHT, GREEN, BLACK);
  std::cout << "X";
  textcolor(RESET, WHITE, BLACK);
  std::cout << std::endl;
  return 0;
  }
*/

}//color
}//CLIPV
