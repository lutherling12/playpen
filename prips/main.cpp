#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <arpa/inet.h>

struct compare_s {
  bool operator() (const char* lhs, const char* rhs) {
    int cmp = strncmp (lhs, rhs, INET_ADDRSTRLEN);
    // if lhs < rhs
    if (cmp < 0)
      return true;
    else
      return false;
  }
};

typedef std::map<const char*, int, compare_s> cstrMap;

int main (int argc, char* argv [])
{
  cstrMap testMap;

  cstrMap::key_compare compTest = testMap.key_comp ();

  // Setting value
  testMap ["192.168.0.10"] = 1;

  // Access Value
  printf ("Value: %i\n", testMap ["192.168.0.10"]);
  // Invalid Access
  printf ("Invalid: %i\n", testMap ["NonXist"]);

  // Key Comparisons
  printf ("lhs < rhs Key:\t False: %i, True: %i, False: %i\n",
    //Equal returns False
    compTest ("192.168.0.10", "192.168.0.10"),
    //lhs < rhs returns True
    compTest ("192.168.0.10", "192.168.0.20"),
    //rhs > lhs returns False
    compTest ("192.168.0.10", "192.168.0.0")
  );

  return 0;
}