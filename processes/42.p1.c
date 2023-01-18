#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler1(int s)
{
    printf("Parent wants to terminate the child process...");
    signal(SIGINT, SIG_DFL);
    sleep(3);
    kill(getpid(), SIGINT);
}

void handler2(int s)
{
    printf("Child proccess is terminated");
}

int main(int argc, char const *argv[])
{
    int p = fork();
    if (p < 0)
    {
        exit(-1);
    }
    else if (p == 0)
    {
        signal(SIGINT, handler1);
        while (1)
        {
            sleep(1);
            printf("Child proccess id is : %d\n", getpid());
        }
    }
    else if (p > 0)
    {
        signal(SIGCHLD, handler2);
        sleep(3);
        printf("Child proccess id is %d and parent process id is %d\n", p, getpid());
        if (p % 2 == 0)
            (void)kill(p, SIGINT);
        sleep(5);
        printf("Parent Proccess exit\n");
    }

    return 0;
}
