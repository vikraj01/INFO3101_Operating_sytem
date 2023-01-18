#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int g = 100;
int main()
{
    int l = 50;
    int p;
    p = fork();
    if(p<0){
        printf("Fork failure\n");
        exit(-1);
    }
    else if(p == 0){
        for(int i=0;i<5;i++){
            system("ps -ef");
            sleep(5);
        }
    }
    return 0;
}