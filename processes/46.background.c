#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int p = vfork();
    if (p < 0)
    {
        printf("failure happend");
        exit(1);
    }else if(p == 0){
        sleep(10);
        system("ps");
        
    }else if(p > 0){
        printf("Child process id is : %d\n", p);
        printf("parrent proccess id is %d\n",getpid());
    }
    return 0;
}
