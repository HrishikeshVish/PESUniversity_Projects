#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int  k, n, id;
  double x = 0,  z=0, y=0;

  printf(1, "Parent:%d\n", getpid());

  if(argc < 2 )
    n = 1;       //default value
  else
    n = atoi ( argv[1] ); //from command line
  if ( n < 0 || n > 20 )
    n = 2;
  x = 0;
  id = 0;
  for ( k = 0; k < n; k++ ) {
    id = fork ();
    if(id == 0) {
      // child
      printf(1, "Child process %d\n", getpid());
      
      for(y=0; y<400.0; y+=0.1) {
        printf(1, ".");
        for(x=0; x<40000.0; x+=0.1) {
          z+= x;
	  // while(z>0) z--;
        }
      }

      printf(1, "Child completed %d\n", getpid());

      exit();
    } else if(id > 0) {
      printf(1, "Parent created %d\n", id);
    } else if(id<0) {
      printf(1, "Fork Failed\n");
    }
  }

  cps();

  for(k=0; k<n; k++) {
    printf(1, "W%d\n", k);
    wait();
  }
  exit();
}
