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

#include <string>
#include <fstream>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#ifdef COLOR256
#include <visualize/color256.hh>
#endif

//This will get removed sooner or later
//Please remove it if the year is 2020 or later and it is still commented out
//#define KEEP_MASTER_POSE

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
  } else {
    std::cout << "It is recommended to run set_CLIPV_params beforehand to make sure you do not get a warpped image. See https://github.com/JackMaguire/CLIProteinViewer for more information." << std::endl;
  }
}

int main( int argc, char **argv ){

  std::vector< std::string > args( argv, argv + argc );

  for( std::string const & arg : args ){
    if( arg == "-h" || arg == "--help" ){
      std::cout << "Usage: CLIProteinViewer [name of one or more pdb files]" << std::endl;
      std::cout << "Please go to https://jackmaguire.github.io/CLIProteinViewer/ for more instructions" << std::endl;
      return 0;
    }
  }

  if( args.size() < 2 ){
    std::cerr << "Please pass at least one pdb file" << std::endl;
    return -1;
  }

  maybe_load_settings();

  CLIProteinViewer::fit_display_parameters();

  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;

  Pose pose( args[1] );
  for( unsigned ii = 2; ii < args.size(); ++ii ){
    pose.load_from_pdb_file( args[ ii ] );
  }
  pose.normalize_pose( true, true );

#ifdef KEEP_MASTER_POSE
  double x_rotation = 0.0;
  double y_rotation = 0.0;
  double z_rotation = 0.0;
#endif

#ifdef COLOR256
  color256::Color256Matcher matcher;
#endif

  double d_rot = M_PI / 4.0;
  render::DisplayMode display_mode = render::DisplayMode::BB_HEAVY;

  double zoomin_factor = 0.97;
  double zoomout_factor = 1.05;

  render::draw_pose_on_screen( pose, screen, display_mode );

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

#ifdef KEEP_MASTER_POSE
	//Rotate:
      case Key::A:
	z_rotation += d_rot;
	repaint = true;
	break;
      case Key::D:
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
      case Key::UP:
	x_rotation += d_rot;
	repaint = true;
	break;
      case Key::DOWN:
	x_rotation -= d_rot;
	repaint = true;
	break;
      case Key::R:
	x_rotation = 0;
	y_rotation = 0;
	z_rotation = 0;
	repaint = true;
	break;
#else
	//Rotate:
      case Key::UP:
	transform_pose( pose, 0.0, 0.0, d_rot );
	repaint = true;
	break;
      case Key::DOWN:
	transform_pose( pose, 0.0, 0.0, -1.0 * d_rot );
	repaint = true;
	break;
      case Key::LEFT:
	transform_pose( pose, 0.0, d_rot, 0.0 );
	repaint = true;
	break;
      case Key::RIGHT:
	transform_pose( pose, 0.0, -1.0 * d_rot, 0.0 );
	repaint = true;
	break;
      case Key::A:
	transform_pose( pose, d_rot, 0.0, 0.0 );
	repaint = true;
	break;
      case Key::D:
	transform_pose( pose, -1.0 * d_rot, 0.0, 0.0 );
	repaint = true;
	break;
#endif

	// Zooming:
      case Key::S:
	settings::ZOOM *= zoomout_factor;
	repaint = true;
	break;
      case Key::W:
	settings::ZOOM *= zoomin_factor;
	repaint = true;
	break;

	// Shadow:
      case Key::Q:
	settings::shadow_buffer += 0.1;
	repaint = true;
	break;
      case Key::E:
	settings::shadow_buffer -= 0.1;
	repaint = true;
	break;

	//Step Size:
      case Key::ONE:
	d_rot = M_PI / 16.0;
	zoomin_factor = 0.97;
	zoomout_factor = 1.05;
	repaint = false;
	break;
      case Key::TWO:
	d_rot = M_PI / 8.0;
	zoomin_factor = 0.93;
	zoomout_factor = 1.10;
	repaint = false;
	break;
      case Key::THREE:
	d_rot = M_PI / 4.0;
	zoomin_factor = 0.8;
	zoomout_factor = 1.5;
	repaint = false;
	break;
      case Key::FOUR:
	d_rot = M_PI / 2.0;
	zoomin_factor = 0.5;
	zoomout_factor = 2.0;
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
      default:
	break;
      }
    }
    else if( res < 0 ){
      perror( "select error" );
      break;
    }

    if( repaint ){
#ifdef KEEP_MASTER_POSE
      Pose p( pose );
      transform_pose( p, x_rotation, y_rotation, z_rotation );
#else
      Pose const & p = pose;
#endif
      render::draw_pose_on_screen( p, screen, display_mode );
      for( int h = 0; h < screen.height(); ++h ){
	for( int w = 0; w < screen.width(); ++w ){
	  //std::cout << screen.pixel( h, w ).r << std::endl;
#ifdef COLOR256
	  auto const & pixel = screen.pixel( h, w );
	  auto const & color = matcher.determine_closest_color( pixel.r, pixel.g, pixel.b );
	  std::cout << color.cmd << "X";
	  char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
	  std::cout << normal;
#else	  
	  print_nearest_color( screen.pixel( h, w ) );
	  char normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };
	  std::cout << normal;
#endif
	}
      }      
    }

  }

  tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );

}
