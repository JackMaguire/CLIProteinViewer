#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace CLIProteinViewer {
namespace settings {

//These can just be members of the Screen object, no?

static double ZOOM = 0.0032;

static double h_to_v_ratio = 0.55 / 1.2;

static double shadow_buffer = 0.1;

void save_to_file( std::string const & filename ){
  std::ofstream myfile;
  myfile.open( filename );
  myfile << "ZOOM " << ZOOM << std::endl;
  myfile << "h_to_v_ratio " << h_to_v_ratio << std::endl;
  myfile << "shadow_buffer " << shadow_buffer << std::endl;
  myfile.close();
}

void load_from_file( std::string const & filename ){
  std::ifstream myfile;
  myfile.open( filename );
  std::string line;
  while( std::getline( myfile, line ) ){
    std::istringstream iss( line );
    std::string a, b;
    if (!(iss >> a >> b)) { break; }
    std::cout << a << " AND " << b << std::endl;

    if( a == "ZOOM" ){ ZOOM = std::stod( b ); }
    else if( a == "h_to_v_ratio" ){ h_to_v_ratio = std::stod( b ); }
    else if( a == "shadow_buffer" ){ shadow_buffer = std::stod( b ); }
  }
  myfile.close();  
}

}
}
