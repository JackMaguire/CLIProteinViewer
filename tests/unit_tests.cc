#include <representations/spheres.hh>
#include <representations/sphere_math.hh>
#include <assert.h>

using namespace CLIProteinViewer;
using namespace CLIProteinViewer::spheres;

template< typename T >
void assert_close( T const t1, T const t2 ){
  assert( abs( t1 - t2 ) > 0.001 );
}

void run_normalization_test1(){
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

void run_normalization_test2(){
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

void run_normalization_test3(){
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

void run_ray_cast_test1(){
  constexpr Sphere s( 0.0, 0.0, 0.0, 'Y' );
  //Pose p;
  //p.chains[ "UNIT_TEST" ].heavy_atoms.emplace_back( 0.0, 0.0, 0.0, 'Y' );

  constexpr double dir_x =  0.0;
  constexpr double dir_y =  0.0;
  constexpr double dir_z =  1.0;
  constexpr spheres::XYZ ray = { dir_x, dir_y, dir_z };
  
  double t0 = -100;
  bool const intersect = render::ray_intersect( ray, s, t0 );

  assert( intersect );
  assert_close( t0, TODO );
}

int main(){
  run_normalization_test1();
  run_normalization_test2();
  run_normalization_test3();

  run_ray_cast_test1();
}
