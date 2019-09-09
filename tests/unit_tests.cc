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

  //Test origin after normalization
  p.normalize_pose();
  XYZ const origin2 = p.calc_origin();
  assert( origin2.x == 0.0 );
  assert( origin2.y == 0.0 );
  assert( origin2.z == 0.0 );
}

void run_test2(){
  Pose p;
  p.chains[ "UNIT_TEST" ].heavy_atoms.emplace_back( 1.0, 2.0, 3.0, 'Y' );

  //Test origin
  XYZ const origin = p.calc_origin();
  assert( origin.x == 1.0 );
  assert( origin.y == 2.0 );
  assert( origin.z == 3.0 );

  //Test origin after normalization
  p.normalize_pose();
  XYZ const origin2 = p.calc_origin();
  assert( origin2.x == 0.0 );
  assert( origin2.y == 0.0 );
  assert( origin2.z == 0.0 );
}

void run_test3(){
  Pose p;
  p.chains[ "UNIT_TEST"  ].heavy_atoms.emplace_back( 1.0, 2.0, 3.0, 'Y' );
  p.chains[ "UNIT_TEST2" ].heavy_atoms.emplace_back( 3.0, 2.0, 3.0, 'Z' );

  //Test origin
  XYZ const origin = p.calc_origin();
  assert( origin.x == 2.0 );
  assert( origin.y == 2.0 );
  assert( origin.z == 3.0 );

  //Test origin after normalization
  p.normalize_pose();
  XYZ const origin2 = p.calc_origin();
  assert( origin2.x == 0.0 );
  assert( origin2.y == 0.0 );
  assert( origin2.z == 0.0 );
}

int main(){
  run_test1();
  run_test2();
  run_test3();
}
