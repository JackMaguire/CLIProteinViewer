#pragma once
#include <array>

#include <visualize/colors.hh>

/*
  Useful links:
  https://jonasjacek.github.io/colors/
  https://stackoverflow.com/questions/33419215/how-to-change-the-color-of-text-to-any-color-in-c
*/

namespace CLIProteinViewer {
namespace color256 {

using color::Color;

struct Color256 {
  Color256() = default;

  Color256( int R, int G, int B ) :
    r( R ),
    g( G ),
    b( B )
  {}

  Color256( Color256 const & src ) = default;
  Color256( Color256 && src ) = default;

  int r;
  int g;
  int b;
  char color[12];

};


struct ColorMatcher {

  std::array< Color256, 256 > colors256;

  int determine_closest_code( int r, int g, int b, bool must_be_system = false ) const {
    int closest_code = 0;
    float closest_score = 999;

    for( unsigned i = 0; i < colors.size(); ++i ){
      Color const & c = colors[ i ];
      if( must_be_system && ! c.is_system() ) break;

      float const r_diff = c.r - r;
      float const g_diff = c.g - g;
      float const b_diff = c.b - b;
      float const diff_sq = (r_diff*r_diff) + (g_diff*g_diff) + (b_diff*b_diff);
      if( diff_sq < closest_score ){
	closest_score = diff_sq;
	closest_code = c.code;
      }
    }

    return closest_code;
  }

  ColorMatcher(){
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '0', 'm', 0 };
      colors256[ 0 ].chars = c;
      colors256[ 0 ].r = 0;
      colors256[ 0 ].g = 0;
      colors256[ 0 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1', 'm', 0 };
      colors256[ 1 ].chars = c;
      colors256[ 1 ].r = 128;
      colors256[ 1 ].g = 0;
      colors256[ 1 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2', 'm', 0 };
      colors256[ 2 ].chars = c;
      colors256[ 2 ].r = 0;
      colors256[ 2 ].g = 128;
      colors256[ 2 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3', 'm', 0 };
      colors256[ 3 ].chars = c;
      colors256[ 3 ].r = 128;
      colors256[ 3 ].g = 128;
      colors256[ 3 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4', 'm', 0 };
      colors256[ 4 ].chars = c;
      colors256[ 4 ].r = 0;
      colors256[ 4 ].g = 0;
      colors256[ 4 ].b = 128;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5', 'm', 0 };
      colors256[ 5 ].chars = c;
      colors256[ 5 ].r = 128;
      colors256[ 5 ].g = 0;
      colors256[ 5 ].b = 128;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6', 'm', 0 };
      colors256[ 6 ].chars = c;
      colors256[ 6 ].r = 0;
      colors256[ 6 ].g = 128;
      colors256[ 6 ].b = 128;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7', 'm', 0 };
      colors256[ 7 ].chars = c;
      colors256[ 7 ].r = 192;
      colors256[ 7 ].g = 192;
      colors256[ 7 ].b = 192;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8', 'm', 0 };
      colors256[ 8 ].chars = c;
      colors256[ 8 ].r = 128;
      colors256[ 8 ].g = 128;
      colors256[ 8 ].b = 128;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9', 'm', 0 };
      colors256[ 9 ].chars = c;
      colors256[ 9 ].r = 255;
      colors256[ 9 ].g = 0;
      colors256[ 9 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0', 'm', 0 };
      colors256[ 10 ].chars = c;
      colors256[ 10 ].r = 0;
      colors256[ 10 ].g = 255;
      colors256[ 10 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1', 'm', 0 };
      colors256[ 11 ].chars = c;
      colors256[ 11 ].r = 255;
      colors256[ 11 ].g = 255;
      colors256[ 11 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2', 'm', 0 };
      colors256[ 12 ].chars = c;
      colors256[ 12 ].r = 0;
      colors256[ 12 ].g = 0;
      colors256[ 12 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3', 'm', 0 };
      colors256[ 13 ].chars = c;
      colors256[ 13 ].r = 255;
      colors256[ 13 ].g = 0;
      colors256[ 13 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4', 'm', 0 };
      colors256[ 14 ].chars = c;
      colors256[ 14 ].r = 0;
      colors256[ 14 ].g = 255;
      colors256[ 14 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5', 'm', 0 };
      colors256[ 15 ].chars = c;
      colors256[ 15 ].r = 255;
      colors256[ 15 ].g = 255;
      colors256[ 15 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6', 'm', 0 };
      colors256[ 16 ].chars = c;
      colors256[ 16 ].r = 0;
      colors256[ 16 ].g = 0;
      colors256[ 16 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7', 'm', 0 };
      colors256[ 17 ].chars = c;
      colors256[ 17 ].r = 0;
      colors256[ 17 ].g = 0;
      colors256[ 17 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8', 'm', 0 };
      colors256[ 18 ].chars = c;
      colors256[ 18 ].r = 0;
      colors256[ 18 ].g = 0;
      colors256[ 18 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9', 'm', 0 };
      colors256[ 19 ].chars = c;
      colors256[ 19 ].r = 0;
      colors256[ 19 ].g = 0;
      colors256[ 19 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0', 'm', 0 };
      colors256[ 20 ].chars = c;
      colors256[ 20 ].r = 0;
      colors256[ 20 ].g = 0;
      colors256[ 20 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1', 'm', 0 };
      colors256[ 21 ].chars = c;
      colors256[ 21 ].r = 0;
      colors256[ 21 ].g = 0;
      colors256[ 21 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2', 'm', 0 };
      colors256[ 22 ].chars = c;
      colors256[ 22 ].r = 0;
      colors256[ 22 ].g = 95;
      colors256[ 22 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3', 'm', 0 };
      colors256[ 23 ].chars = c;
      colors256[ 23 ].r = 0;
      colors256[ 23 ].g = 95;
      colors256[ 23 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4', 'm', 0 };
      colors256[ 24 ].chars = c;
      colors256[ 24 ].r = 0;
      colors256[ 24 ].g = 95;
      colors256[ 24 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '5', 'm', 0 };
      colors256[ 25 ].chars = c;
      colors256[ 25 ].r = 0;
      colors256[ 25 ].g = 95;
      colors256[ 25 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '6', 'm', 0 };
      colors256[ 26 ].chars = c;
      colors256[ 26 ].r = 0;
      colors256[ 26 ].g = 95;
      colors256[ 26 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '7', 'm', 0 };
      colors256[ 27 ].chars = c;
      colors256[ 27 ].r = 0;
      colors256[ 27 ].g = 95;
      colors256[ 27 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '8', 'm', 0 };
      colors256[ 28 ].chars = c;
      colors256[ 28 ].r = 0;
      colors256[ 28 ].g = 135;
      colors256[ 28 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '9', 'm', 0 };
      colors256[ 29 ].chars = c;
      colors256[ 29 ].r = 0;
      colors256[ 29 ].g = 135;
      colors256[ 29 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '0', 'm', 0 };
      colors256[ 30 ].chars = c;
      colors256[ 30 ].r = 0;
      colors256[ 30 ].g = 135;
      colors256[ 30 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '1', 'm', 0 };
      colors256[ 31 ].chars = c;
      colors256[ 31 ].r = 0;
      colors256[ 31 ].g = 135;
      colors256[ 31 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '2', 'm', 0 };
      colors256[ 32 ].chars = c;
      colors256[ 32 ].r = 0;
      colors256[ 32 ].g = 135;
      colors256[ 32 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '3', 'm', 0 };
      colors256[ 33 ].chars = c;
      colors256[ 33 ].r = 0;
      colors256[ 33 ].g = 135;
      colors256[ 33 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '4', 'm', 0 };
      colors256[ 34 ].chars = c;
      colors256[ 34 ].r = 0;
      colors256[ 34 ].g = 175;
      colors256[ 34 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '5', 'm', 0 };
      colors256[ 35 ].chars = c;
      colors256[ 35 ].r = 0;
      colors256[ 35 ].g = 175;
      colors256[ 35 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '6', 'm', 0 };
      colors256[ 36 ].chars = c;
      colors256[ 36 ].r = 0;
      colors256[ 36 ].g = 175;
      colors256[ 36 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '7', 'm', 0 };
      colors256[ 37 ].chars = c;
      colors256[ 37 ].r = 0;
      colors256[ 37 ].g = 175;
      colors256[ 37 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '8', 'm', 0 };
      colors256[ 38 ].chars = c;
      colors256[ 38 ].r = 0;
      colors256[ 38 ].g = 175;
      colors256[ 38 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '3',
		   '9', 'm', 0 };
      colors256[ 39 ].chars = c;
      colors256[ 39 ].r = 0;
      colors256[ 39 ].g = 175;
      colors256[ 39 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '0', 'm', 0 };
      colors256[ 40 ].chars = c;
      colors256[ 40 ].r = 0;
      colors256[ 40 ].g = 215;
      colors256[ 40 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '1', 'm', 0 };
      colors256[ 41 ].chars = c;
      colors256[ 41 ].r = 0;
      colors256[ 41 ].g = 215;
      colors256[ 41 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '2', 'm', 0 };
      colors256[ 42 ].chars = c;
      colors256[ 42 ].r = 0;
      colors256[ 42 ].g = 215;
      colors256[ 42 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '3', 'm', 0 };
      colors256[ 43 ].chars = c;
      colors256[ 43 ].r = 0;
      colors256[ 43 ].g = 215;
      colors256[ 43 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '4', 'm', 0 };
      colors256[ 44 ].chars = c;
      colors256[ 44 ].r = 0;
      colors256[ 44 ].g = 215;
      colors256[ 44 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '5', 'm', 0 };
      colors256[ 45 ].chars = c;
      colors256[ 45 ].r = 0;
      colors256[ 45 ].g = 215;
      colors256[ 45 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '6', 'm', 0 };
      colors256[ 46 ].chars = c;
      colors256[ 46 ].r = 0;
      colors256[ 46 ].g = 255;
      colors256[ 46 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '7', 'm', 0 };
      colors256[ 47 ].chars = c;
      colors256[ 47 ].r = 0;
      colors256[ 47 ].g = 255;
      colors256[ 47 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '8', 'm', 0 };
      colors256[ 48 ].chars = c;
      colors256[ 48 ].r = 0;
      colors256[ 48 ].g = 255;
      colors256[ 48 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '4',
		   '9', 'm', 0 };
      colors256[ 49 ].chars = c;
      colors256[ 49 ].r = 0;
      colors256[ 49 ].g = 255;
      colors256[ 49 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '0', 'm', 0 };
      colors256[ 50 ].chars = c;
      colors256[ 50 ].r = 0;
      colors256[ 50 ].g = 255;
      colors256[ 50 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '1', 'm', 0 };
      colors256[ 51 ].chars = c;
      colors256[ 51 ].r = 0;
      colors256[ 51 ].g = 255;
      colors256[ 51 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '2', 'm', 0 };
      colors256[ 52 ].chars = c;
      colors256[ 52 ].r = 95;
      colors256[ 52 ].g = 0;
      colors256[ 52 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '3', 'm', 0 };
      colors256[ 53 ].chars = c;
      colors256[ 53 ].r = 95;
      colors256[ 53 ].g = 0;
      colors256[ 53 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '4', 'm', 0 };
      colors256[ 54 ].chars = c;
      colors256[ 54 ].r = 95;
      colors256[ 54 ].g = 0;
      colors256[ 54 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '5', 'm', 0 };
      colors256[ 55 ].chars = c;
      colors256[ 55 ].r = 95;
      colors256[ 55 ].g = 0;
      colors256[ 55 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '6', 'm', 0 };
      colors256[ 56 ].chars = c;
      colors256[ 56 ].r = 95;
      colors256[ 56 ].g = 0;
      colors256[ 56 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '7', 'm', 0 };
      colors256[ 57 ].chars = c;
      colors256[ 57 ].r = 95;
      colors256[ 57 ].g = 0;
      colors256[ 57 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '8', 'm', 0 };
      colors256[ 58 ].chars = c;
      colors256[ 58 ].r = 95;
      colors256[ 58 ].g = 95;
      colors256[ 58 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '5',
		   '9', 'm', 0 };
      colors256[ 59 ].chars = c;
      colors256[ 59 ].r = 95;
      colors256[ 59 ].g = 95;
      colors256[ 59 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '0', 'm', 0 };
      colors256[ 60 ].chars = c;
      colors256[ 60 ].r = 95;
      colors256[ 60 ].g = 95;
      colors256[ 60 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '1', 'm', 0 };
      colors256[ 61 ].chars = c;
      colors256[ 61 ].r = 95;
      colors256[ 61 ].g = 95;
      colors256[ 61 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '2', 'm', 0 };
      colors256[ 62 ].chars = c;
      colors256[ 62 ].r = 95;
      colors256[ 62 ].g = 95;
      colors256[ 62 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '3', 'm', 0 };
      colors256[ 63 ].chars = c;
      colors256[ 63 ].r = 95;
      colors256[ 63 ].g = 95;
      colors256[ 63 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '4', 'm', 0 };
      colors256[ 64 ].chars = c;
      colors256[ 64 ].r = 95;
      colors256[ 64 ].g = 135;
      colors256[ 64 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '5', 'm', 0 };
      colors256[ 65 ].chars = c;
      colors256[ 65 ].r = 95;
      colors256[ 65 ].g = 135;
      colors256[ 65 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '6', 'm', 0 };
      colors256[ 66 ].chars = c;
      colors256[ 66 ].r = 95;
      colors256[ 66 ].g = 135;
      colors256[ 66 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '7', 'm', 0 };
      colors256[ 67 ].chars = c;
      colors256[ 67 ].r = 95;
      colors256[ 67 ].g = 135;
      colors256[ 67 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '8', 'm', 0 };
      colors256[ 68 ].chars = c;
      colors256[ 68 ].r = 95;
      colors256[ 68 ].g = 135;
      colors256[ 68 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '6',
		   '9', 'm', 0 };
      colors256[ 69 ].chars = c;
      colors256[ 69 ].r = 95;
      colors256[ 69 ].g = 135;
      colors256[ 69 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '0', 'm', 0 };
      colors256[ 70 ].chars = c;
      colors256[ 70 ].r = 95;
      colors256[ 70 ].g = 175;
      colors256[ 70 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '1', 'm', 0 };
      colors256[ 71 ].chars = c;
      colors256[ 71 ].r = 95;
      colors256[ 71 ].g = 175;
      colors256[ 71 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '2', 'm', 0 };
      colors256[ 72 ].chars = c;
      colors256[ 72 ].r = 95;
      colors256[ 72 ].g = 175;
      colors256[ 72 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '3', 'm', 0 };
      colors256[ 73 ].chars = c;
      colors256[ 73 ].r = 95;
      colors256[ 73 ].g = 175;
      colors256[ 73 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '4', 'm', 0 };
      colors256[ 74 ].chars = c;
      colors256[ 74 ].r = 95;
      colors256[ 74 ].g = 175;
      colors256[ 74 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '5', 'm', 0 };
      colors256[ 75 ].chars = c;
      colors256[ 75 ].r = 95;
      colors256[ 75 ].g = 175;
      colors256[ 75 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '6', 'm', 0 };
      colors256[ 76 ].chars = c;
      colors256[ 76 ].r = 95;
      colors256[ 76 ].g = 215;
      colors256[ 76 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '7', 'm', 0 };
      colors256[ 77 ].chars = c;
      colors256[ 77 ].r = 95;
      colors256[ 77 ].g = 215;
      colors256[ 77 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '8', 'm', 0 };
      colors256[ 78 ].chars = c;
      colors256[ 78 ].r = 95;
      colors256[ 78 ].g = 215;
      colors256[ 78 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '7',
		   '9', 'm', 0 };
      colors256[ 79 ].chars = c;
      colors256[ 79 ].r = 95;
      colors256[ 79 ].g = 215;
      colors256[ 79 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '0', 'm', 0 };
      colors256[ 80 ].chars = c;
      colors256[ 80 ].r = 95;
      colors256[ 80 ].g = 215;
      colors256[ 80 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '1', 'm', 0 };
      colors256[ 81 ].chars = c;
      colors256[ 81 ].r = 95;
      colors256[ 81 ].g = 215;
      colors256[ 81 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '2', 'm', 0 };
      colors256[ 82 ].chars = c;
      colors256[ 82 ].r = 95;
      colors256[ 82 ].g = 255;
      colors256[ 82 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '3', 'm', 0 };
      colors256[ 83 ].chars = c;
      colors256[ 83 ].r = 95;
      colors256[ 83 ].g = 255;
      colors256[ 83 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '4', 'm', 0 };
      colors256[ 84 ].chars = c;
      colors256[ 84 ].r = 95;
      colors256[ 84 ].g = 255;
      colors256[ 84 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '5', 'm', 0 };
      colors256[ 85 ].chars = c;
      colors256[ 85 ].r = 95;
      colors256[ 85 ].g = 255;
      colors256[ 85 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '6', 'm', 0 };
      colors256[ 86 ].chars = c;
      colors256[ 86 ].r = 95;
      colors256[ 86 ].g = 255;
      colors256[ 86 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '7', 'm', 0 };
      colors256[ 87 ].chars = c;
      colors256[ 87 ].r = 95;
      colors256[ 87 ].g = 255;
      colors256[ 87 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '8', 'm', 0 };
      colors256[ 88 ].chars = c;
      colors256[ 88 ].r = 135;
      colors256[ 88 ].g = 0;
      colors256[ 88 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '8',
		   '9', 'm', 0 };
      colors256[ 89 ].chars = c;
      colors256[ 89 ].r = 135;
      colors256[ 89 ].g = 0;
      colors256[ 89 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '0', 'm', 0 };
      colors256[ 90 ].chars = c;
      colors256[ 90 ].r = 135;
      colors256[ 90 ].g = 0;
      colors256[ 90 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '1', 'm', 0 };
      colors256[ 91 ].chars = c;
      colors256[ 91 ].r = 135;
      colors256[ 91 ].g = 0;
      colors256[ 91 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '2', 'm', 0 };
      colors256[ 92 ].chars = c;
      colors256[ 92 ].r = 135;
      colors256[ 92 ].g = 0;
      colors256[ 92 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '3', 'm', 0 };
      colors256[ 93 ].chars = c;
      colors256[ 93 ].r = 135;
      colors256[ 93 ].g = 0;
      colors256[ 93 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '4', 'm', 0 };
      colors256[ 94 ].chars = c;
      colors256[ 94 ].r = 135;
      colors256[ 94 ].g = 95;
      colors256[ 94 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '5', 'm', 0 };
      colors256[ 95 ].chars = c;
      colors256[ 95 ].r = 135;
      colors256[ 95 ].g = 95;
      colors256[ 95 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '6', 'm', 0 };
      colors256[ 96 ].chars = c;
      colors256[ 96 ].r = 135;
      colors256[ 96 ].g = 95;
      colors256[ 96 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '7', 'm', 0 };
      colors256[ 97 ].chars = c;
      colors256[ 97 ].r = 135;
      colors256[ 97 ].g = 95;
      colors256[ 97 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '8', 'm', 0 };
      colors256[ 98 ].chars = c;
      colors256[ 98 ].r = 135;
      colors256[ 98 ].g = 95;
      colors256[ 98 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '9',
		   '9', 'm', 0 };
      colors256[ 99 ].chars = c;
      colors256[ 99 ].r = 135;
      colors256[ 99 ].g = 95;
      colors256[ 99 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '0', 'm', 0 };
      colors256[ 100 ].chars = c;
      colors256[ 100 ].r = 135;
      colors256[ 100 ].g = 135;
      colors256[ 100 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '1', 'm', 0 };
      colors256[ 101 ].chars = c;
      colors256[ 101 ].r = 135;
      colors256[ 101 ].g = 135;
      colors256[ 101 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '2', 'm', 0 };
      colors256[ 102 ].chars = c;
      colors256[ 102 ].r = 135;
      colors256[ 102 ].g = 135;
      colors256[ 102 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '3', 'm', 0 };
      colors256[ 103 ].chars = c;
      colors256[ 103 ].r = 135;
      colors256[ 103 ].g = 135;
      colors256[ 103 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '4', 'm', 0 };
      colors256[ 104 ].chars = c;
      colors256[ 104 ].r = 135;
      colors256[ 104 ].g = 135;
      colors256[ 104 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '5', 'm', 0 };
      colors256[ 105 ].chars = c;
      colors256[ 105 ].r = 135;
      colors256[ 105 ].g = 135;
      colors256[ 105 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '6', 'm', 0 };
      colors256[ 106 ].chars = c;
      colors256[ 106 ].r = 135;
      colors256[ 106 ].g = 175;
      colors256[ 106 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '7', 'm', 0 };
      colors256[ 107 ].chars = c;
      colors256[ 107 ].r = 135;
      colors256[ 107 ].g = 175;
      colors256[ 107 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '8', 'm', 0 };
      colors256[ 108 ].chars = c;
      colors256[ 108 ].r = 135;
      colors256[ 108 ].g = 175;
      colors256[ 108 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '0',
		   '9', 'm', 0 };
      colors256[ 109 ].chars = c;
      colors256[ 109 ].r = 135;
      colors256[ 109 ].g = 175;
      colors256[ 109 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '0', 'm', 0 };
      colors256[ 110 ].chars = c;
      colors256[ 110 ].r = 135;
      colors256[ 110 ].g = 175;
      colors256[ 110 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '1', 'm', 0 };
      colors256[ 111 ].chars = c;
      colors256[ 111 ].r = 135;
      colors256[ 111 ].g = 175;
      colors256[ 111 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '2', 'm', 0 };
      colors256[ 112 ].chars = c;
      colors256[ 112 ].r = 135;
      colors256[ 112 ].g = 215;
      colors256[ 112 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '3', 'm', 0 };
      colors256[ 113 ].chars = c;
      colors256[ 113 ].r = 135;
      colors256[ 113 ].g = 215;
      colors256[ 113 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '4', 'm', 0 };
      colors256[ 114 ].chars = c;
      colors256[ 114 ].r = 135;
      colors256[ 114 ].g = 215;
      colors256[ 114 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '5', 'm', 0 };
      colors256[ 115 ].chars = c;
      colors256[ 115 ].r = 135;
      colors256[ 115 ].g = 215;
      colors256[ 115 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '6', 'm', 0 };
      colors256[ 116 ].chars = c;
      colors256[ 116 ].r = 135;
      colors256[ 116 ].g = 215;
      colors256[ 116 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '7', 'm', 0 };
      colors256[ 117 ].chars = c;
      colors256[ 117 ].r = 135;
      colors256[ 117 ].g = 215;
      colors256[ 117 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '8', 'm', 0 };
      colors256[ 118 ].chars = c;
      colors256[ 118 ].r = 135;
      colors256[ 118 ].g = 255;
      colors256[ 118 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '1',
		   '9', 'm', 0 };
      colors256[ 119 ].chars = c;
      colors256[ 119 ].r = 135;
      colors256[ 119 ].g = 255;
      colors256[ 119 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '0', 'm', 0 };
      colors256[ 120 ].chars = c;
      colors256[ 120 ].r = 135;
      colors256[ 120 ].g = 255;
      colors256[ 120 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '1', 'm', 0 };
      colors256[ 121 ].chars = c;
      colors256[ 121 ].r = 135;
      colors256[ 121 ].g = 255;
      colors256[ 121 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '2', 'm', 0 };
      colors256[ 122 ].chars = c;
      colors256[ 122 ].r = 135;
      colors256[ 122 ].g = 255;
      colors256[ 122 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '3', 'm', 0 };
      colors256[ 123 ].chars = c;
      colors256[ 123 ].r = 135;
      colors256[ 123 ].g = 255;
      colors256[ 123 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '4', 'm', 0 };
      colors256[ 124 ].chars = c;
      colors256[ 124 ].r = 175;
      colors256[ 124 ].g = 0;
      colors256[ 124 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '5', 'm', 0 };
      colors256[ 125 ].chars = c;
      colors256[ 125 ].r = 175;
      colors256[ 125 ].g = 0;
      colors256[ 125 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '6', 'm', 0 };
      colors256[ 126 ].chars = c;
      colors256[ 126 ].r = 175;
      colors256[ 126 ].g = 0;
      colors256[ 126 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '7', 'm', 0 };
      colors256[ 127 ].chars = c;
      colors256[ 127 ].r = 175;
      colors256[ 127 ].g = 0;
      colors256[ 127 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '8', 'm', 0 };
      colors256[ 128 ].chars = c;
      colors256[ 128 ].r = 175;
      colors256[ 128 ].g = 0;
      colors256[ 128 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '2',
		   '9', 'm', 0 };
      colors256[ 129 ].chars = c;
      colors256[ 129 ].r = 175;
      colors256[ 129 ].g = 0;
      colors256[ 129 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '0', 'm', 0 };
      colors256[ 130 ].chars = c;
      colors256[ 130 ].r = 175;
      colors256[ 130 ].g = 95;
      colors256[ 130 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '1', 'm', 0 };
      colors256[ 131 ].chars = c;
      colors256[ 131 ].r = 175;
      colors256[ 131 ].g = 95;
      colors256[ 131 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '2', 'm', 0 };
      colors256[ 132 ].chars = c;
      colors256[ 132 ].r = 175;
      colors256[ 132 ].g = 95;
      colors256[ 132 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '3', 'm', 0 };
      colors256[ 133 ].chars = c;
      colors256[ 133 ].r = 175;
      colors256[ 133 ].g = 95;
      colors256[ 133 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '4', 'm', 0 };
      colors256[ 134 ].chars = c;
      colors256[ 134 ].r = 175;
      colors256[ 134 ].g = 95;
      colors256[ 134 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '5', 'm', 0 };
      colors256[ 135 ].chars = c;
      colors256[ 135 ].r = 175;
      colors256[ 135 ].g = 95;
      colors256[ 135 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '6', 'm', 0 };
      colors256[ 136 ].chars = c;
      colors256[ 136 ].r = 175;
      colors256[ 136 ].g = 135;
      colors256[ 136 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '7', 'm', 0 };
      colors256[ 137 ].chars = c;
      colors256[ 137 ].r = 175;
      colors256[ 137 ].g = 135;
      colors256[ 137 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '8', 'm', 0 };
      colors256[ 138 ].chars = c;
      colors256[ 138 ].r = 175;
      colors256[ 138 ].g = 135;
      colors256[ 138 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '3',
		   '9', 'm', 0 };
      colors256[ 139 ].chars = c;
      colors256[ 139 ].r = 175;
      colors256[ 139 ].g = 135;
      colors256[ 139 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '0', 'm', 0 };
      colors256[ 140 ].chars = c;
      colors256[ 140 ].r = 175;
      colors256[ 140 ].g = 135;
      colors256[ 140 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '1', 'm', 0 };
      colors256[ 141 ].chars = c;
      colors256[ 141 ].r = 175;
      colors256[ 141 ].g = 135;
      colors256[ 141 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '2', 'm', 0 };
      colors256[ 142 ].chars = c;
      colors256[ 142 ].r = 175;
      colors256[ 142 ].g = 175;
      colors256[ 142 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '3', 'm', 0 };
      colors256[ 143 ].chars = c;
      colors256[ 143 ].r = 175;
      colors256[ 143 ].g = 175;
      colors256[ 143 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '4', 'm', 0 };
      colors256[ 144 ].chars = c;
      colors256[ 144 ].r = 175;
      colors256[ 144 ].g = 175;
      colors256[ 144 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '5', 'm', 0 };
      colors256[ 145 ].chars = c;
      colors256[ 145 ].r = 175;
      colors256[ 145 ].g = 175;
      colors256[ 145 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '6', 'm', 0 };
      colors256[ 146 ].chars = c;
      colors256[ 146 ].r = 175;
      colors256[ 146 ].g = 175;
      colors256[ 146 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '7', 'm', 0 };
      colors256[ 147 ].chars = c;
      colors256[ 147 ].r = 175;
      colors256[ 147 ].g = 175;
      colors256[ 147 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '8', 'm', 0 };
      colors256[ 148 ].chars = c;
      colors256[ 148 ].r = 175;
      colors256[ 148 ].g = 215;
      colors256[ 148 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '4',
		   '9', 'm', 0 };
      colors256[ 149 ].chars = c;
      colors256[ 149 ].r = 175;
      colors256[ 149 ].g = 215;
      colors256[ 149 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '0', 'm', 0 };
      colors256[ 150 ].chars = c;
      colors256[ 150 ].r = 175;
      colors256[ 150 ].g = 215;
      colors256[ 150 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '1', 'm', 0 };
      colors256[ 151 ].chars = c;
      colors256[ 151 ].r = 175;
      colors256[ 151 ].g = 215;
      colors256[ 151 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '2', 'm', 0 };
      colors256[ 152 ].chars = c;
      colors256[ 152 ].r = 175;
      colors256[ 152 ].g = 215;
      colors256[ 152 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '3', 'm', 0 };
      colors256[ 153 ].chars = c;
      colors256[ 153 ].r = 175;
      colors256[ 153 ].g = 215;
      colors256[ 153 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '4', 'm', 0 };
      colors256[ 154 ].chars = c;
      colors256[ 154 ].r = 175;
      colors256[ 154 ].g = 255;
      colors256[ 154 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '5', 'm', 0 };
      colors256[ 155 ].chars = c;
      colors256[ 155 ].r = 175;
      colors256[ 155 ].g = 255;
      colors256[ 155 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '6', 'm', 0 };
      colors256[ 156 ].chars = c;
      colors256[ 156 ].r = 175;
      colors256[ 156 ].g = 255;
      colors256[ 156 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '7', 'm', 0 };
      colors256[ 157 ].chars = c;
      colors256[ 157 ].r = 175;
      colors256[ 157 ].g = 255;
      colors256[ 157 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '8', 'm', 0 };
      colors256[ 158 ].chars = c;
      colors256[ 158 ].r = 175;
      colors256[ 158 ].g = 255;
      colors256[ 158 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '5',
		   '9', 'm', 0 };
      colors256[ 159 ].chars = c;
      colors256[ 159 ].r = 175;
      colors256[ 159 ].g = 255;
      colors256[ 159 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '0', 'm', 0 };
      colors256[ 160 ].chars = c;
      colors256[ 160 ].r = 215;
      colors256[ 160 ].g = 0;
      colors256[ 160 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '1', 'm', 0 };
      colors256[ 161 ].chars = c;
      colors256[ 161 ].r = 215;
      colors256[ 161 ].g = 0;
      colors256[ 161 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '2', 'm', 0 };
      colors256[ 162 ].chars = c;
      colors256[ 162 ].r = 215;
      colors256[ 162 ].g = 0;
      colors256[ 162 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '3', 'm', 0 };
      colors256[ 163 ].chars = c;
      colors256[ 163 ].r = 215;
      colors256[ 163 ].g = 0;
      colors256[ 163 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '4', 'm', 0 };
      colors256[ 164 ].chars = c;
      colors256[ 164 ].r = 215;
      colors256[ 164 ].g = 0;
      colors256[ 164 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '5', 'm', 0 };
      colors256[ 165 ].chars = c;
      colors256[ 165 ].r = 215;
      colors256[ 165 ].g = 0;
      colors256[ 165 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '6', 'm', 0 };
      colors256[ 166 ].chars = c;
      colors256[ 166 ].r = 215;
      colors256[ 166 ].g = 95;
      colors256[ 166 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '7', 'm', 0 };
      colors256[ 167 ].chars = c;
      colors256[ 167 ].r = 215;
      colors256[ 167 ].g = 95;
      colors256[ 167 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '8', 'm', 0 };
      colors256[ 168 ].chars = c;
      colors256[ 168 ].r = 215;
      colors256[ 168 ].g = 95;
      colors256[ 168 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '6',
		   '9', 'm', 0 };
      colors256[ 169 ].chars = c;
      colors256[ 169 ].r = 215;
      colors256[ 169 ].g = 95;
      colors256[ 169 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '0', 'm', 0 };
      colors256[ 170 ].chars = c;
      colors256[ 170 ].r = 215;
      colors256[ 170 ].g = 95;
      colors256[ 170 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '1', 'm', 0 };
      colors256[ 171 ].chars = c;
      colors256[ 171 ].r = 215;
      colors256[ 171 ].g = 95;
      colors256[ 171 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '2', 'm', 0 };
      colors256[ 172 ].chars = c;
      colors256[ 172 ].r = 215;
      colors256[ 172 ].g = 135;
      colors256[ 172 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '3', 'm', 0 };
      colors256[ 173 ].chars = c;
      colors256[ 173 ].r = 215;
      colors256[ 173 ].g = 135;
      colors256[ 173 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '4', 'm', 0 };
      colors256[ 174 ].chars = c;
      colors256[ 174 ].r = 215;
      colors256[ 174 ].g = 135;
      colors256[ 174 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '5', 'm', 0 };
      colors256[ 175 ].chars = c;
      colors256[ 175 ].r = 215;
      colors256[ 175 ].g = 135;
      colors256[ 175 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '6', 'm', 0 };
      colors256[ 176 ].chars = c;
      colors256[ 176 ].r = 215;
      colors256[ 176 ].g = 135;
      colors256[ 176 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '7', 'm', 0 };
      colors256[ 177 ].chars = c;
      colors256[ 177 ].r = 215;
      colors256[ 177 ].g = 135;
      colors256[ 177 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '8', 'm', 0 };
      colors256[ 178 ].chars = c;
      colors256[ 178 ].r = 215;
      colors256[ 178 ].g = 175;
      colors256[ 178 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '7',
		   '9', 'm', 0 };
      colors256[ 179 ].chars = c;
      colors256[ 179 ].r = 215;
      colors256[ 179 ].g = 175;
      colors256[ 179 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '0', 'm', 0 };
      colors256[ 180 ].chars = c;
      colors256[ 180 ].r = 215;
      colors256[ 180 ].g = 175;
      colors256[ 180 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '1', 'm', 0 };
      colors256[ 181 ].chars = c;
      colors256[ 181 ].r = 215;
      colors256[ 181 ].g = 175;
      colors256[ 181 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '2', 'm', 0 };
      colors256[ 182 ].chars = c;
      colors256[ 182 ].r = 215;
      colors256[ 182 ].g = 175;
      colors256[ 182 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '3', 'm', 0 };
      colors256[ 183 ].chars = c;
      colors256[ 183 ].r = 215;
      colors256[ 183 ].g = 175;
      colors256[ 183 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '4', 'm', 0 };
      colors256[ 184 ].chars = c;
      colors256[ 184 ].r = 215;
      colors256[ 184 ].g = 215;
      colors256[ 184 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '5', 'm', 0 };
      colors256[ 185 ].chars = c;
      colors256[ 185 ].r = 215;
      colors256[ 185 ].g = 215;
      colors256[ 185 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '6', 'm', 0 };
      colors256[ 186 ].chars = c;
      colors256[ 186 ].r = 215;
      colors256[ 186 ].g = 215;
      colors256[ 186 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '7', 'm', 0 };
      colors256[ 187 ].chars = c;
      colors256[ 187 ].r = 215;
      colors256[ 187 ].g = 215;
      colors256[ 187 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '8', 'm', 0 };
      colors256[ 188 ].chars = c;
      colors256[ 188 ].r = 215;
      colors256[ 188 ].g = 215;
      colors256[ 188 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '8',
		   '9', 'm', 0 };
      colors256[ 189 ].chars = c;
      colors256[ 189 ].r = 215;
      colors256[ 189 ].g = 215;
      colors256[ 189 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '0', 'm', 0 };
      colors256[ 190 ].chars = c;
      colors256[ 190 ].r = 215;
      colors256[ 190 ].g = 255;
      colors256[ 190 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '1', 'm', 0 };
      colors256[ 191 ].chars = c;
      colors256[ 191 ].r = 215;
      colors256[ 191 ].g = 255;
      colors256[ 191 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '2', 'm', 0 };
      colors256[ 192 ].chars = c;
      colors256[ 192 ].r = 215;
      colors256[ 192 ].g = 255;
      colors256[ 192 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '3', 'm', 0 };
      colors256[ 193 ].chars = c;
      colors256[ 193 ].r = 215;
      colors256[ 193 ].g = 255;
      colors256[ 193 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '4', 'm', 0 };
      colors256[ 194 ].chars = c;
      colors256[ 194 ].r = 215;
      colors256[ 194 ].g = 255;
      colors256[ 194 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '5', 'm', 0 };
      colors256[ 195 ].chars = c;
      colors256[ 195 ].r = 215;
      colors256[ 195 ].g = 255;
      colors256[ 195 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '6', 'm', 0 };
      colors256[ 196 ].chars = c;
      colors256[ 196 ].r = 255;
      colors256[ 196 ].g = 0;
      colors256[ 196 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '7', 'm', 0 };
      colors256[ 197 ].chars = c;
      colors256[ 197 ].r = 255;
      colors256[ 197 ].g = 0;
      colors256[ 197 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '8', 'm', 0 };
      colors256[ 198 ].chars = c;
      colors256[ 198 ].r = 255;
      colors256[ 198 ].g = 0;
      colors256[ 198 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '1',
		   '9',
		   '9', 'm', 0 };
      colors256[ 199 ].chars = c;
      colors256[ 199 ].r = 255;
      colors256[ 199 ].g = 0;
      colors256[ 199 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '0', 'm', 0 };
      colors256[ 200 ].chars = c;
      colors256[ 200 ].r = 255;
      colors256[ 200 ].g = 0;
      colors256[ 200 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '1', 'm', 0 };
      colors256[ 201 ].chars = c;
      colors256[ 201 ].r = 255;
      colors256[ 201 ].g = 0;
      colors256[ 201 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '2', 'm', 0 };
      colors256[ 202 ].chars = c;
      colors256[ 202 ].r = 255;
      colors256[ 202 ].g = 95;
      colors256[ 202 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '3', 'm', 0 };
      colors256[ 203 ].chars = c;
      colors256[ 203 ].r = 255;
      colors256[ 203 ].g = 95;
      colors256[ 203 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '4', 'm', 0 };
      colors256[ 204 ].chars = c;
      colors256[ 204 ].r = 255;
      colors256[ 204 ].g = 95;
      colors256[ 204 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '5', 'm', 0 };
      colors256[ 205 ].chars = c;
      colors256[ 205 ].r = 255;
      colors256[ 205 ].g = 95;
      colors256[ 205 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '6', 'm', 0 };
      colors256[ 206 ].chars = c;
      colors256[ 206 ].r = 255;
      colors256[ 206 ].g = 95;
      colors256[ 206 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '7', 'm', 0 };
      colors256[ 207 ].chars = c;
      colors256[ 207 ].r = 255;
      colors256[ 207 ].g = 95;
      colors256[ 207 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '8', 'm', 0 };
      colors256[ 208 ].chars = c;
      colors256[ 208 ].r = 255;
      colors256[ 208 ].g = 135;
      colors256[ 208 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '0',
		   '9', 'm', 0 };
      colors256[ 209 ].chars = c;
      colors256[ 209 ].r = 255;
      colors256[ 209 ].g = 135;
      colors256[ 209 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '0', 'm', 0 };
      colors256[ 210 ].chars = c;
      colors256[ 210 ].r = 255;
      colors256[ 210 ].g = 135;
      colors256[ 210 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '1', 'm', 0 };
      colors256[ 211 ].chars = c;
      colors256[ 211 ].r = 255;
      colors256[ 211 ].g = 135;
      colors256[ 211 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '2', 'm', 0 };
      colors256[ 212 ].chars = c;
      colors256[ 212 ].r = 255;
      colors256[ 212 ].g = 135;
      colors256[ 212 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '3', 'm', 0 };
      colors256[ 213 ].chars = c;
      colors256[ 213 ].r = 255;
      colors256[ 213 ].g = 135;
      colors256[ 213 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '4', 'm', 0 };
      colors256[ 214 ].chars = c;
      colors256[ 214 ].r = 255;
      colors256[ 214 ].g = 175;
      colors256[ 214 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '5', 'm', 0 };
      colors256[ 215 ].chars = c;
      colors256[ 215 ].r = 255;
      colors256[ 215 ].g = 175;
      colors256[ 215 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '6', 'm', 0 };
      colors256[ 216 ].chars = c;
      colors256[ 216 ].r = 255;
      colors256[ 216 ].g = 175;
      colors256[ 216 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '7', 'm', 0 };
      colors256[ 217 ].chars = c;
      colors256[ 217 ].r = 255;
      colors256[ 217 ].g = 175;
      colors256[ 217 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '8', 'm', 0 };
      colors256[ 218 ].chars = c;
      colors256[ 218 ].r = 255;
      colors256[ 218 ].g = 175;
      colors256[ 218 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '1',
		   '9', 'm', 0 };
      colors256[ 219 ].chars = c;
      colors256[ 219 ].r = 255;
      colors256[ 219 ].g = 175;
      colors256[ 219 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '0', 'm', 0 };
      colors256[ 220 ].chars = c;
      colors256[ 220 ].r = 255;
      colors256[ 220 ].g = 215;
      colors256[ 220 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '1', 'm', 0 };
      colors256[ 221 ].chars = c;
      colors256[ 221 ].r = 255;
      colors256[ 221 ].g = 215;
      colors256[ 221 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '2', 'm', 0 };
      colors256[ 222 ].chars = c;
      colors256[ 222 ].r = 255;
      colors256[ 222 ].g = 215;
      colors256[ 222 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '3', 'm', 0 };
      colors256[ 223 ].chars = c;
      colors256[ 223 ].r = 255;
      colors256[ 223 ].g = 215;
      colors256[ 223 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '4', 'm', 0 };
      colors256[ 224 ].chars = c;
      colors256[ 224 ].r = 255;
      colors256[ 224 ].g = 215;
      colors256[ 224 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '5', 'm', 0 };
      colors256[ 225 ].chars = c;
      colors256[ 225 ].r = 255;
      colors256[ 225 ].g = 215;
      colors256[ 225 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '6', 'm', 0 };
      colors256[ 226 ].chars = c;
      colors256[ 226 ].r = 255;
      colors256[ 226 ].g = 255;
      colors256[ 226 ].b = 0;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '7', 'm', 0 };
      colors256[ 227 ].chars = c;
      colors256[ 227 ].r = 255;
      colors256[ 227 ].g = 255;
      colors256[ 227 ].b = 95;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '8', 'm', 0 };
      colors256[ 228 ].chars = c;
      colors256[ 228 ].r = 255;
      colors256[ 228 ].g = 255;
      colors256[ 228 ].b = 135;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '2',
		   '9', 'm', 0 };
      colors256[ 229 ].chars = c;
      colors256[ 229 ].r = 255;
      colors256[ 229 ].g = 255;
      colors256[ 229 ].b = 175;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '0', 'm', 0 };
      colors256[ 230 ].chars = c;
      colors256[ 230 ].r = 255;
      colors256[ 230 ].g = 255;
      colors256[ 230 ].b = 215;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '1', 'm', 0 };
      colors256[ 231 ].chars = c;
      colors256[ 231 ].r = 255;
      colors256[ 231 ].g = 255;
      colors256[ 231 ].b = 255;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '2', 'm', 0 };
      colors256[ 232 ].chars = c;
      colors256[ 232 ].r = 8;
      colors256[ 232 ].g = 8;
      colors256[ 232 ].b = 8;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '3', 'm', 0 };
      colors256[ 233 ].chars = c;
      colors256[ 233 ].r = 18;
      colors256[ 233 ].g = 18;
      colors256[ 233 ].b = 18;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '4', 'm', 0 };
      colors256[ 234 ].chars = c;
      colors256[ 234 ].r = 28;
      colors256[ 234 ].g = 28;
      colors256[ 234 ].b = 28;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '5', 'm', 0 };
      colors256[ 235 ].chars = c;
      colors256[ 235 ].r = 38;
      colors256[ 235 ].g = 38;
      colors256[ 235 ].b = 38;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '6', 'm', 0 };
      colors256[ 236 ].chars = c;
      colors256[ 236 ].r = 48;
      colors256[ 236 ].g = 48;
      colors256[ 236 ].b = 48;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '7', 'm', 0 };
      colors256[ 237 ].chars = c;
      colors256[ 237 ].r = 58;
      colors256[ 237 ].g = 58;
      colors256[ 237 ].b = 58;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '8', 'm', 0 };
      colors256[ 238 ].chars = c;
      colors256[ 238 ].r = 68;
      colors256[ 238 ].g = 68;
      colors256[ 238 ].b = 68;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '3',
		   '9', 'm', 0 };
      colors256[ 239 ].chars = c;
      colors256[ 239 ].r = 78;
      colors256[ 239 ].g = 78;
      colors256[ 239 ].b = 78;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '0', 'm', 0 };
      colors256[ 240 ].chars = c;
      colors256[ 240 ].r = 88;
      colors256[ 240 ].g = 88;
      colors256[ 240 ].b = 88;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '1', 'm', 0 };
      colors256[ 241 ].chars = c;
      colors256[ 241 ].r = 98;
      colors256[ 241 ].g = 98;
      colors256[ 241 ].b = 98;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '2', 'm', 0 };
      colors256[ 242 ].chars = c;
      colors256[ 242 ].r = 108;
      colors256[ 242 ].g = 108;
      colors256[ 242 ].b = 108;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '3', 'm', 0 };
      colors256[ 243 ].chars = c;
      colors256[ 243 ].r = 118;
      colors256[ 243 ].g = 118;
      colors256[ 243 ].b = 118;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '4', 'm', 0 };
      colors256[ 244 ].chars = c;
      colors256[ 244 ].r = 128;
      colors256[ 244 ].g = 128;
      colors256[ 244 ].b = 128;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '5', 'm', 0 };
      colors256[ 245 ].chars = c;
      colors256[ 245 ].r = 138;
      colors256[ 245 ].g = 138;
      colors256[ 245 ].b = 138;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '6', 'm', 0 };
      colors256[ 246 ].chars = c;
      colors256[ 246 ].r = 148;
      colors256[ 246 ].g = 148;
      colors256[ 246 ].b = 148;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '7', 'm', 0 };
      colors256[ 247 ].chars = c;
      colors256[ 247 ].r = 158;
      colors256[ 247 ].g = 158;
      colors256[ 247 ].b = 158;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '8', 'm', 0 };
      colors256[ 248 ].chars = c;
      colors256[ 248 ].r = 168;
      colors256[ 248 ].g = 168;
      colors256[ 248 ].b = 168;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '4',
		   '9', 'm', 0 };
      colors256[ 249 ].chars = c;
      colors256[ 249 ].r = 178;
      colors256[ 249 ].g = 178;
      colors256[ 249 ].b = 178;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '5',
		   '0', 'm', 0 };
      colors256[ 250 ].chars = c;
      colors256[ 250 ].r = 188;
      colors256[ 250 ].g = 188;
      colors256[ 250 ].b = 188;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '5',
		   '1', 'm', 0 };
      colors256[ 251 ].chars = c;
      colors256[ 251 ].r = 198;
      colors256[ 251 ].g = 198;
      colors256[ 251 ].b = 198;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '5',
		   '2', 'm', 0 };
      colors256[ 252 ].chars = c;
      colors256[ 252 ].r = 208;
      colors256[ 252 ].g = 208;
      colors256[ 252 ].b = 208;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '5',
		   '3', 'm', 0 };
      colors256[ 253 ].chars = c;
      colors256[ 253 ].r = 218;
      colors256[ 253 ].g = 218;
      colors256[ 253 ].b = 218;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '5',
		   '4', 'm', 0 };
      colors256[ 254 ].chars = c;
      colors256[ 254 ].r = 228;
      colors256[ 254 ].g = 228;
      colors256[ 254 ].b = 228;
    }
    {
      char c[] = { 0x1b, '[', '3', '8', ';', '5', ';', '2',
		   '5',
		   '5', 'm', 0 };
      colors256[ 255 ].chars = c;
      colors256[ 255 ].r = 238;
      colors256[ 255 ].g = 238;
      colors256[ 255 ].b = 238;
    }

  }

};

}//color256
}//CLIProteinViewer

/*backup
  rgb(0,0,0) 0
  rgb(128,0,0) 1
  rgb(0,128,0) 2
  rgb(128,128,0) 3
  rgb(0,0,128) 4
  rgb(128,0,128) 5
  rgb(0,128,128) 6
  rgb(192,192,192) 7
  rgb(128,128,128) 8
  rgb(255,0,0) 9
  rgb(0,255,0) 10
  rgb(255,255,0) 11
  rgb(0,0,255) 12
  rgb(255,0,255) 13
  rgb(0,255,255) 14
  rgb(255,255,255) 15
  rgb(0,0,0) 16
  rgb(0,0,95) 17
  rgb(0,0,135) 18
  rgb(0,0,175) 19
  rgb(0,0,215) 20
  rgb(0,0,255) 21
  rgb(0,95,0) 22
  rgb(0,95,95) 23
  rgb(0,95,135) 24
  rgb(0,95,175) 25
  rgb(0,95,215) 26
  rgb(0,95,255) 27
  rgb(0,135,0) 28
  rgb(0,135,95) 29
  rgb(0,135,135) 30
  rgb(0,135,175) 31
  rgb(0,135,215) 32
  rgb(0,135,255) 33
  rgb(0,175,0) 34
  rgb(0,175,95) 35
  rgb(0,175,135) 36
  rgb(0,175,175) 37
  rgb(0,175,215) 38
  rgb(0,175,255) 39
  rgb(0,215,0) 40
  rgb(0,215,95) 41
  rgb(0,215,135) 42
  rgb(0,215,175) 43
  rgb(0,215,215) 44
  rgb(0,215,255) 45
  rgb(0,255,0) 46
  rgb(0,255,95) 47
  rgb(0,255,135) 48
  rgb(0,255,175) 49
  rgb(0,255,215) 50
  rgb(0,255,255) 51
  rgb(95,0,0) 52
  rgb(95,0,95) 53
  rgb(95,0,135) 54
  rgb(95,0,175) 55
  rgb(95,0,215) 56
  rgb(95,0,255) 57
  rgb(95,95,0) 58
  rgb(95,95,95) 59
  rgb(95,95,135) 60
  rgb(95,95,175) 61
  rgb(95,95,215) 62
  rgb(95,95,255) 63
  rgb(95,135,0) 64
  rgb(95,135,95) 65
  rgb(95,135,135) 66
  rgb(95,135,175) 67
  rgb(95,135,215) 68
  rgb(95,135,255) 69
  rgb(95,175,0) 70
  rgb(95,175,95) 71
  rgb(95,175,135) 72
  rgb(95,175,175) 73
  rgb(95,175,215) 74
  rgb(95,175,255) 75
  rgb(95,215,0) 76
  rgb(95,215,95) 77
  rgb(95,215,135) 78
  rgb(95,215,175) 79
  rgb(95,215,215) 80
  rgb(95,215,255) 81
  rgb(95,255,0) 82
  rgb(95,255,95) 83
  rgb(95,255,135) 84
  rgb(95,255,175) 85
  rgb(95,255,215) 86
  rgb(95,255,255) 87
  rgb(135,0,0) 88
  rgb(135,0,95) 89
  rgb(135,0,135) 90
  rgb(135,0,175) 91
  rgb(135,0,215) 92
  rgb(135,0,255) 93
  rgb(135,95,0) 94
  rgb(135,95,95) 95
  rgb(135,95,135) 96
  rgb(135,95,175) 97
  rgb(135,95,215) 98
  rgb(135,95,255) 99
  rgb(135,135,0) 100
  rgb(135,135,95) 101
  rgb(135,135,135) 102
  rgb(135,135,175) 103
  rgb(135,135,215) 104
  rgb(135,135,255) 105
  rgb(135,175,0) 106
  rgb(135,175,95) 107
  rgb(135,175,135) 108
  rgb(135,175,175) 109
  rgb(135,175,215) 110
  rgb(135,175,255) 111
  rgb(135,215,0) 112
  rgb(135,215,95) 113
  rgb(135,215,135) 114
  rgb(135,215,175) 115
  rgb(135,215,215) 116
  rgb(135,215,255) 117
  rgb(135,255,0) 118
  rgb(135,255,95) 119
  rgb(135,255,135) 120
  rgb(135,255,175) 121
  rgb(135,255,215) 122
  rgb(135,255,255) 123
  rgb(175,0,0) 124
  rgb(175,0,95) 125
  rgb(175,0,135) 126
  rgb(175,0,175) 127
  rgb(175,0,215) 128
  rgb(175,0,255) 129
  rgb(175,95,0) 130
  rgb(175,95,95) 131
  rgb(175,95,135) 132
  rgb(175,95,175) 133
  rgb(175,95,215) 134
  rgb(175,95,255) 135
  rgb(175,135,0) 136
  rgb(175,135,95) 137
  rgb(175,135,135) 138
  rgb(175,135,175) 139
  rgb(175,135,215) 140
  rgb(175,135,255) 141
  rgb(175,175,0) 142
  rgb(175,175,95) 143
  rgb(175,175,135) 144
  rgb(175,175,175) 145
  rgb(175,175,215) 146
  rgb(175,175,255) 147
  rgb(175,215,0) 148
  rgb(175,215,95) 149
  rgb(175,215,135) 150
  rgb(175,215,175) 151
  rgb(175,215,215) 152
  rgb(175,215,255) 153
  rgb(175,255,0) 154
  rgb(175,255,95) 155
  rgb(175,255,135) 156
  rgb(175,255,175) 157
  rgb(175,255,215) 158
  rgb(175,255,255) 159
  rgb(215,0,0) 160
  rgb(215,0,95) 161
  rgb(215,0,135) 162
  rgb(215,0,175) 163
  rgb(215,0,215) 164
  rgb(215,0,255) 165
  rgb(215,95,0) 166
  rgb(215,95,95) 167
  rgb(215,95,135) 168
  rgb(215,95,175) 169
  rgb(215,95,215) 170
  rgb(215,95,255) 171
  rgb(215,135,0) 172
  rgb(215,135,95) 173
  rgb(215,135,135) 174
  rgb(215,135,175) 175
  rgb(215,135,215) 176
  rgb(215,135,255) 177
  rgb(215,175,0) 178
  rgb(215,175,95) 179
  rgb(215,175,135) 180
  rgb(215,175,175) 181
  rgb(215,175,215) 182
  rgb(215,175,255) 183
  rgb(215,215,0) 184
  rgb(215,215,95) 185
  rgb(215,215,135) 186
  rgb(215,215,175) 187
  rgb(215,215,215) 188
  rgb(215,215,255) 189
  rgb(215,255,0) 190
  rgb(215,255,95) 191
  rgb(215,255,135) 192
  rgb(215,255,175) 193
  rgb(215,255,215) 194
  rgb(215,255,255) 195
  rgb(255,0,0) 196
  rgb(255,0,95) 197
  rgb(255,0,135) 198
  rgb(255,0,175) 199
  rgb(255,0,215) 200
  rgb(255,0,255) 201
  rgb(255,95,0) 202
  rgb(255,95,95) 203
  rgb(255,95,135) 204
  rgb(255,95,175) 205
  rgb(255,95,215) 206
  rgb(255,95,255) 207
  rgb(255,135,0) 208
  rgb(255,135,95) 209
  rgb(255,135,135) 210
  rgb(255,135,175) 211
  rgb(255,135,215) 212
  rgb(255,135,255) 213
  rgb(255,175,0) 214
  rgb(255,175,95) 215
  rgb(255,175,135) 216
  rgb(255,175,175) 217
  rgb(255,175,215) 218
  rgb(255,175,255) 219
  rgb(255,215,0) 220
  rgb(255,215,95) 221
  rgb(255,215,135) 222
  rgb(255,215,175) 223
  rgb(255,215,215) 224
  rgb(255,215,255) 225
  rgb(255,255,0) 226
  rgb(255,255,95) 227
  rgb(255,255,135) 228
  rgb(255,255,175) 229
  rgb(255,255,215) 230
  rgb(255,255,255) 231
  rgb(8,8,8) 232
  rgb(18,18,18) 233
  rgb(28,28,28) 234
  rgb(38,38,38) 235
  rgb(48,48,48) 236
  rgb(58,58,58) 237
  rgb(68,68,68) 238
  rgb(78,78,78) 239
  rgb(88,88,88) 240
  rgb(98,98,98) 241
  rgb(108,108,108) 242
  rgb(118,118,118) 243
  rgb(128,128,128) 244
  rgb(138,138,138) 245
  rgb(148,148,148) 246
  rgb(158,158,158) 247
  rgb(168,168,168) 248
  rgb(178,178,178) 249
  rgb(188,188,188) 250
  rgb(198,198,198) 251
  rgb(208,208,208) 252
  rgb(218,218,218) 253
  rgb(228,228,228) 254
  rgb(238,238,238) 255
*/
