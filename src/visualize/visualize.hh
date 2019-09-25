#pragma once

#include <vector>

#include <iostream>

//From https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
#include <sys/ioctl.h> // For ioctl, TIOCGWINSZ
#include <unistd.h> // For STDOUT_FILENO

namespace CLIProteinViewer {
namespace visualize {

struct Pixel {
  Pixel() :
    r( 0 ),
    g( 0 ),
    b( 0 )
  {}

  Pixel( int R, int G, int B ) :
    r( R ),
    g( G ),
    b( B )
  {}

  int r;
  int g;
  int b;

  template< typename Matcher >
  int determine_closest_code( Matcher const & matcher ){
    return matcher.determine_closest_code( r, g, b );
  }
};

struct Screen {
  Screen(){
    struct winsize size;
    ioctl( STDOUT_FILENO, TIOCGWINSZ, &size );
    auto const ncols = size.ws_col;
    auto const nrows = size.ws_row;
    pixels.resize( nrows );
    for( std::vector< Pixel > & v : pixels ){
      v.resize( ncols );
    }
  }

  int height() const { return pixels.size(); }

  int nrow() const { return height(); }

  int width() const { return pixels[0].size(); }

  int ncol() const { return width(); }

  Pixel & pixel( int h, int w ){ return pixels[h][w]; }

  Pixel const & pixel( int h, int w ) const { return pixels[h][w]; }

  Pixel & pixel_rowcol( int row, int col ) { return pixel( row, col ); }

  Pixel const & pixel_rowcol( int row, int col ) const { return pixel( row, col ); }

  std::vector< std::vector< Pixel > > pixels; //outer vec is height, inner is width

  void set_to_splash_screen();
};

void
draw(
  Screen const & screen
){
  for( std::vector< Pixel > const & row : screen.pixels ){
    for( Pixel const & pix : row ){
      std::cout << "COLOR" << "MAGIC";
    }
    std::cout << std::endl;
  }
}

inline
void
Screen::set_to_splash_screen(){
  int const w_max = width();
  int const h_max = height();

  for( int w = 0; w < w_max; ++w ){
    for( int h = 0; h < h_max; ++h ){
      Pixel & p = pixel( h, w );

      //r aligns with width
      p.r = (float(w) / w_max) * 256;

      //g aligns with height
      p.g = (float(h) / h_max) * 256;

      //b aligns with h+w
      p.b = (float(w+h) / (w_max + h_max) ) * 256;
    }
  }
}

}//namespace visualize
}//namespace CLIProteinViewer
