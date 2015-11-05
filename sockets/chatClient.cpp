#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>

#define CHAR_LIMIT 2048

int main (int argc, char * argv[])
{
  const char* ip = "127.0.0.1";
  const char* port = "50008";

  struct addrinfo config;
    memset (&config, 0, sizeof(struct addrinfo));
    config.ai_family = AF_UNSPEC;
    config.ai_socktype = SOCK_STREAM;

  struct addrinfo* results;

  char msg [CHAR_LIMIT];

  int gai = getaddrinfo (ip, port, &config, &results);
  if (gai != 0) {
    fprintf (stderr, "getaddrinfo: %s\n", gai_strerror(gai));
    exit (EXIT_FAILURE);
  }

  int sfd = socket (
    results->ai_family,
    results->ai_socktype,
    results->ai_protocol
  );

  if (sfd == -1) {
    fprintf (stderr, "Socket not open.\n");
    exit (EXIT_FAILURE);
  }

  if (connect (sfd, results->ai_addr, results->ai_addrlen) != 0) {
    fprintf (stderr, "Failed to connect.\n");
    exit (EXIT_FAILURE);
  }

  freeaddrinfo (results);

  for (;;) {
    fgets (msg, CHAR_LIMIT, stdin);
    send (sfd, msg, sizeof(msg), 0);
  }

  close (sfd);
  return 0;
}
