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

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

using namespace CLIProteinViewer;
using namespace CLIProteinViewer::visualize;
using namespace CLIProteinViewer::color;
using namespace CLIProteinViewer::spheres;
using namespace CLIProteinViewer::keylistener;

void
maybe_load_settings(){
  //determine filename
  const char *homedir;
  if ((homedir = getenv("HOME")) == NULL) {
    homedir = getpwuid(getuid())->pw_dir;
  }
  std::string filename( homedir );
  filename += "/.clipv.settings";

  //check if file exists
  std::ifstream f( filename.c_str() );
  if( f.good() ){
    settings::load_from_file( filename );
  }
}


int main(){

  //Determine save file
  const char *homedir;
  if ((homedir = getenv("HOME")) == NULL) {
    homedir = getpwuid(getuid())->pw_dir;
  }
  std::string new_filename( homedir );
  new_filename += "/.clipv.settings";
  std::cout << "Creating file: " << new_filename << std::endl;

  maybe_load_settings();

  CLIProteinViewer::fit_display_parameters();

  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;

  Pose pose;
  pose.chains[ "" ].heavy_atoms.emplace_back( 0.0, 0.0, 0.0, 'X', "N ", 1.0 );
  pose.normalize_pose( true, true );

  render::draw_pose_on_screen( pose, screen );

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

  bool time_to_break = false;

  while( ! time_to_break ) {
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

      case Key::LEFT:
	settings::h_to_v_ratio *= 1.1;
	repaint = true;
	break;
      case Key::RIGHT:
	settings::h_to_v_ratio /= 1.1;
	repaint = true;
	break;
      case Key::Q:
	time_to_break = true;
	repaint = false;
	settings::save_to_file( new_filename );
	settings::load_from_file( new_filename );
	break;
      default:
	break;
      }
    }
    else if( res < 0 ){
      perror( "select error" );
      break;
    }

    if( repaint ){
      render::draw_pose_on_screen( pose, screen );
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
