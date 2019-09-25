#include <iostream>

#include <visualize/visualize.hh>
#include <visualize/colors.hh>
#include <representations/spheres.hh>
#include <render/render.hh>

#include <util.hh>

#include <vector>

using namespace CLIProteinViewer;
using namespace CLIProteinViewer::visualize;
using namespace CLIProteinViewer::color;
using namespace CLIProteinViewer::spheres;

int main( int argc, char **argv ){

  CLIProteinViewer::fit_display_parameters();

  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;

  Pose pose;
  pose.chains[ "" ].heavy_atoms.emplace_back( 0.0, 0.0, 0.0, 'X', 1.0 );

  render::draw_pose_on_screen( pose, screen );

  printf("\n");
  for( int h = 0; h < screen.height(); ++h ){
    for( int w = 0; w < screen.width(); ++w ){
      //std::cout << screen.pixel( h, w ).r << std::endl;
      print_nearest_color( screen.pixel( h, w ) );
    }
  }
}
