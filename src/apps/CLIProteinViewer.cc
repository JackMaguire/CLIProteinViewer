#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>
#include <vector>

#include <visualize/visualize.hh>
#include <visualize/colors.hh>
#include <representations/spheres.hh>
#include <render/render.hh>
#include <keylistener/keylistener.hh>
#include <util.hh>

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

  std::vector< std::string > args( argv, argv + argc );

  if( args.size() != 2 ){
    std::cerr << "Please pass exactly one pdb file" << std::endl;
    return -1;
  }

  CLIProteinViewer::fit_display_parameters();

  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;

  Pose pose( args[1] );
  pose.normalize_pose( true, true );

  render::draw_pose_on_screen( pose, screen );

  double x_rotation = 0.0;
  double y_rotation = 0.0;
  double z_rotation = 0.0;

  double d_rot = M_PI / 4.0;
  render::DisplayMode display_mode = render::DisplayMode::BB;

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

	//Rotate:
      case Key::UP:
	z_rotation += d_rot;
	repaint = true;
	break;
      case Key::DOWN:
	z_rotation -= d_rot;
	repaint = true;
	break;
      case Key::LEFT:
	y_rotation += d_rot;
	repaint = true;
	break;
      case Key::RIGHT:
	y_rotation -= d_rot;
	repaint = true;
	break;
      case Key::A:
	x_rotation += d_rot;
	repaint = true;
	break;
      case Key::D:
	x_rotation -= d_rot;
	repaint = true;
	break;

	// Zooming:
      case Key::S:
	settings::ZOOM *= 1.05;
	repaint = true;
	break;
      case Key::W:
	settings::ZOOM *= 0.95;
	repaint = true;
	break;

	//Step Size:
      case Key::ONE:
	d_rot = M_PI / 16.0;
	repaint = false;
	break;
      case Key::TWO:
	d_rot = M_PI / 8.0;
	repaint = false;
	break;
      case Key::THREE:
	d_rot = M_PI / 4.0;
	repaint = false;
	break;
      case Key::FOUR:
	d_rot = M_PI / 2.0;
	repaint = false;
	break;

	//View Mode:
      case Key::ZERO:
	if( display_mode != render::DisplayMode::ALLATOM ){
	  display_mode = render::DisplayMode::ALLATOM;
	  repaint = true;
	}
	break;
      case Key::NINE:
	if( display_mode != render::DisplayMode::HEAVY ){
	  display_mode = render::DisplayMode::HEAVY;
	  repaint = true;
	}
	break;
      case Key::EIGHT:
	if( display_mode != render::DisplayMode::BB_HEAVY ){
	  display_mode = render::DisplayMode::BB_HEAVY;
	  repaint = true;
	}
	break;
      case Key::SEVEN:
	if( display_mode != render::DisplayMode::BB_N ){
	  display_mode = render::DisplayMode::BB_N;
	  repaint = true;
	}
	break;

      }
    }
    else if( res < 0 ){
      perror( "select error" );
      break;
    }

    if( repaint ){
      Pose p( pose );
      transform_pose( p, x_rotation, y_rotation, z_rotation );
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
