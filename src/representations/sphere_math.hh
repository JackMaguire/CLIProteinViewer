#pragma once

#include <representations/spheres.hh>

//Ugly as hell
//Copied from https://github.com/ssloy/tinyraytracer/blob/master/geometry.h
namespace CLIProteinViewer {
namespace spheres {

double operator*( XYZ const & lhs, XYZ const & rhs) {
  double ret = 0.0;
  ret += lhs.x * rhs.x;
  ret += lhs.y * rhs.y;
  ret += lhs.z * rhs.z;
  return ret;
}

//This isn't normal to change the operand, right?
//It's pass-by-value but still makes me uncomfortable
XYZ operator+( XYZ lhs, XYZ const & rhs) {
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  lhs.z += rhs.z;
  return lhs;
}

XYZ operator-( XYZ lhs, XYZ const & rhs) {
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
  lhs.z -= rhs.z;
  return lhs;
}


XYZ operator*( XYZ const & lhs, double const rhs) {
  XYZ ret( 0, 0, 0 );
  ret.x = lhs.x * rhs;
  ret.y = lhs.y * rhs;
  ret.z = lhs.z * rhs;
  return ret;
}

XYZ operator-( XYZ const & lhs ){
  return lhs*( -1.0 );
}

/*XYZ cross(vec<3,T> v1, vec<3,T> v2) {
  return vec<3,T>(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}*/

}
}//namespaces
