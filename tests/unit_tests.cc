#include <representations/spheres.hh>
#include <representations/sphere_math.hh>
#include <render/render.hh>
#include <assert.h>

#include <iostream>

using namespace CLIProteinViewer;
using namespace CLIProteinViewer::spheres;

//yeah yeah yeah I know this can be done with a macro
template< typename T >
void assert_equals( T const t1, T const t2, int const line_num ){
  if( t1 != t2 ){
    std::cerr << t1 << " != " << t2 << " on line " << line_num << std::endl;
    assert( false );
  }
}

template< typename T >
void assert_close( T const t1, T const t2, int const line_num ){
  if( abs( t1 - t2 ) > 0.001 ){
    std::cerr << t1 << " != " << t2 << " on line " << line_num << std::endl;
    assert( false );
  }
}

void run_normalization_test1(){
  Pose p;
  p.chains[ "UNIT_TEST" ].heavy_atoms.emplace_back( 0.0, 0.0, 0.0, 'Y' );

  //Test origin
  XYZ const origin = p.calc_origin();
  assert_equals( origin.x, 0.0, __LINE__ );
  assert_equals( origin.y, 0.0, __LINE__ );
  assert_equals( origin.z, 0.0, __LINE__ );

  //Test origin after normalization
  p.normalize_pose();
  XYZ const origin2 = p.calc_origin();
  assert_equals( origin2.x, 0.0, __LINE__ );
  assert_equals( origin2.y, 0.0, __LINE__ );
  assert_equals( origin2.z, 0.0, __LINE__ );
}

void run_normalization_test2(){
  Pose p;
  p.chains[ "UNIT_TEST" ].heavy_atoms.emplace_back( 1.0, 2.0, 3.0, 'Y' );

  //Test origin
  XYZ const origin = p.calc_origin();
  assert_equals( origin.x, 0.0, __LINE__ );
  assert_equals( origin.y, 0.0, __LINE__ );
  assert_equals( origin.z, 0.0, __LINE__ );

  //Test origin after normalization
  p.normalize_pose();
  XYZ const origin2 = p.calc_origin();
  assert_equals( origin2.x, 0.0, __LINE__ );
  assert_equals( origin2.y, 0.0, __LINE__ );
  assert_equals( origin2.z, 0.0, __LINE__ );
}

void run_normalization_test3(){
  Pose p;
  p.chains[ "UNIT_TEST"  ].heavy_atoms.emplace_back( 1.0, 2.0, 3.0, 'Y' );
  p.chains[ "UNIT_TEST2" ].heavy_atoms.emplace_back( 3.0, 2.0, 3.0, 'Z' );

  //Test origin
  XYZ const origin = p.calc_origin();
  assert_equals( origin.x, 0.0, __LINE__ );
  assert_equals( origin.y, 0.0, __LINE__ );
  assert_equals( origin.z, 0.0, __LINE__ );

  //Test origin after normalization
  p.normalize_pose();
  XYZ const origin2 = p.calc_origin();
  assert_equals( origin2.x, 0.0, __LINE__ );
  assert_equals( origin2.y, 0.0, __LINE__ );
  assert_equals( origin2.z, 0.0, __LINE__ );

}

void run_ray_cast_test1(){
  // double R = 1.0;
  std::array< double, 5 > Rs({ 1.0, 2.0, 3.0, 4.0, 5.0 });
  for(  unsigned i = 0; i < Rs.size(); ++i ){
    double R = Rs[ i ];
    Sphere s( 0.0, 0.0, 0.0, 'Y', R );

    double dir_x =  0.0;
    double dir_y =  0.0;
    double dir_z =  1.0;
    spheres::XYZ ray = { dir_x, dir_y, dir_z };
  
    double t0 = -100;
    bool const intersect = render::ray_intersect( ray, s, t0 );

    assert( intersect );
  
    double const expected_distance = CLIProteinViewer::render::ABS_CAMERA_Z - s.radius;
    assert_close( t0, expected_distance, __LINE__ );
  }
}


int main(){
  run_normalization_test1();
  run_normalization_test2();
  run_normalization_test3();

  run_ray_cast_test1();
}
