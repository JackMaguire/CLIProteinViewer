#include <iostream>

#include <visualize/visualize.hh>
#include <visualize/colors.hh>
#include <keylistener/keylistener.hh>

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

using namespace CLIProteinViewer;
using namespace CLIProteinViewer::visualize;
using namespace CLIProteinViewer::color;
using namespace CLIProteinViewer::keylistener;

template< typename T >
void op_on_all_pixels(
  Screen & screen,
  T && op
) {
  for( int h = 0; h < screen.height(); ++h ){
    for( int w = 0; w < screen.width(); ++w ){
      op( screen.pixel( h, w ) );
    }
  }
}


int main(){
  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;
  screen.set_to_splash_screen();
  printf("\n");
  for( int h = 0; h < screen.height(); ++h ){
    for( int w = 0; w < screen.width(); ++w ){
      //std::cout << screen.pixel( h, w ).r << std::endl;
      print_nearest_color( screen.pixel( h, w ) );
    }
  }

  struct termios oldSettings, newSettings;

  tcgetattr( fileno( stdin ), &oldSettings );
  newSettings = oldSettings;
  newSettings.c_lflag &= (~ICANON & ~ECHO);
  tcsetattr( fileno( stdin ), TCSANOW, &newSettings );    

  while( true ) {
    fd_set set;
    struct timeval tv;

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    FD_ZERO( &set );
    FD_SET( fileno( stdin ), &set );

    int res = select( fileno( stdin )+1, &set, NULL, NULL, &tv );

    if( res > 0 ){
      char c;
      read( fileno( stdin ), &c, 1 );
      int const command = int( c );
      switch( parse_int( command ) ){
      case Key::UP:
	std::cout << '\r';
	//increase reds by 5;
	op_on_all_pixels( screen,
	  [](Pixel & p){
	    p.r += 5;
	    if( p.r > 255 ) p.r = 255;
	    print_nearest_color( p );
	  }
	);
	break;
      case Key::DOWN:
	std::cout << '\r';
	//std::cout << std::endl;
	//decrease reds by 5;
	op_on_all_pixels( screen,
	  [](Pixel & p){
	    p.r -= 5;
	    if( p.r < 0 ) p.r = 0;
	    print_nearest_color( p );
	  }
	);
	break;
      case Key::LEFT:
	std::cout << '\r';
	//std::cout << std::endl;
	//increase greens by 5;
	op_on_all_pixels( screen,
	  [](Pixel & p){
	    p.g += 5;
	    if( p.g > 255 ) p.g = 255;
	    print_nearest_color( p );
	  }
	);
	break;
      case Key::RIGHT:
	std::cout << '\r';
	//std::cout << std::endl;
	//decrease greens by 5;
	op_on_all_pixels( screen,
	  [](Pixel & p){
	    p.g -= 5;
	    if( p.g < 0 ) p.g = 0;
	    print_nearest_color( p );
	  }
	);
	break;
      }
    }
    else if( res < 0 ){
      perror( "select error" );
      break;
    }

  }

  tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
  return 0;

}
