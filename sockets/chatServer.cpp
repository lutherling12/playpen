#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <pthread.h>

#define CHAR_LIMIT 2048

int main (int argc, char * argv [])
{
  const char* ip = "127.0.0.1";
  const char* port = "50008";

  struct addrinfo config;
    memset(&config, 0, sizeof(struct addrinfo));
    config.ai_family = AF_UNSPEC;
    config.ai_socktype = SOCK_STREAM;
    config.ai_flags = AI_PASSIVE;
    config.ai_protocol = 0;
    config.ai_canonname = NULL;
    config.ai_addr = NULL;
    config.ai_next = NULL;

  struct addrinfo* results = NULL;
  struct addrinfo cliaddr;
    memset(&cliaddr, 0, sizeof(struct addrinfo));

  char msg [CHAR_LIMIT] = "";

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

  if (bind (sfd, results->ai_addr, results->ai_addrlen) != 0) {
    fprintf (stderr, "Binding failed.\n");
    exit (EXIT_FAILURE);
  }

  freeaddrinfo (results);
  printf ("Server Bound.\n");

  listen (sfd, 5);
  int clientfd1 = accept (sfd, cliaddr.ai_addr, &cliaddr.ai_addrlen);
  int clientfd2 = accept (sfd, cliaddr.ai_addr, &cliaddr.ai_addrlen);

  for (;;) { 
    if (recv (clientfd1, msg, CHAR_LIMIT, MSG_DONTWAIT) > 0) {
      send (clientfd2, msg, CHAR_LIMIT, 0);
      printf (">: %s", msg);
    }
    else if (recv (clientfd2, msg, CHAR_LIMIT, MSG_DONTWAIT) > 0) {
      send (clientfd1, msg, CHAR_LIMIT, 0);
      printf ("<: %s", msg);
    }
    
    memset (msg, 0, sizeof(msg));
  }

  close (sfd);
  return 0;
}