#pragma once
#include <array>

/*
  Useful links:
  https://jonasjacek.github.io/colors/
  
*/

namespace CLIProteinViewer {
namespace color256 {

struct ColorMatcher {

  std::array< Color, 256 > colors;

  int determine_closest_code( int r, int g, int b, bool must_be_system = false ) const {
    int closest_code = 0;
    float closest_score = 999;

    for( unsigned i = 0; i < colors.size(); ++i ){
      Color const & c = colors[ i ];
      if( must_be_system && ! c.is_system() ) break;

      float const r_diff = c.r - r;
      float const g_diff = c.g - g;
      float const b_diff = c.b - b;
      float const diff_sq = (r_diff*r_diff) + (g_diff*g_diff) + (b_diff*b_diff);
      if( diff_sq < closest_score ){
	closest_score = diff_sq;
	closest_code = c.code;
      }
    }

    return closest_code;
  }

  ColorMatcher(){
    { Color c(0,0,0,0); colors[ c.code ] = c; }
    { Color c(128,0,0,1); colors[ c.code ] = c; }
    { Color c(0,128,0,2); colors[ c.code ] = c; }
    { Color c(128,128,0,3); colors[ c.code ] = c; }
    { Color c(0,0,128,4); colors[ c.code ] = c; }
    { Color c(128,0,128,5); colors[ c.code ] = c; }
    { Color c(0,128,128,6); colors[ c.code ] = c; }
    { Color c(192,192,192,7); colors[ c.code ] = c; }
    { Color c(128,128,128,8); colors[ c.code ] = c; }
    { Color c(255,0,0,9); colors[ c.code ] = c; }
    { Color c(0,255,0,10); colors[ c.code ] = c; }
    { Color c(255,255,0,11); colors[ c.code ] = c; }
    { Color c(0,0,255,12); colors[ c.code ] = c; }
    { Color c(255,0,255,13); colors[ c.code ] = c; }
    { Color c(0,255,255,14); colors[ c.code ] = c; }
    { Color c(255,255,255,15); colors[ c.code ] = c; }
    { Color c(0,0,0,16); colors[ c.code ] = c; }
    { Color c(0,0,95,17); colors[ c.code ] = c; }
    { Color c(0,0,135,18); colors[ c.code ] = c; }
    { Color c(0,0,175,19); colors[ c.code ] = c; }
    { Color c(0,0,215,20); colors[ c.code ] = c; }
    { Color c(0,0,255,21); colors[ c.code ] = c; }
    { Color c(0,95,0,22); colors[ c.code ] = c; }
    { Color c(0,95,95,23); colors[ c.code ] = c; }
    { Color c(0,95,135,24); colors[ c.code ] = c; }
    { Color c(0,95,175,25); colors[ c.code ] = c; }
    { Color c(0,95,215,26); colors[ c.code ] = c; }
    { Color c(0,95,255,27); colors[ c.code ] = c; }
    { Color c(0,135,0,28); colors[ c.code ] = c; }
    { Color c(0,135,95,29); colors[ c.code ] = c; }
    { Color c(0,135,135,30); colors[ c.code ] = c; }
    { Color c(0,135,175,31); colors[ c.code ] = c; }
    { Color c(0,135,215,32); colors[ c.code ] = c; }
    { Color c(0,135,255,33); colors[ c.code ] = c; }
    { Color c(0,175,0,34); colors[ c.code ] = c; }
    { Color c(0,175,95,35); colors[ c.code ] = c; }
    { Color c(0,175,135,36); colors[ c.code ] = c; }
    { Color c(0,175,175,37); colors[ c.code ] = c; }
    { Color c(0,175,215,38); colors[ c.code ] = c; }
    { Color c(0,175,255,39); colors[ c.code ] = c; }
    { Color c(0,215,0,40); colors[ c.code ] = c; }
    { Color c(0,215,95,41); colors[ c.code ] = c; }
    { Color c(0,215,135,42); colors[ c.code ] = c; }
    { Color c(0,215,175,43); colors[ c.code ] = c; }
    { Color c(0,215,215,44); colors[ c.code ] = c; }
    { Color c(0,215,255,45); colors[ c.code ] = c; }
    { Color c(0,255,0,46); colors[ c.code ] = c; }
    { Color c(0,255,95,47); colors[ c.code ] = c; }
    { Color c(0,255,135,48); colors[ c.code ] = c; }
    { Color c(0,255,175,49); colors[ c.code ] = c; }
    { Color c(0,255,215,50); colors[ c.code ] = c; }
    { Color c(0,255,255,51); colors[ c.code ] = c; }
    { Color c(95,0,0,52); colors[ c.code ] = c; }
    { Color c(95,0,95,53); colors[ c.code ] = c; }
    { Color c(95,0,135,54); colors[ c.code ] = c; }
    { Color c(95,0,175,55); colors[ c.code ] = c; }
    { Color c(95,0,215,56); colors[ c.code ] = c; }
    { Color c(95,0,255,57); colors[ c.code ] = c; }
    { Color c(95,95,0,58); colors[ c.code ] = c; }
    { Color c(95,95,95,59); colors[ c.code ] = c; }
    { Color c(95,95,135,60); colors[ c.code ] = c; }
    { Color c(95,95,175,61); colors[ c.code ] = c; }
    { Color c(95,95,215,62); colors[ c.code ] = c; }
    { Color c(95,95,255,63); colors[ c.code ] = c; }
    { Color c(95,135,0,64); colors[ c.code ] = c; }
    { Color c(95,135,95,65); colors[ c.code ] = c; }
    { Color c(95,135,135,66); colors[ c.code ] = c; }
    { Color c(95,135,175,67); colors[ c.code ] = c; }
    { Color c(95,135,215,68); colors[ c.code ] = c; }
    { Color c(95,135,255,69); colors[ c.code ] = c; }
    { Color c(95,175,0,70); colors[ c.code ] = c; }
    { Color c(95,175,95,71); colors[ c.code ] = c; }
    { Color c(95,175,135,72); colors[ c.code ] = c; }
    { Color c(95,175,175,73); colors[ c.code ] = c; }
    { Color c(95,175,215,74); colors[ c.code ] = c; }
    { Color c(95,175,255,75); colors[ c.code ] = c; }
    { Color c(95,215,0,76); colors[ c.code ] = c; }
    { Color c(95,215,95,77); colors[ c.code ] = c; }
    { Color c(95,215,135,78); colors[ c.code ] = c; }
    { Color c(95,215,175,79); colors[ c.code ] = c; }
    { Color c(95,215,215,80); colors[ c.code ] = c; }
    { Color c(95,215,255,81); colors[ c.code ] = c; }
    { Color c(95,255,0,82); colors[ c.code ] = c; }
    { Color c(95,255,95,83); colors[ c.code ] = c; }
    { Color c(95,255,135,84); colors[ c.code ] = c; }
    { Color c(95,255,175,85); colors[ c.code ] = c; }
    { Color c(95,255,215,86); colors[ c.code ] = c; }
    { Color c(95,255,255,87); colors[ c.code ] = c; }
    { Color c(135,0,0,88); colors[ c.code ] = c; }
    { Color c(135,0,95,89); colors[ c.code ] = c; }
    { Color c(135,0,135,90); colors[ c.code ] = c; }
    { Color c(135,0,175,91); colors[ c.code ] = c; }
    { Color c(135,0,215,92); colors[ c.code ] = c; }
    { Color c(135,0,255,93); colors[ c.code ] = c; }
    { Color c(135,95,0,94); colors[ c.code ] = c; }
    { Color c(135,95,95,95); colors[ c.code ] = c; }
    { Color c(135,95,135,96); colors[ c.code ] = c; }
    { Color c(135,95,175,97); colors[ c.code ] = c; }
    { Color c(135,95,215,98); colors[ c.code ] = c; }
    { Color c(135,95,255,99); colors[ c.code ] = c; }
    { Color c(135,135,0,100); colors[ c.code ] = c; }
    { Color c(135,135,95,101); colors[ c.code ] = c; }
    { Color c(135,135,135,102); colors[ c.code ] = c; }
    { Color c(135,135,175,103); colors[ c.code ] = c; }
    { Color c(135,135,215,104); colors[ c.code ] = c; }
    { Color c(135,135,255,105); colors[ c.code ] = c; }
    { Color c(135,175,0,106); colors[ c.code ] = c; }
    { Color c(135,175,95,107); colors[ c.code ] = c; }
    { Color c(135,175,135,108); colors[ c.code ] = c; }
    { Color c(135,175,175,109); colors[ c.code ] = c; }
    { Color c(135,175,215,110); colors[ c.code ] = c; }
    { Color c(135,175,255,111); colors[ c.code ] = c; }
    { Color c(135,215,0,112); colors[ c.code ] = c; }
    { Color c(135,215,95,113); colors[ c.code ] = c; }
    { Color c(135,215,135,114); colors[ c.code ] = c; }
    { Color c(135,215,175,115); colors[ c.code ] = c; }
    { Color c(135,215,215,116); colors[ c.code ] = c; }
    { Color c(135,215,255,117); colors[ c.code ] = c; }
    { Color c(135,255,0,118); colors[ c.code ] = c; }
    { Color c(135,255,95,119); colors[ c.code ] = c; }
    { Color c(135,255,135,120); colors[ c.code ] = c; }
    { Color c(135,255,175,121); colors[ c.code ] = c; }
    { Color c(135,255,215,122); colors[ c.code ] = c; }
    { Color c(135,255,255,123); colors[ c.code ] = c; }
    { Color c(175,0,0,124); colors[ c.code ] = c; }
    { Color c(175,0,95,125); colors[ c.code ] = c; }
    { Color c(175,0,135,126); colors[ c.code ] = c; }
    { Color c(175,0,175,127); colors[ c.code ] = c; }
    { Color c(175,0,215,128); colors[ c.code ] = c; }
    { Color c(175,0,255,129); colors[ c.code ] = c; }
    { Color c(175,95,0,130); colors[ c.code ] = c; }
    { Color c(175,95,95,131); colors[ c.code ] = c; }
    { Color c(175,95,135,132); colors[ c.code ] = c; }
    { Color c(175,95,175,133); colors[ c.code ] = c; }
    { Color c(175,95,215,134); colors[ c.code ] = c; }
    { Color c(175,95,255,135); colors[ c.code ] = c; }
    { Color c(175,135,0,136); colors[ c.code ] = c; }
    { Color c(175,135,95,137); colors[ c.code ] = c; }
    { Color c(175,135,135,138); colors[ c.code ] = c; }
    { Color c(175,135,175,139); colors[ c.code ] = c; }
    { Color c(175,135,215,140); colors[ c.code ] = c; }
    { Color c(175,135,255,141); colors[ c.code ] = c; }
    { Color c(175,175,0,142); colors[ c.code ] = c; }
    { Color c(175,175,95,143); colors[ c.code ] = c; }
    { Color c(175,175,135,144); colors[ c.code ] = c; }
    { Color c(175,175,175,145); colors[ c.code ] = c; }
    { Color c(175,175,215,146); colors[ c.code ] = c; }
    { Color c(175,175,255,147); colors[ c.code ] = c; }
    { Color c(175,215,0,148); colors[ c.code ] = c; }
    { Color c(175,215,95,149); colors[ c.code ] = c; }
    { Color c(175,215,135,150); colors[ c.code ] = c; }
    { Color c(175,215,175,151); colors[ c.code ] = c; }
    { Color c(175,215,215,152); colors[ c.code ] = c; }
    { Color c(175,215,255,153); colors[ c.code ] = c; }
    { Color c(175,255,0,154); colors[ c.code ] = c; }
    { Color c(175,255,95,155); colors[ c.code ] = c; }
    { Color c(175,255,135,156); colors[ c.code ] = c; }
    { Color c(175,255,175,157); colors[ c.code ] = c; }
    { Color c(175,255,215,158); colors[ c.code ] = c; }
    { Color c(175,255,255,159); colors[ c.code ] = c; }
    { Color c(215,0,0,160); colors[ c.code ] = c; }
    { Color c(215,0,95,161); colors[ c.code ] = c; }
    { Color c(215,0,135,162); colors[ c.code ] = c; }
    { Color c(215,0,175,163); colors[ c.code ] = c; }
    { Color c(215,0,215,164); colors[ c.code ] = c; }
    { Color c(215,0,255,165); colors[ c.code ] = c; }
    { Color c(215,95,0,166); colors[ c.code ] = c; }
    { Color c(215,95,95,167); colors[ c.code ] = c; }
    { Color c(215,95,135,168); colors[ c.code ] = c; }
    { Color c(215,95,175,169); colors[ c.code ] = c; }
    { Color c(215,95,215,170); colors[ c.code ] = c; }
    { Color c(215,95,255,171); colors[ c.code ] = c; }
    { Color c(215,135,0,172); colors[ c.code ] = c; }
    { Color c(215,135,95,173); colors[ c.code ] = c; }
    { Color c(215,135,135,174); colors[ c.code ] = c; }
    { Color c(215,135,175,175); colors[ c.code ] = c; }
    { Color c(215,135,215,176); colors[ c.code ] = c; }
    { Color c(215,135,255,177); colors[ c.code ] = c; }
    { Color c(215,175,0,178); colors[ c.code ] = c; }
    { Color c(215,175,95,179); colors[ c.code ] = c; }
    { Color c(215,175,135,180); colors[ c.code ] = c; }
    { Color c(215,175,175,181); colors[ c.code ] = c; }
    { Color c(215,175,215,182); colors[ c.code ] = c; }
    { Color c(215,175,255,183); colors[ c.code ] = c; }
    { Color c(215,215,0,184); colors[ c.code ] = c; }
    { Color c(215,215,95,185); colors[ c.code ] = c; }
    { Color c(215,215,135,186); colors[ c.code ] = c; }
    { Color c(215,215,175,187); colors[ c.code ] = c; }
    { Color c(215,215,215,188); colors[ c.code ] = c; }
    { Color c(215,215,255,189); colors[ c.code ] = c; }
    { Color c(215,255,0,190); colors[ c.code ] = c; }
    { Color c(215,255,95,191); colors[ c.code ] = c; }
    { Color c(215,255,135,192); colors[ c.code ] = c; }
    { Color c(215,255,175,193); colors[ c.code ] = c; }
    { Color c(215,255,215,194); colors[ c.code ] = c; }
    { Color c(215,255,255,195); colors[ c.code ] = c; }
    { Color c(255,0,0,196); colors[ c.code ] = c; }
    { Color c(255,0,95,197); colors[ c.code ] = c; }
    { Color c(255,0,135,198); colors[ c.code ] = c; }
    { Color c(255,0,175,199); colors[ c.code ] = c; }
    { Color c(255,0,215,200); colors[ c.code ] = c; }
    { Color c(255,0,255,201); colors[ c.code ] = c; }
    { Color c(255,95,0,202); colors[ c.code ] = c; }
    { Color c(255,95,95,203); colors[ c.code ] = c; }
    { Color c(255,95,135,204); colors[ c.code ] = c; }
    { Color c(255,95,175,205); colors[ c.code ] = c; }
    { Color c(255,95,215,206); colors[ c.code ] = c; }
    { Color c(255,95,255,207); colors[ c.code ] = c; }
    { Color c(255,135,0,208); colors[ c.code ] = c; }
    { Color c(255,135,95,209); colors[ c.code ] = c; }
    { Color c(255,135,135,210); colors[ c.code ] = c; }
    { Color c(255,135,175,211); colors[ c.code ] = c; }
    { Color c(255,135,215,212); colors[ c.code ] = c; }
    { Color c(255,135,255,213); colors[ c.code ] = c; }
    { Color c(255,175,0,214); colors[ c.code ] = c; }
    { Color c(255,175,95,215); colors[ c.code ] = c; }
    { Color c(255,175,135,216); colors[ c.code ] = c; }
    { Color c(255,175,175,217); colors[ c.code ] = c; }
    { Color c(255,175,215,218); colors[ c.code ] = c; }
    { Color c(255,175,255,219); colors[ c.code ] = c; }
    { Color c(255,215,0,220); colors[ c.code ] = c; }
    { Color c(255,215,95,221); colors[ c.code ] = c; }
    { Color c(255,215,135,222); colors[ c.code ] = c; }
    { Color c(255,215,175,223); colors[ c.code ] = c; }
    { Color c(255,215,215,224); colors[ c.code ] = c; }
    { Color c(255,215,255,225); colors[ c.code ] = c; }
    { Color c(255,255,0,226); colors[ c.code ] = c; }
    { Color c(255,255,95,227); colors[ c.code ] = c; }
    { Color c(255,255,135,228); colors[ c.code ] = c; }
    { Color c(255,255,175,229); colors[ c.code ] = c; }
    { Color c(255,255,215,230); colors[ c.code ] = c; }
    { Color c(255,255,255,231); colors[ c.code ] = c; }
    { Color c(8,8,8,232); colors[ c.code ] = c; }
    { Color c(18,18,18,233); colors[ c.code ] = c; }
    { Color c(28,28,28,234); colors[ c.code ] = c; }
    { Color c(38,38,38,235); colors[ c.code ] = c; }
    { Color c(48,48,48,236); colors[ c.code ] = c; }
    { Color c(58,58,58,237); colors[ c.code ] = c; }
    { Color c(68,68,68,238); colors[ c.code ] = c; }
    { Color c(78,78,78,239); colors[ c.code ] = c; }
    { Color c(88,88,88,240); colors[ c.code ] = c; }
    { Color c(98,98,98,241); colors[ c.code ] = c; }
    { Color c(108,108,108,242); colors[ c.code ] = c; }
    { Color c(118,118,118,243); colors[ c.code ] = c; }
    { Color c(128,128,128,244); colors[ c.code ] = c; }
    { Color c(138,138,138,245); colors[ c.code ] = c; }
    { Color c(148,148,148,246); colors[ c.code ] = c; }
    { Color c(158,158,158,247); colors[ c.code ] = c; }
    { Color c(168,168,168,248); colors[ c.code ] = c; }
    { Color c(178,178,178,249); colors[ c.code ] = c; }
    { Color c(188,188,188,250); colors[ c.code ] = c; }
    { Color c(198,198,198,251); colors[ c.code ] = c; }
    { Color c(208,208,208,252); colors[ c.code ] = c; }
    { Color c(218,218,218,253); colors[ c.code ] = c; }
    { Color c(228,228,228,254); colors[ c.code ] = c; }
    { Color c(238,238,238,255); colors[ c.code ] = c; }

  }

};

}//color256
}//CLIProteinViewer

/*backup
  rgb(0,0,0) 0
  rgb(128,0,0) 1
  rgb(0,128,0) 2
  rgb(128,128,0) 3
  rgb(0,0,128) 4
  rgb(128,0,128) 5
  rgb(0,128,128) 6
  rgb(192,192,192) 7
  rgb(128,128,128) 8
  rgb(255,0,0) 9
  rgb(0,255,0) 10
  rgb(255,255,0) 11
  rgb(0,0,255) 12
  rgb(255,0,255) 13
  rgb(0,255,255) 14
  rgb(255,255,255) 15
  rgb(0,0,0) 16
  rgb(0,0,95) 17
  rgb(0,0,135) 18
  rgb(0,0,175) 19
  rgb(0,0,215) 20
  rgb(0,0,255) 21
  rgb(0,95,0) 22
  rgb(0,95,95) 23
  rgb(0,95,135) 24
  rgb(0,95,175) 25
  rgb(0,95,215) 26
  rgb(0,95,255) 27
  rgb(0,135,0) 28
  rgb(0,135,95) 29
  rgb(0,135,135) 30
  rgb(0,135,175) 31
  rgb(0,135,215) 32
  rgb(0,135,255) 33
  rgb(0,175,0) 34
  rgb(0,175,95) 35
  rgb(0,175,135) 36
  rgb(0,175,175) 37
  rgb(0,175,215) 38
  rgb(0,175,255) 39
  rgb(0,215,0) 40
  rgb(0,215,95) 41
  rgb(0,215,135) 42
  rgb(0,215,175) 43
  rgb(0,215,215) 44
  rgb(0,215,255) 45
  rgb(0,255,0) 46
  rgb(0,255,95) 47
  rgb(0,255,135) 48
  rgb(0,255,175) 49
  rgb(0,255,215) 50
  rgb(0,255,255) 51
  rgb(95,0,0) 52
  rgb(95,0,95) 53
  rgb(95,0,135) 54
  rgb(95,0,175) 55
  rgb(95,0,215) 56
  rgb(95,0,255) 57
  rgb(95,95,0) 58
  rgb(95,95,95) 59
  rgb(95,95,135) 60
  rgb(95,95,175) 61
  rgb(95,95,215) 62
  rgb(95,95,255) 63
  rgb(95,135,0) 64
  rgb(95,135,95) 65
  rgb(95,135,135) 66
  rgb(95,135,175) 67
  rgb(95,135,215) 68
  rgb(95,135,255) 69
  rgb(95,175,0) 70
  rgb(95,175,95) 71
  rgb(95,175,135) 72
  rgb(95,175,175) 73
  rgb(95,175,215) 74
  rgb(95,175,255) 75
  rgb(95,215,0) 76
  rgb(95,215,95) 77
  rgb(95,215,135) 78
  rgb(95,215,175) 79
  rgb(95,215,215) 80
  rgb(95,215,255) 81
  rgb(95,255,0) 82
  rgb(95,255,95) 83
  rgb(95,255,135) 84
  rgb(95,255,175) 85
  rgb(95,255,215) 86
  rgb(95,255,255) 87
  rgb(135,0,0) 88
  rgb(135,0,95) 89
  rgb(135,0,135) 90
  rgb(135,0,175) 91
  rgb(135,0,215) 92
  rgb(135,0,255) 93
  rgb(135,95,0) 94
  rgb(135,95,95) 95
  rgb(135,95,135) 96
  rgb(135,95,175) 97
  rgb(135,95,215) 98
  rgb(135,95,255) 99
  rgb(135,135,0) 100
  rgb(135,135,95) 101
  rgb(135,135,135) 102
  rgb(135,135,175) 103
  rgb(135,135,215) 104
  rgb(135,135,255) 105
  rgb(135,175,0) 106
  rgb(135,175,95) 107
  rgb(135,175,135) 108
  rgb(135,175,175) 109
  rgb(135,175,215) 110
  rgb(135,175,255) 111
  rgb(135,215,0) 112
  rgb(135,215,95) 113
  rgb(135,215,135) 114
  rgb(135,215,175) 115
  rgb(135,215,215) 116
  rgb(135,215,255) 117
  rgb(135,255,0) 118
  rgb(135,255,95) 119
  rgb(135,255,135) 120
  rgb(135,255,175) 121
  rgb(135,255,215) 122
  rgb(135,255,255) 123
  rgb(175,0,0) 124
  rgb(175,0,95) 125
  rgb(175,0,135) 126
  rgb(175,0,175) 127
  rgb(175,0,215) 128
  rgb(175,0,255) 129
  rgb(175,95,0) 130
  rgb(175,95,95) 131
  rgb(175,95,135) 132
  rgb(175,95,175) 133
  rgb(175,95,215) 134
  rgb(175,95,255) 135
  rgb(175,135,0) 136
  rgb(175,135,95) 137
  rgb(175,135,135) 138
  rgb(175,135,175) 139
  rgb(175,135,215) 140
  rgb(175,135,255) 141
  rgb(175,175,0) 142
  rgb(175,175,95) 143
  rgb(175,175,135) 144
  rgb(175,175,175) 145
  rgb(175,175,215) 146
  rgb(175,175,255) 147
  rgb(175,215,0) 148
  rgb(175,215,95) 149
  rgb(175,215,135) 150
  rgb(175,215,175) 151
  rgb(175,215,215) 152
  rgb(175,215,255) 153
  rgb(175,255,0) 154
  rgb(175,255,95) 155
  rgb(175,255,135) 156
  rgb(175,255,175) 157
  rgb(175,255,215) 158
  rgb(175,255,255) 159
  rgb(215,0,0) 160
  rgb(215,0,95) 161
  rgb(215,0,135) 162
  rgb(215,0,175) 163
  rgb(215,0,215) 164
  rgb(215,0,255) 165
  rgb(215,95,0) 166
  rgb(215,95,95) 167
  rgb(215,95,135) 168
  rgb(215,95,175) 169
  rgb(215,95,215) 170
  rgb(215,95,255) 171
  rgb(215,135,0) 172
  rgb(215,135,95) 173
  rgb(215,135,135) 174
  rgb(215,135,175) 175
  rgb(215,135,215) 176
  rgb(215,135,255) 177
  rgb(215,175,0) 178
  rgb(215,175,95) 179
  rgb(215,175,135) 180
  rgb(215,175,175) 181
  rgb(215,175,215) 182
  rgb(215,175,255) 183
  rgb(215,215,0) 184
  rgb(215,215,95) 185
  rgb(215,215,135) 186
  rgb(215,215,175) 187
  rgb(215,215,215) 188
  rgb(215,215,255) 189
  rgb(215,255,0) 190
  rgb(215,255,95) 191
  rgb(215,255,135) 192
  rgb(215,255,175) 193
  rgb(215,255,215) 194
  rgb(215,255,255) 195
  rgb(255,0,0) 196
  rgb(255,0,95) 197
  rgb(255,0,135) 198
  rgb(255,0,175) 199
  rgb(255,0,215) 200
  rgb(255,0,255) 201
  rgb(255,95,0) 202
  rgb(255,95,95) 203
  rgb(255,95,135) 204
  rgb(255,95,175) 205
  rgb(255,95,215) 206
  rgb(255,95,255) 207
  rgb(255,135,0) 208
  rgb(255,135,95) 209
  rgb(255,135,135) 210
  rgb(255,135,175) 211
  rgb(255,135,215) 212
  rgb(255,135,255) 213
  rgb(255,175,0) 214
  rgb(255,175,95) 215
  rgb(255,175,135) 216
  rgb(255,175,175) 217
  rgb(255,175,215) 218
  rgb(255,175,255) 219
  rgb(255,215,0) 220
  rgb(255,215,95) 221
  rgb(255,215,135) 222
  rgb(255,215,175) 223
  rgb(255,215,215) 224
  rgb(255,215,255) 225
  rgb(255,255,0) 226
  rgb(255,255,95) 227
  rgb(255,255,135) 228
  rgb(255,255,175) 229
  rgb(255,255,215) 230
  rgb(255,255,255) 231
  rgb(8,8,8) 232
  rgb(18,18,18) 233
  rgb(28,28,28) 234
  rgb(38,38,38) 235
  rgb(48,48,48) 236
  rgb(58,58,58) 237
  rgb(68,68,68) 238
  rgb(78,78,78) 239
  rgb(88,88,88) 240
  rgb(98,98,98) 241
  rgb(108,108,108) 242
  rgb(118,118,118) 243
  rgb(128,128,128) 244
  rgb(138,138,138) 245
  rgb(148,148,148) 246
  rgb(158,158,158) 247
  rgb(168,168,168) 248
  rgb(178,178,178) 249
  rgb(188,188,188) 250
  rgb(198,198,198) 251
  rgb(208,208,208) 252
  rgb(218,218,218) 253
  rgb(228,228,228) 254
  rgb(238,238,238) 255
*/
