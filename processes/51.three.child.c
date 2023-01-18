#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int x, y, t;
    x = fork();
    if (x < 0)
    {
        printf("Fork Failure\n");
        exit(-1);
    }
    else if (x == 0)
    {
        system(" Date +\"%d\" ");
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
            system(" echo Hello");
        }
        else if (y > 0)
        {
            t = fork();
            if (t < 0)
            {
                printf("Fork Failure\n");
                exit(-1);
            }
            else if (t == 0)
            {
                system("ls -l");
            }
            wait(NULL);
            printf("Good Bye");
        }
    }
    return 0;
}
