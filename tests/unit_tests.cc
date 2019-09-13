#include <representations/spheres.hh>
#include <representations/sphere_math.hh>
#include <render/render.hh>
#include <assert.h>

#include <iostream>

#define LOGGER std::cout << __FUNCTION__ << " "

#define START LOGGER << std::endl
#define END   std::cout << std::endl

#define T_EQUALS( a, b ) assert_equals< decltype( a ) >( a, b, __LINE__ )
#define T_CLOSE( a, b ) assert_close< decltype( a ) >( a, b, __LINE__ )

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
  START;
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
  END;
}

void run_normalization_test2(){
  START;
  Pose p;
  p.chains[ "UNIT_TEST" ].heavy_atoms.emplace_back( 1.0, 2.0, 3.0, 'Y' );

  //Test origin
  XYZ const origin = p.calc_origin();
  assert_equals( origin.x, 1.0, __LINE__ );
  assert_equals( origin.y, 2.0, __LINE__ );
  assert_equals( origin.z, 3.0, __LINE__ );

  //Test origin after normalization
  p.normalize_pose();
  XYZ const origin2 = p.calc_origin();
  assert_equals( origin2.x, 0.0, __LINE__ );
  assert_equals( origin2.y, 0.0, __LINE__ );
  assert_equals( origin2.z, 0.0, __LINE__ );
  END;
}

void run_normalization_test3(){
  START;
  Pose p;
  p.chains[ "UNIT_TEST"  ].heavy_atoms.emplace_back( 1.0, 2.0, 3.0, 'Y' );
  p.chains[ "UNIT_TEST2" ].heavy_atoms.emplace_back( 3.0, 2.0, 3.0, 'Z' );

  //Test origin
  XYZ const origin = p.calc_origin();
  assert_equals( origin.x, 2.0, __LINE__ );
  assert_equals( origin.y, 2.0, __LINE__ );
  assert_equals( origin.z, 3.0, __LINE__ );

  //Test origin after normalization
  p.normalize_pose();
  XYZ const origin2 = p.calc_origin();
  assert_close( origin2.x, 0.0, __LINE__ );
  assert_close( origin2.y, 0.0, __LINE__ );
  assert_close( origin2.z, 0.0, __LINE__ );
  END;
}

void run_ray_cast_test1(){
  START;
  // double R = 1.0;
  std::array< double, 5 > Rs({ 1.0, 2.0, 3.0, 4.0, 5.0 });
  for( unsigned i = 0; i < Rs.size(); ++i ){
    //LOGGER << "i == " << i << std::endl;
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
  END;
}

void pdb_load_test1_inner_call1( Pose const & pose ){
  /*
    $ awk '{print $NF}' test.pdb | sort | uniq -c
    15 C
    29 H
    7 N
    6 O
    2 TER

    15 + 7 + 6 = 28
   */

  constexpr unsigned num_expected_heavy    = 28;
  constexpr unsigned num_expected_hydrogen = 29;

  /*
    $ grep ' A ' test.pdb | awk '{print $NF}' | sort | uniq -c
    11 C
    21 H
    5 N
    4 O

    11 + 5 + 4 = 20
  */

  constexpr unsigned num_expected_heavy_chain1    = 20;
  constexpr unsigned num_expected_hydrogen_chain1 = 21;

  /*
    $ grep ' B ' test.pdb | awk '{print $NF}' | sort | uniq -c
      4 C
      8 H
      2 N
      2 O

      4 + 2 + 2 = 8
  */

  constexpr unsigned num_expected_heavy_chain2    = 8;
  constexpr unsigned num_expected_hydrogen_chain2 = 8;

  static_assert( num_expected_heavy == num_expected_heavy_chain1 + num_expected_heavy_chain2, "Unit test was set up incorrectly" );
  static_assert( num_expected_hydrogen == num_expected_hydrogen_chain1 + num_expected_hydrogen_chain2, "Unit test was set up incorrectly" );

  T_EQUALS( pose.chains.size(), 2 );

  for( auto const & string_chain_pair : pose.chains ){
    Chain const & chain = string_chain_pair.second;
    if( chain.chain == 'A' ){
      T_EQUALS( chain.heavy_atoms.size(), num_expected_heavy_chain1 );
      T_EQUALS( chain.hydrogen_atoms.size(), num_expected_hydrogen_chain1 );
    } else if ( chain.chain == 'B' ){
      T_EQUALS( chain.heavy_atoms.size(), num_expected_heavy_chain2 );
      T_EQUALS( chain.hydrogen_atoms.size(), num_expected_hydrogen_chain2 );
    } else {
      std::cerr << "Unknown chain " << chain.chain << " found!" << std::endl;
      assert( false );
    }
  }
}

void run_pdb_load_test1(){
  START;
  //Hard-coded to assume this is run from the main directory
  Pose pose( "tests/test.pdb" );
  pdb_load_test1_inner_call1( pose );

  //Make sure that the pose behaves correctly after being loaded:
  END;
}

int main(){
  run_normalization_test1();
  run_normalization_test2();
  run_normalization_test3();

  run_ray_cast_test1();

  run_pdb_load_test1();

  std::cout << "All unit tests pass!" << std::endl;
}
