#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void fun1(int s)
{
    printf("Parents want to terminate\n");
    (void)signal(SIGINT, SIG_DFL);
    sleep(2);
    (void)kill(getpid(), SIGINT);
}

void fun2(int s)
{
    printf("Child process want to terminate.");
}

int main(int argc, char const *argv[])
{
    int b;
    b = fork();
    if (b < 0)
    {
        printf("Fail\n");
    }
    else if (b == 0)
    {
        (void)signal(SIGINT, fun1);
        while (1)
        {
            sleep(1);
            printf("I am %d\n", getpid());
        }
    }
    else
    {
        (void) signal(SIGCHLD,fun2);
        sleep(3);
        printf("Parent process id: %d\nchild process id is %d\n", getpid(), b);
        if (b % 2 == 0)
            (void)kill(b, SIGINT);
        sleep(3);
        printf("Parent process exist\n");
        exit(0);
    }
}
