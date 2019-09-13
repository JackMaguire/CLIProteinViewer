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
  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;

  Pose pose;
  pose.chains[ "A" ].heavy_atoms.emplace_back(  0.5, 0.0, 0.0, 'X', 1.0 );
  pose.chains[ "B" ].heavy_atoms.emplace_back( -0.5, 0.0, 0.0, 'X', 1.0 );

  render::draw_pose_on_screen( pose, screen );

  printf("\n");
  for( int h = 0; h < screen.height(); ++h ){
    for( int w = 0; w < screen.width(); ++w ){
      //std::cout << screen.pixel( h, w ).r << std::endl;
      print_nearest_color( screen.pixel( h, w ) );
    }
  }
}
