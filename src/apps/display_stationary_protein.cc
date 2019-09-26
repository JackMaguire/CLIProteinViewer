#include <iostream>

#include <visualize/visualize.hh>
#include <visualize/colors.hh>
#include <representations/spheres.hh>
#include <render/render.hh>

#include <vector>

using namespace CLIProteinViewer;
using namespace CLIProteinViewer::visualize;
using namespace CLIProteinViewer::color;
using namespace CLIProteinViewer::spheres;

int main( int argc, char **argv ){
  std::vector< std::string > args( argv, argv + argc );

  if( args.size() != 2 ){
    std::cerr << "Please pass exactly one pdb file" << std::endl;
    return -1;
  }

  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;

  Pose pose( args[1] );
  pose.normalize_pose( true, false );

  render::draw_pose_on_screen( pose, screen );

  printf("\n");
  for( int h = 0; h < screen.height(); ++h ){
    for( int w = 0; w < screen.width(); ++w ){
      //std::cout << screen.pixel( h, w ).r << std::endl;
      print_nearest_color( screen.pixel( h, w ) );
    }
  }
}
