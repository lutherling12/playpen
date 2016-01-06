#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[])
{
  struct in_addr ip;
  char buff[INET_ADDRSTRLEN];

  strncpy (buff, argv[1], INET_ADDRSTRLEN);

  inet_pton (AF_INET, buff, &ip);
  inet_ntop (AF_INET, &ip, buff, INET_ADDRSTRLEN);

  printf ("%s's s_addr is: %u.\n", buff, ip.s_addr);

  return 0;
}
