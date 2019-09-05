#include <vector.hh>

//From https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
#include <sys/ioctl.h> // For ioctl, TIOCGWINSZ
#include <unistd.h> // For STDOUT_FILENO

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
};

struct Screen {
  Screen(){
    struct winsize size;
    ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
    auto const nrows = size.ws_row;
    auto const ncols = size.ws_col;
    pixels.resize( nrows );
    for( std::vector< Pixel > & v : pixels ){
      pixels.resize( );
    }
  }

  std::vector< std::vector< Pixel > > pixels; //outer vec is width, inner is height
};

void
