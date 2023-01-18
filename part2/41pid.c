#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int p;
    p = fork();
    if (p < 0)
    {
        printf("Fork Failure\n");
        exit(-1);
    }
    else if (p == 0)
    {
        printf("Executed By Child\n");
        printf("Parent Process ID is %d\n", getppid());
        printf("Child Process id is %d\n", getpid());
        // system("ps -ef | pg");
        // system("ps -x | grep z+");
    }
    else
    {
        sleep(2);
        printf("Executed by parent\n");
        printf("Parent process id is %d\n", getpid());
        printf("Child process is %d\n", p);
    }
    return 0;
}