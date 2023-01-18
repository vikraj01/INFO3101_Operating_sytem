#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler1(int s)
{
    printf("Parents wants to terminate Child Proccess...\n");
    (void)signal(SIGINT, SIG_DFL);
    sleep(2);
    (void)kill(getpid(), SIGINT);
}

void handler2(int s)
{
    printf("Child Proccess is terminated\n");
}

int main(int argc, char const *argv[])
{
    int p;
    p = fork();
    if (p < 0)
    {
        exit(-1);
    }
    else if (p == 0)
    {
        (void) signal(SIGINT, handler1);
        while (1)
        {
            sleep(1);
            printf("I am %d\n",getpid());
        }
        
    } else{
        (void ) signal(SIGCHLD, handler2);
        sleep(3);
        printf("Parent Procees id : %d , child proccess id is %d\n", getpid(), p);
        if(p%2 == 0) (void)  kill(p,SIGINT);
        sleep(5);
        printf("Parent Process exit\n");
    }
    return 0;
}
