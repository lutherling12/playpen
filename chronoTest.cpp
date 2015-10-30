#include <chrono>
#include <iostream>
#include <unistd.h>
#include <string.h>

typedef std::chrono::milliseconds ms;
typedef std::chrono::system_clock sysClock;

int main (int argc, char * argv[])
{
  if (argc > 1) {
    sysClock grandfather;
    auto start = grandfather.now();
    usleep (atoi(argv[1]));
    auto end = grandfather.now();

    std::chrono::duration<double> elapsed = (end - start);

    std::cout << elapsed.count() << std::endl;
  }

  return 0;
}
