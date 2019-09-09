#include <representations/spheres.hh>
#include <representations/sphere_math.hh>
#include <assert.h>

using namespace CLIProteinViewer;
using namespace CLIProteinViewer::spheres;

void run_test1(){
  Pose p;
  p.chains[ "UNIT_TEST" ].heavy_atoms.emplace_back( 0.0, 0.0, 0.0, 'Y' );

  //Test origin
  XYZ const origin = p.calc_origin();
  assert( origin.x == 0.0 );
  assert( origin.y == 0.0 );
  assert( origin.z == 0.0 );

}

int main(){
  run_test1();
}
