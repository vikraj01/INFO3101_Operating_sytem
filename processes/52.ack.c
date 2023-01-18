#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int n;
    int p = fork();
    if (p < 0)
    {
        printf("failure happend");
        exit(1);
    }else if(p == 0){
        wait(&n);
        printf("Child process id is : %d\n", getpid());
        printf("Parent process id is %d\n",getppid());
    }else if(p > 0){
        printf("Child process id is : %d\n", p);
        printf("parrent proccess id is %d\n",getpid());
        int x ;
        wait(&x);
        printf("Good work child , worth the wait %d %d",x, n);

    }
    return 0;
}
