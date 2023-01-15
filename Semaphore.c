// Write a program implementing two separate threads, one keeps printing 1-5 and halts for one
// second & the other repeatedly print A,B,C,D,E and for one second. Both share the same output
// terminal. So the same resource should be shared within a critical section. Implement the solution
// using Semaphore.
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void* thread1_func() {
    int i;
    for (i = 1; i <= 5; i++) {
        sem_wait(&sem); // enter critical section
        printf("%d ", i);
        fflush(stdout);
        sem_post(&sem); // exit critical section
        sleep(1);
    }
    return NULL;
}

void* thread2_func() {
    char c;
    for (c = 'A'; c <= 'E'; c++) {
        sem_wait(&sem); // enter critical section
        printf("%c ", c);
        fflush(stdout);
        sem_post(&sem); // exit critical section
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    sem_init(&sem, 0, 1); // initialize semaphore with value 1

    // create threads
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    // wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&sem); // destroy semaphore
    return 0;
}


