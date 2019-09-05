#pragma once

#include <vector>
#include <map>
#include <string>
#include <fstream>

namespace CLIProteinViewer {
namespace spheres {

struct XYZ {
  double x = 0.0;
  double y = 0.0;
  double z = 0.0;
};

struct Sphere {

  Sphere() = default;
  Sphere( Sphere const & src ) = default;
  Sphere( Sphere && src ) = default;

  Sphere( double X, double Y, double Z, char A ) :
    x( X ),
    y( Y ),
    z( Z ),
    atom( A )
  {}

  

  double x = 0.0;
  double y = 0.0;
  double z = 0.0;

  char atom = 'X';
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
  std::vector< Sphere > hydrogens_atoms;
};

struct Pose {

  Pose() = default;
  Pose( Pose const & src ) = default;
  Pose( Pose && src ) = default;

  std::map< std::string, Chain > chains;

  Pose
  create_transformed_pose(
    double theta_radians,
    double phi_radians,
    double psi_radians
  ) {
    //TODO
    //https://math.stackexchange.com/questions/1741282/3d-calculate-new-location-of-point-after-rotation-around-origin
    //Try just basic rotations: https://en.wikipedia.org/wiki/Rotation_matrix#Basic_rotations
    Pose p;
    return p;
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

      char const chain = str.substr( 21, 1 );
      double const x = std::stod( str.substr( 30, 8 ) );
      double const y = std::stod( str.substr( 38, 8 ) );
      double const z = std::stod( str.substr( 46, 8 ) );
      //std::string
      char const element = str.substr( 77, 1 );//ignore 2-char elements?

      if( chain == previous_chain_name && previous_chain != nullptr ){
	//Nothing to do here?
	//maybe some asserts?
      } else {
	std::string const name_for_map = filename + "_" + chain;
	Chain * new_chain = &chains[ name_for_map ];
	new_chain->chain = chain;
	new_chain->chain_name = name_for_map;
	previous_chain_name = chain;
	previous_chain = new_chain
      }

      if( element == 'H' ){
	previous_chain->hydrogens_atoms.emplace_back( x, y, z, element );
      } else {
	previous_chain->heavy_atoms.emplace_back( x, y, z, element );
      }

    }
  }
};

}
}
