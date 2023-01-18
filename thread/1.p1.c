#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>

void *fun(void *a)
{
    
    printf("From thread body...\n");
    sleep(3);
    return ("Return from thread...");
}

int main(int argc, char const *argv[])
{
    pthread_t th;
    int ch;
    void *arg;
    int *n;
    printf("Enter a number : ");
    
    char *msg = "Message from the other world XD";
    ch = pthread_create(&th, NULL, fun, (void *)msg);

    printf("Waiting for the other thread to complete");
    char p = pthread_join(th, &arg);
    printf("Returned value = %s\n", (char *)arg);

    return 0;
}
