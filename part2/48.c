#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
// #include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int x, y;
    x = fork();
    if (x < 0)
    {
        printf("Fork Failure\n");
        exit(-1);
    }
    else if (x == 0)
    {
        
        for (int i = 0; i < 10; i++)
        {
            printf("%d\n", i);
            printf("Parent Process ID: %d\n", getppid());
            printf("Child processID : %d\n", getpid());
        }
    }
    else
    {
        y = fork();
        if (y < 0)
        {
            printf("Fork Failure\n");
            exit(-1);
        }
        else if (y == 0)
        {
            for (int i = 0; i < 10; i++)
            {
                printf("%d\n", i);
                printf("Parent Process ID: %d\n", getppid());
                printf("Child processID : %d\n", getpid());
            }
        }

        wait(NULL);
        printf("Good Bye");
    }
    return 0;
}
