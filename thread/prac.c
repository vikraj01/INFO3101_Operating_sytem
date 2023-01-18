#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

void *fun(void *a)
{
    int n = *((int *)a);
    printf("done");
    printf("%d\n", n);
    return ("Thread done");
}

void *th_body(void *a)
{
    int n = *((int *)a);
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 > 0)
        {
            printf("\nThread 1 odd %d\n", i);
            sleep(1);
        }
    }
    return ("Thread2 done");
}

int main(int argc, char const *argv[])
{
    // int *n;
    // printf("Enter a number : ");
    // scanf("%d", n);

    // pthread_t th;
    // void *args;
    // char ch = pthread_create(&th, NULL, fun, (void *)n);

    // char t = pthread_join(th, &args);

    // printf("Msg: %s", (char *)args);

    pthread_t th;
    int ch, *a;
    void *arg;
    printf("number dal : ");
    scanf("%d", a);
    // ch = pthread_create(&th, NULL, th_body, (void *)a);
    ch = pthread_create(&th, NULL, th_body, (void *)a);
    if (ch != 0)
    {
        printf("Creation failed\n");
        exit(0);
    }

    ch = pthread_join(th, &arg);
    printf("\nReturned value %s %s\n", (char *)arg);
    return 0;

    // pthread_t th;
    // int *a;
    // scanf("%d",a);
    // void *args;
    // int ch ;
    // ch = pthread_create(&th, NULL, th_body, (void *)a);
    // int t = pthread_join(th, &args);
    // printf("\nReturned value %s \n", (char *)args);

    // return 0;
}
