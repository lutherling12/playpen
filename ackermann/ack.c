#include <stdlib.h>
#include <stdio.h>

#include <sys/time.h>
#include <sys/resource.h>

long int ackmn (long int m, long int n);

int main (int argc, char ** argv) {

  struct rusage thisProc;
  
  if (argc != 3) {
    printf ("Usage is <prog> <int> <int>.\n");
    return 1;
  }
  else {
    long int a = (long int)atoi (argv[1]);
    long int b = (long int)atoi (argv[2]);
    long int result = ackmn (a, b);
    printf ("A (%li, %li) = %li\n", a, b, result);
  }

  if (getrusage (RUSAGE_SELF, &thisProc) == 0) {
    if (thisProc.ru_utime.tv_sec > 0) {
      printf ("User CPU Time: %li seconds\n", thisProc.ru_utime.tv_sec);
    }
    else {
      printf ("User CPU Time: %li microseconds\n", thisProc.ru_utime.tv_usec);
    }
  }

  return 0;
}

long int ackmn (long int m, long int n) {
  if (m == 0) {
    return n + 1;
  }
  else if ((m > 0) && (n == 0)) {
    return ackmn (m - 1, 1);
  }
  else if ((m > 0) && (n > 0)) {
    return ackmn (m - 1, ackmn (m, n - 1));
  }
  return -1;
}