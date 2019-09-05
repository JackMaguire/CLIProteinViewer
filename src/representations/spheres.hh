#pragma once

#include <vector>

namespace CLIProteinViewer {
namespace spheres {

struct Sphere {

  float x = 0.0;
  float y = 0.0;
  float z = 0.0;

  char atom = 'X';
  bool is_hydrogen = false;

};

struct Chain {
  char chain = ' ';
  int chain_id = -1;

  std::vector< Sphere > heavy_atoms;
  std::vector< Sphere > hydrogens_atoms;
};

struct Pose {
  std::vector< Chain > chains;

  
};

}
}
