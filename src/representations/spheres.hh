#pragma once

#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <assert.h>
#include <stdlib.h> //abs
#include <math.h>
#include <array>

namespace CLIProteinViewer {
namespace spheres {

struct XYZ {
  constexpr XYZ() = default;
  constexpr XYZ( XYZ const & src ) = default;
  constexpr XYZ( XYZ & src ) = default;
  XYZ & operator=( XYZ const & src ) = default;

  constexpr XYZ( double X, double Y, double Z ) :
  x( X ),
    y( Y ),
    z( Z )
  {}

  double x = 0.0;
  double y = 0.0;
  double z = 0.0;

  void normalize() {
    double const l = sqrt( x*x + y*y + z*z );
    x /= l;
    y /= l;
    z /= l;
  }

  double & operator[]( size_t const i ){
    switch( i ){
    case 0: return x;
    case 1: return y;
    case 2: return z;
    default: assert( false );
    }
  }

};

struct Sphere : public XYZ {

  Sphere() = default;
  Sphere( Sphere const & src ) = default;
  Sphere( Sphere && src ) = default;

  Sphere & operator=( Sphere const & src ) = default;

  Sphere(
    double X,
    double Y,
    double Z,
    char A,
    std::array< char, 2 > A_name,
    double rad = 1.0
  ) :
  XYZ( X, Y, Z ),
    atom( A ),
    atom_name( A_name ),
    radius( rad )
  {}

  Sphere(
    double X,
    double Y,
    double Z,
    char A,
    std::string const & A_name, //must be size 2
    double rad = 1.0
  ) :
  XYZ( X, Y, Z ),
    atom( A ),
    atom_name({ A_name[ 0 ], A_name[ 1 ] }),
    radius( rad )
  {}

  char atom = 'X';
  std::array< char, 2 > atom_name = {{ ' ', ' ' }};
  double radius = 1.0;
  //bool is_hydrogen = false;

};

struct Chain {

  Chain() = default;
  Chain( Chain const & src ) = default;
  Chain( Chain && src ) = default;

  char chain = ' ';
  std::string chain_name = "foo";
  //int chain_id = -1;

  std::vector< Sphere > heavy_atoms;
  std::vector< Sphere > hydrogen_atoms;
};

struct Pose {

  Pose() = default;
  Pose( Pose const & src ) = default;
  Pose( Pose && src ) = default;

  Pose( std::string const & filename ){
    load_from_pdb_file( filename );
  }

  std::map< std::string, Chain > chains;

  void
  normalize_pose(
    bool const position = true,
    bool scale = true
  ) {
    double x_span = -1.0;
    double y_span = -1.0;
    double z_span = -1.0;

    XYZ const origin = calc_origin( x_span, y_span, z_span );
    double const max_scale = std::max( x_span, std::max( y_span, z_span ) );

    if( max_scale == 0.0 ){
      scale = false;
    }

    for( auto & pair : chains ){
      for( Sphere & s : pair.second.hydrogen_atoms ){
	if( position ){
	  s.x -= origin.x;
	  s.y -= origin.y;
	  s.z -= origin.z;
	}
	if( scale ){
	  s.x /= max_scale;
	  s.y /= max_scale;
	  s.z /= max_scale;
	}
      }
      for( Sphere & s : pair.second.heavy_atoms ){
	if( position ){
	  s.x -= origin.x;
	  s.y -= origin.y;
	  s.z -= origin.z;
	}
	if( scale ){
	  s.x /= max_scale;
	  s.y /= max_scale;
	  s.z /= max_scale;
	  s.radius /= max_scale;
	}
      }

      //asserts
      /*
	XYZ const new_origin = calc_origin( x_span, y_span, z_span );
	assert( abs( new_origin.x ) < 0.01 );
	assert( abs( new_origin.y ) < 0.01 );
	assert( abs( new_origin.z ) < 0.01 );
	assert( x_span < 1.01 );
	assert( y_span < 1.01 );
	assert( z_span < 1.01 );
      */
    }

  }

  void
  normalize(
    bool const position = true,
    bool const scale = true
  ) {
    normalize_pose( position, scale );
  }

  XYZ
  calc_origin() const {
    XYZ origin;
    double atom_count = 0;

    for( auto const & pair : chains ){
      //just do heavy atoms for now
      for( Sphere const & s : pair.second.heavy_atoms ){
	origin.x += s.x;
	origin.y += s.y;
	origin.z += s.z;
      }
      atom_count += pair.second.heavy_atoms.size();
    }

    origin.x /= atom_count;
    origin.y /= atom_count;
    origin.z /= atom_count;

    return origin;
  }

  XYZ
  calc_origin(
    double & x_span,
    double & y_span,
    double & z_span
  ) const {
    XYZ origin;
    double atom_count = 0;

    double max_x_value = -999999;
    double min_x_value = 999999;
    double max_y_value = -999999;
    double min_y_value = 999999;
    double max_z_value = -999999;
    double min_z_value = 999999;

    for( auto const & pair : chains ){
      //just do heavy atoms for now
      for( Sphere const & s : pair.second.heavy_atoms ){
	origin.x += s.x;
	origin.y += s.y;
	origin.z += s.z;

	if( s.x > max_x_value ) max_x_value = s.x;
	if( s.x < min_x_value ) min_x_value = s.x;
	if( s.y > max_y_value ) max_y_value = s.y;
	if( s.y < min_y_value ) min_y_value = s.y;
	if( s.z > max_z_value ) max_z_value = s.z;
	if( s.z < min_z_value ) min_z_value = s.z;
      }
      atom_count += pair.second.heavy_atoms.size();
    }

    origin.x /= atom_count;
    origin.y /= atom_count;
    origin.z /= atom_count;

    x_span = max_x_value - min_x_value;
    y_span = max_y_value - min_y_value;
    z_span = max_z_value - min_z_value;
    return origin;
  }

  //Note this does not reset the Pose.
  //Technically possible to load from multiple files
  void
  load_from_pdb_file( std::string const & filename ) {
    std::ifstream file( filename );
    std::string str;

    char previous_chain_name = '.';
    Chain * previous_chain = nullptr;

    while( std::getline( file, str ) ){
      if( str.substr(0,4) != "ATOM" ) continue;

      //ATOM      1  N   PRO A   6      24.084 -19.518  -6.502  1.00  0.00           N
      //01234567890123456789012345678901234567890123456789012345678901234567890123456789
      //....  ..... .... ... .    .   ........        ........      ......      ......
      //Chain = 21 (inclusive, 0-indexed)
      //X = 30-37 (inclusive, 0-indexed)
      //Y = 38-45 (inclusive, 0-indexed)
      //Z = 46-53 (inclusive, 0-indexed)
      //Element = 76-77 (inclusive, 0-indexed)

      char const chain = str.substr( 21, 1 )[0];
      double const x = std::stod( str.substr( 30, 8 ) );
      double const y = std::stod( str.substr( 38, 8 ) );
      double const z = std::stod( str.substr( 46, 8 ) );
      //std::string
      char const element = str.substr( 77, 1 )[0];//ignore 2-char elements?

      char const atom_name1 = str[ 13 ];
      char const atom_name2 = str[ 14 ];
      std::array< char, 2 > const atom_name{{ atom_name1, atom_name2 }};

      if( chain == previous_chain_name && previous_chain != nullptr ){
	//Nothing to do here?
	//maybe some asserts?
      } else {
	std::string const name_for_map = filename + "_" + chain;
	Chain * new_chain = &chains[ name_for_map ];
	new_chain->chain = chain;
	new_chain->chain_name = name_for_map;
	previous_chain_name = chain;
	previous_chain = new_chain;
      }

      if( element == 'H' ){
	previous_chain->hydrogen_atoms.emplace_back( x, y, z, element, atom_name );
      } else {
	previous_chain->heavy_atoms.emplace_back( x, y, z, element, atom_name );
      }

    }
  }
};

void
transform_pose(
  Pose & p,
  double x_rotation_radian,
  double y_rotation_radian,
  double z_rotation_radian
) {
  //TODO
  //https://math.stackexchange.com/questions/1741282/3d-calculate-new-location-of-point-after-rotation-around-origin
  //Try just basic rotations: https://en.wikipedia.org/wiki/Rotation_matrix#Basic_rotations
  auto && operate = [=]( Sphere & s ){
    //x rotation:
    Sphere s0 = s;
    s.y = s0.y * cos( x_rotation_radian ) - s0.z * sin( x_rotation_radian );
    s.z = s0.y * sin( x_rotation_radian ) + s0.z * cos( x_rotation_radian );

    //y rotation:
    s0 = s;
    s.z = s0.z * cos( y_rotation_radian ) - s0.x * sin( y_rotation_radian );
    s.x = s0.z * sin( y_rotation_radian ) + s0.x * cos( y_rotation_radian );

    //z rotation:
    s0 = s;
    s.x = s0.x * cos( z_rotation_radian ) - s0.y * sin( z_rotation_radian );
    s.y = s0.x * sin( z_rotation_radian ) + s0.y * cos( z_rotation_radian ); 

    //std::cout << s.x << "," << s.y << "," << s.z << std::endl;
  };

  for( auto & string_chain_pair : p.chains ){
    auto & chain = string_chain_pair.second;
    for( Sphere & s : chain.heavy_atoms ){
      operate( s );
    }
    for( Sphere & s : chain.hydrogen_atoms ){
      operate( s );
    }
  }

}


}
}
