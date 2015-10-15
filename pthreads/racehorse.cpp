#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <pthread.h>

#define NUM_OF_HORSES 5

typedef pthread_t horse;
typedef pthread_mutex_t mutex;

typedef struct {
  long id = -1;

  bool* start = NULL;
  bool* finish = NULL;
  mutex* finishLine = NULL;
} results;


void * racehorse (void*);

int main (int argc, char * argv[])
{
  std::srand (std::time(0));

  horse horses [NUM_OF_HORSES];
  results* recorded;

  mutex finishMutex = PTHREAD_MUTEX_INITIALIZER;
  bool startSignal = false;
  // bool finishFlag = false;

  for (long i = 0; i < NUM_OF_HORSES; i++) {
    // Make a horse.
    recorded = new results;
    recorded->id = i;
    recorded->start = &startSignal;
    // recorded->finish = &finishFlag;
    recorded->finishLine = &finishMutex;
    pthread_create (&horses[i], NULL, racehorse, recorded);
  }

  std::cout << "Annd they're off!" << std::endl;
  startSignal = true;

  pthread_exit (NULL);
}

void* racehorse (void* bestHorse)
{
  double progress = 0;
  results * winner = (results*) bestHorse;
  std::string announcer =
    "Horse " + std::to_string(winner->id) + " has crossed the finish line!";

  while (*(winner->start) == false);
    //Wait for the signal.

  while (progress < 100)
    progress += (rand () % 10);

  pthread_mutex_lock (winner->finishLine);
    std::cout << announcer << std::endl;
    // *(winner->finish) = true;
  pthread_mutex_unlock (winner->finishLine);

  pthread_exit (0);
}
