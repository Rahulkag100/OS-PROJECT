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
