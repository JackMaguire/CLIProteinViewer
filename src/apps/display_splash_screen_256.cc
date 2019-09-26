#include <iostream>

#include <visualize/visualize.hh>
#include <visualize/colors.hh>
#include <visualize/color256.hh>

using namespace CLIProteinViewer;
using namespace CLIProteinViewer::visualize;
using namespace CLIProteinViewer::color;

int main(){

  

  return 0;

  Screen screen;
  std::cout << screen.height() << " x " << screen.width() << std::endl;
  screen.set_to_splash_screen();
  printf("\n");
  for( int h = 0; h < screen.height(); ++h ){
    for( int w = 0; w < screen.width(); ++w ){
      //std::cout << screen.pixel( h, w ).r << std::endl;
      print_nearest_color( screen.pixel( h, w ) );
    }
  }
}
