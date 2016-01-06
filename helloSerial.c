#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arducomm.h"
#include <unistd.h>

#define BUFFER_SIZE 256

int main (int argc, char * argv[])
{
  int fd = -1;
  char buffer [BUFFER_SIZE];
  // int * buffer = NULL;

  if (argc > 1) fd = serialport_init (argv[1], 9600);
  else fd = serialport_init ("/dev/ttyACM0", 9600);

  for (;;) {
    serialport_read_until (fd, buffer, '\0', BUFFER_SIZE, 1000);
    if (strlen (buffer) > 0) {
      // printf ("New Write: %i\n", atoi(buffer));
      printf ("New Write: %s\n", buffer);
    }
    // sleep(1);
    serialport_write (fd, "Buenos Dias!\n");
  }

  return 0;
}
