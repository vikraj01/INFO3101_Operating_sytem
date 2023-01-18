#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fun1(int s)
{
    printf("Signal no. %d occured\n", s);
}

void fun2(int s)
{
    printf("Signal no. %d occured\n", s);
    signal(SIGINT, SIG_DFL);
    kill(getpid(), SIGINT);
}

int main(int argc, char const *argv[])

{
    signal(SIGCHLD, fun1);
    int p = fork();
    if (p == 0)
    {
        signal(SIGINT, fun2);
        while (1)
        {
            printf("Child proccess\n");
            sleep(1);
        }
    }
    else if (p > 0)
    {
        sleep(5);
        kill(p, SIGINT);
        printf("BYE\n");
    }
    return 0;
}
