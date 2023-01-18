#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int g = 100;
int main()
{
    int l = 1;
    int pid = fork();
    if (pid == 0)
    {
        g++;
        l++;
    }
    else if (pid < 0)
    {
        printf("Failed to create child process");
    }
    printf("g = %d l = %d Process Id : %d \n", g, l, getpid());

    return 0;
}
