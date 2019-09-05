#pragma once

#include <vector>
#include <map>
#include <string>
#include <fstream>

namespace CLIProteinViewer {
namespace spheres {

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
  char chain = ' ';
  std::string chain_name = "foo";
  //int chain_id = -1;

  std::vector< Sphere > heavy_atoms;
  std::vector< Sphere > hydrogens_atoms;
};

struct Pose {
  std::map< std::string, Chain > chains;

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
