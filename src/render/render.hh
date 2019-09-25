#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include <visualize/visualize.hh>
#include <visualize/colors.hh>
#include <representations/spheres.hh>
#include <representations/sphere_math.hh>

#include <settings.hh>

#include <iostream>

namespace CLIProteinViewer {
namespace render {

constexpr double CAMERA_Z = -10.0;
constexpr double ABS_CAMERA_Z = 10.0;

constexpr spheres::XYZ camera_position({ 0.0, 0.0, CAMERA_Z });

void
determine_color(
  int const chain_id,
  double const t0,
  visualize::Pixel & pixel
) {
  pixel.r = 0;
  pixel.g = 0;
  pixel.b = 0;

  switch( chain_id ){
  case( -1 ): break;
  case( 0 ): pixel.g = 255; break; //green
  case( 1 ): pixel.g = 255; pixel.b = 255; break; //cyan
  case( 2 ): pixel.r = 255; pixel.b = 255; break; //magenta
  case( 3 ): pixel.r = 255; pixel.g = 255; break; //yellow
  case( 4 ): pixel.b = 255; break;
  default:   pixel.r = 255; break;
  }

  //TODO multiply by t0 - ABS_CAMERA_Z?
}

bool ray_intersect(
  spheres::XYZ const & dir,
  spheres::Sphere const & sphere,
  double & t0
) {
  spheres::XYZ const L = sphere - camera_position;
  double const tca = L * dir;
  double d2 = L*L - tca*tca;
  double const r2 = sphere.radius * sphere.radius;
  if( d2 > r2 ) return false;
  double const thc = sqrtf( r2 - d2);
  t0       = tca - thc;
  double const t1 = tca + thc;
  if (t0 < 0) t0 = t1;
  if (t0 < 0) return false;
  return true;
}

void
cast_ray(
  spheres::XYZ const & ray_direction,
  spheres::Pose const & pose,
  //visualize::Screen & screen,
  visualize::Pixel & pixel,
  bool skip_hydrogens = true
) {
  //std::cout << ray_direction.x << " " << ray_direction.y << " " << ray_direction.z << std::endl;

  //Sphere * closest_atom = nullptr;
  int chain_id_for_closest_atom = -1;
  double closest_distance = 99999;

  int chain_id = 0;
  double t0 = 0;
  for( auto const & pair : pose.chains ){
    for( spheres::Sphere const & s : pair.second.heavy_atoms ){
      if( ray_intersect( ray_direction, s, t0 ) ){
	if( t0 < closest_distance || chain_id_for_closest_atom == -1 ){
	  //closest_atom = &s;
	  chain_id_for_closest_atom = chain_id;
	  closest_distance = t0;
	}
      }
    }
    if( ! skip_hydrogens ){
      for( spheres::Sphere const & s : pair.second.hydrogen_atoms ){
	if( ray_intersect( ray_direction, s, t0 ) ){
	  if( t0 < closest_distance || chain_id_for_closest_atom == -1 ){
	    //closest_atom = &s;
	    chain_id_for_closest_atom = chain_id;
	    closest_distance = t0;
	  }
	}
      }
    }
    ++chain_id;
  }

  //spheres::XYZ hit_position = camera_position + ( ray_direction * t0 );
  //std::cout << "Hit a guy at " << hit_position.x << "," << hit_position.y << "," << hit_position.z << std::endl;

  //std::cout << "HIT " << chain_id << std::endl;
  if( chain_id_for_closest_atom == -1 ){
    //no hit
    pixel.r = 0;
    pixel.g = 0;
    pixel.b = 0;
  } else {
    determine_color( chain_id_for_closest_atom, t0, pixel );
  }
}

void
draw_pose_on_screen(
  spheres::Pose const & pose,
  visualize::Screen & screen,
  bool skip_hydrogens = true
) {
  //spheres::XYZ const camera_position = { 0.0, 0.0, CAMERA_Z };

  size_t const width = screen.width();
  size_t const height = screen.height();

  //https://github.com/ssloy/tinyraytracer/blob/master/tinyraytracer.cpp
  /*
    constexpr double fov = M_PI / 1000;
    for( size_t w = 0; w < width; w++ ){
    for( size_t h = 0; h < height; h++ ){
    double const dir_x =  (w + 0.5) -  width/2.;
    double const dir_y = -(h + 0.5) + height/2.;    // this flips the image at the same time
    double const dir_z = -height/(2.*tan(fov/2.));
    spheres::XYZ ray = { dir_x, dir_y, dir_z };
    ray.normalize();

    cast_ray( ray, pose, screen.pixel( h, w ), skip_hydrogens );
    }
    }
  */

  for( size_t w = 0; w < width; w++ ){
    for( size_t h = 0; h < height; h++ ){
      double const dw = (-1.0 * width/2.) + w;
      double const dir_x = dw * settings::ZOOM * settings::h_to_v_ratio;

      double const dh = (-1.0 * height/2.) + h;
      double const dir_y = dh * settings::ZOOM;

      double const dir_z = 1.0;

      spheres::XYZ ray({ dir_x, dir_y, dir_z });
      ray.normalize();

      cast_ray( ray, pose, screen.pixel( h, w ), skip_hydrogens );
    }
  }

}

}//namespace render
}//namespace CLIProteinViewer
