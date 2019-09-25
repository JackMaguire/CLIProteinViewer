#include <iostream>
#include <vector>

#include <visualize/visualize.hh>
#include <visualize/colors.hh>
#include <representations/spheres.hh>
#include <render/render.hh>
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
using namespace CLIProteinViewer::spheres;
using namespace CLIProteinViewer::keylistener;

int main( int argc, char **argv ){
  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;

  Pose pose;
  pose.chains[ "A" ].heavy_atoms.emplace_back(  0.5, 0.0, 0.0, 'X', 1.0 );
  pose.chains[ "B" ].heavy_atoms.emplace_back( -0.5, 0.0, 0.0, 'X', 1.0 );
  pose.normalize_pose( true, true );

  render::draw_pose_on_screen( pose, screen );

  double x_rotation = 0.0;
  double y_rotation = 0.0;
  double z_rotation = 0.0;

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

    int const res = select( fileno( stdin )+1, &set, NULL, NULL, &tv );

    bool repaint = false;

    if( res > 0 ){
      char c;
      read( fileno( stdin ), &c, 1 );
      int const command = int( c );
      switch( parse_int( command ) ){
      case Key::UP:
	z_rotation += 0.1;
	repaint = true;
	break;
      case Key::DOWN:
	z_rotation -= 0.1;
	repaint = true;
	break;
      case Key::LEFT:
	x_rotation += 0.1;
	repaint = true;
	break;
      case Key::RIGHT:
	x_rotation -= 0.1;
	repaint = true;
	break;

	// ZOOMING:
      case Key::W:
	settings::zoom *= 1.05;
	repaint = true;
	break;
      case Key::S:
	settings::zoom *= 0.95;
	repaint = true;
	break;
      }
    }
    else if( res < 0 ){
      perror( "select error" );
      break;
    }

    if( repaint ){
      Pose p = pose.create_transformed_pose( x_rotation, y_rotation, z_rotation );
      render::draw_pose_on_screen( p, screen );
      for( int h = 0; h < screen.height(); ++h ){
	for( int w = 0; w < screen.width(); ++w ){
	  //std::cout << screen.pixel( h, w ).r << std::endl;
	  print_nearest_color( screen.pixel( h, w ) );
	}
      }      
    }

  }

  tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );

}
