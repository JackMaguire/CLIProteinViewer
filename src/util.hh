#pragma once

#include <visualize/visualize.hh>
#include <representations/spheres.hh>

#include <settings.hh>

namespace CLIProteinViewer {

void
fit_zoom( visualize::Screen & screen, spheres::Pose const & pose ){
  auto const && is_background = []( visualize::Pixel const & p ) -> bool {
    return p.r == 0 && p.g == 0 && p.b == 0;
  };

  auto const && zoom_is_too_large = [&is_background]( visualize::Screen const & s ) -> bool {
    //as zoom increase, the observed scene shrinks
    //Zoom is too large if the top row is emtpy
    for( visualize::Pixel const & p : s.pixels[ 0 ] ){
      if( ! is_background( p ) ) return false;
    }
    return true;
  };

  //Step 1: Make zoom too large
  while( ! zoom_is_too_large( screen ) ){
    //std::cout << "Zoom is not too large: " << settings::ZOOM << std::endl;
    settings::ZOOM *= 1.05;
    render::draw_pose_on_screen( pose, screen );
  }

  //Step 2: Make zoom not too large
  while( zoom_is_too_large( screen ) ){
    //std::cout << "Zoom is too large: " << settings::ZOOM << std::endl;
    settings::ZOOM *= 0.99;
    render::draw_pose_on_screen( pose, screen );
  }

}

void
fit_display_parameters(){
  visualize::Screen screen;
  std::cout << "Fitting parameters for screen size: " << screen.height() << " x " << screen.width() << std::endl;

  spheres::Pose pose;
  pose.chains[ "" ].heavy_atoms.emplace_back( 0.0, 0.0, 0.0, 'X', 1.0 );
  pose.normalize();//just to be safe
  render::draw_pose_on_screen( pose, screen );

  fit_zoom( screen, pose );
}

}//namespace CLIProteinViewer
