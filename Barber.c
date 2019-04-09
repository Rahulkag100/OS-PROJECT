#include <unistd.h>

#include <pthread.h>

#include <stdio.h>

#include <stdlib.h>

#include <semaphore.h>



#define NUM_THREADS 100

pthread_t threads[NUM_THREADS];



int seats = 0;

pthread_mutex_t mutex;

sem_t customers;

sem_t barber;
void *barberBob(void *threadid){

  int haircuts = NUM_THREADS-1;

  while(haircuts > 0){

    sem_wait(&customers);

    pthread_mutex_lock(&mutex);

    seats++;

    sem_post(&barber);

    haircuts--;

    printf("cutting some hair, waiting on next customer\n");

    pthread_mutex_unlock(&mutex);

    printf("\n Barber Thread: haircuts = %d, chairs left = %d \n",haircuts,seats);

  }

  printf("Closing shop, bye!\n");

  pthread_exit(NULL);

}

