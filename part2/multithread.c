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
    char *msg = "Thread Program...";
    ch = pthread_create(&th, NULL, fun, (void *)msg);
    if (ch != 0)
    {
        printf("Thread creation failed");
        exit(0);
    }

    printf("Waiting for thread....\n");
    ch = pthread_join(th, &arg);
    if (ch != 0)
    {
        printf("Thread join failed");
        exit(0);
    }
    printf("Returned value = %s\n", (char *)arg);

    return 0;
}
