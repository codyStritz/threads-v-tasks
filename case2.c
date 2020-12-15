#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Set NUM_THREADS and N macros to the appropriate values before compiling */
#define NUM_THREADS 8 
#define N 100000000   
#define ITERATIONS N/NUM_THREADS

long long unsigned sum = 0, a[N];
pthread_mutex_t sum_mutex;


void *calc(void *tid){
    
    int i, start, *mytid, end;
    long long unsigned temp_sum=0;

    
    mytid = (int *)tid;
    start = (*mytid * ITERATIONS);
    end = start + ITERATIONS;

    for(i = start; i < end; i++){
        a[i] = i;
        temp_sum = temp_sum + a[i];
    }

    /* Lock mutex and update global sum */
    pthread_mutex_lock(&sum_mutex);
    sum = sum + temp_sum;
    pthread_mutex_unlock(&sum_mutex);
    /* exit */
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){

    int i, start, tids[NUM_THREADS];
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;

    pthread_mutex_init(&sum_mutex, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for(i = 0; i < NUM_THREADS; i++){
        tids[i] = i;
        pthread_create(&threads[i], &attr, calc, (void *)&tids[i]);   
    }

    /* join all threads and print global sum */
    for(i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("Sum= %llu \n", sum);

    
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&sum_mutex);
    pthread_exit(NULL);
}