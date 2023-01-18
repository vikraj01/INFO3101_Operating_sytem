#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int p = fork();
    if (p < 0)
    {
        printf("failure happend");
        exit(1);
    }else if(p == 0){
        printf("Child process\n");
        // getpid() will return process id of child process
        printf("ID: %d\n", getpid());
        // getppid() will return parent process id of child process
        printf("Parent -ID: %d\n\n", getppid());

        sleep(2);

        // At this time parent process has finished.
        // So if u will check parent process id
        // it will show different process id
        printf("\nChild process \n");
        printf("ID: %d\n", getpid());
        printf("Parent -ID: %d\n", getppid());
    }else if(p > 0){
        printf("Child process id is : %d\n", p);
        printf("parrent proccess id is %d\n",getpid());
    }
    return 0;
}
