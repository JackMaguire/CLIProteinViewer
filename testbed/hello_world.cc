//From: https://stackoverflow.com/questions/18281412/check-keypress-in-c-on-linux
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main()
{
  struct termios oldSettings, newSettings;

  tcgetattr( fileno( stdin ), &oldSettings );
  newSettings = oldSettings;
  newSettings.c_lflag &= (~ICANON & ~ECHO);
  tcsetattr( fileno( stdin ), TCSANOW, &newSettings );    

  int abc = 0;

  while ( 1 )
    {
      const std::string test("\033[0;" + std::to_string(abc) + "m");
      const std::string reset("\033[0m");
      ++abc;
      abc %= 256;

      std::cout << test << "TESTING" << reset << std::endl;

      fd_set set;
      struct timeval tv;

      tv.tv_sec = 10;
      tv.tv_usec = 0;

      FD_ZERO( &set );
      FD_SET( fileno( stdin ), &set );

      int res = select( fileno( stdin )+1, &set, NULL, NULL, &tv );

      if( res > 0 )
        {
	  char c;
	  read( fileno( stdin ), &c, 1 );
	  std::cout << c << " " << int(c) << " " << std::endl;
	  /*
	    Output for LDRU:
	    27 
	    [ 91 
	    D 68 
	    27 
	    [ 91 
	    B 66 
	    27 
	    [ 91 
	    C 67 
	    27 
	    [ 91 
	    A 65
	  */
        }
      else if( res < 0 )
        {
	  perror( "select error" );
	  break;
        }
      else
        {
	  printf( "Select timeout\n" );
        }
    }

  tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
  return 0;
}
