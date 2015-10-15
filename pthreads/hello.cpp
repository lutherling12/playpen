/******************************************************************************
* FILE: hello.c
* DESCRIPTION:
*   A "hello world" Pthreads program.  Demonstrates thread creation and
*   termination.
* AUTHOR: Blaise Barney
* LAST REVISED: 08/09/11
******************************************************************************/
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#define NUM_THREADS	10

pthread_mutex_t sampleLock = PTHREAD_MUTEX_INITIALIZER;
std::string str = "";

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;

   pthread_mutex_lock (&sampleLock);

     str = "Thread " + std::to_string (tid) + " says hello!";
     std::cout << str << std::endl;
    //  sleep (10);

   pthread_mutex_unlock(&sampleLock);

   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];

   int rc;
   long t;
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);
     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
