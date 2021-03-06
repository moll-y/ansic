#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "kcol.h"
#include "anik.h"

#define LIMIT 1e7

int counter = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
lock_t k;

void *
func1 (void *arg)
{
  int i;

  for (i = 0; i < LIMIT; i++)
    {
      lock (&k);
      counter = counter + 1;
      unlock (&k);
    }
  return NULL;
}

void *
func2 (void *arg)
{
  int i;

  for (i = 0; i < LIMIT; i++)
    {
      pthread_mutex_lock (&m);
      counter = counter + 1;
      pthread_mutex_unlock (&m);
    }
  return NULL;
}

int
main (int argc, char *argv[])
{
  pthread_t p1, p2, p3;
  void *(*f) (void *);
  int done;
  char c;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      {
	switch (c)
	  {
	  case 'n':
	    f = func2;
	    break;
	  case 'm':
	    init (&k);
	    f = func1;
	    break;
	  default:
	    fputs ("Usage: main -OPTION\n", stderr);
	    exit (0);
	  }
	done = 0;
	pthread_create (&p3, NULL, anik, (void *) &done);
	pthread_create (&p1, NULL, f, NULL);
	pthread_create (&p2, NULL, f, NULL);
	pthread_join (p1, NULL);
	pthread_join (p2, NULL);
	done = 1;
	pthread_join (p3, NULL);
	printf ("%d\n", counter);
      }
  return 0;
}
