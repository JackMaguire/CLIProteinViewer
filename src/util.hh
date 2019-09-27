#pragma once

#include <visualize/visualize.hh>
#include <representations/spheres.hh>

#include <settings.hh>

namespace CLIProteinViewer {

bool is_background( visualize::Pixel const & p ){
  return p.r == 0 && p.g == 0 && p.b == 0;
};


void
fit_zoom( visualize::Screen & screen, spheres::Pose const & pose ){
  auto const && zoom_is_too_large = []( visualize::Screen const & s ) -> bool {
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
fit_h_to_v_ratio( visualize::Screen & screen, spheres::Pose const & pose ){

  auto const && number_of_filled_columns = []( visualize::Screen const & s ) -> unsigned {
    unsigned count = 0;
    for( int col = 0; col < s.ncol(); ++col ){
      bool has_any_filled = false;
      for( int row = 0; row < s.nrow(); ++row ){
	if( ! is_background( s.pixel_rowcol( row, col ) ) ){
	  has_any_filled = true;
	  break;
	}
      }
      if( has_any_filled ) ++count;
    }
    return count;
  };

  auto const && number_of_filled_rows = []( visualize::Screen const & s ) -> unsigned {
    unsigned count = 0;
    for( int row = 0; row < s.nrow(); ++row ){
      bool has_any_filled = false;
      for( int col = 0; col < s.ncol(); ++col ){
	if( ! is_background( s.pixel_rowcol( row, col ) ) ){
	  has_any_filled = true;
	  break;
	}
      }
      if( has_any_filled ) ++count;
    }
    return count;
  };


  auto const && ratio_is_too_large = [&]( visualize::Screen const & s ) -> bool {
    //as the ratio increase, the number of occupied rows becomes larger than the number of occupied columns
    return number_of_filled_rows( s ) > number_of_filled_columns( s );
  };

  render::draw_pose_on_screen( pose, screen );

  //Step 1: Make zoom too large
  while( ! ratio_is_too_large( screen ) ){
    //std::cout << "Zoom is not too large: " << settings::ZOOM << std::endl;
    settings::h_to_v_ratio *= 1.05;
    render::draw_pose_on_screen( pose, screen );
  }

  //Step 2: Make zoom not too large
  while( ratio_is_too_large( screen ) ){
    //std::cout << "Zoom is too large: " << settings::ZOOM << std::endl;
    settings::h_to_v_ratio *= 0.99;
    render::draw_pose_on_screen( pose, screen );
  }

  
}

void
fit_display_parameters(){
  visualize::Screen screen;
  std::cout << "Fitting parameters for screen size: " << screen.height() << " x " << screen.width() << std::endl;

  spheres::Pose pose;
  pose.chains[ "" ].heavy_atoms.emplace_back( 0.0, 0.0, 0.0, 'X', "N ", 1.0 );
  pose.normalize();//just to be safe
  render::draw_pose_on_screen( pose, screen );

  fit_zoom( screen, pose );
  //fit_h_to_v_ratio( screen, pose );
}

}//namespace CLIProteinViewer
