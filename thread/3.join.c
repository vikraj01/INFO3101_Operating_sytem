#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>



void * th_body(void *a){
    int n = *((int*)a);
    for(int i = 0; i <= n ; i++){
        if(i%2 == 0){
            printf("\nThread 1 even %d\n",i);
            sleep(1);
        }
    }
    return ("Thread1 done");
}

void * th2_body(void * a){
    int n = *((int *)a);
    for(int i = 0; i <= n ; i++){
        if(i%2 > 0){
            printf("\nThread 1 odd %d\n",i);
            sleep(1);
        }
    }
    return ("Thread2 done");
}


int main(){
    pthread_t th, th2;
    int ch , *a;
    void * arg , * arg2;
    char * msg = "Thread program..";
    printf("number dal: ");
    scanf("%d",a);
    ch = pthread_create(&th, NULL, th_body, (void*)a);
    if( ch != 0){
        printf("Creation failed\n");
        exit(0);
    }

    int t = pthread_create(&th2, NULL, th2_body, (void*)a);

    if(t != 0){
        printf("Creation failed\n");
        exit(0);
    }
    printf("\nWaiting for thread\n");


    ch = pthread_join(th, &arg);
    t = pthread_join(th2, &arg2);
    printf("\nReturned value %s %s\n", (char*)arg, (char*)arg2);
    return 0;
}