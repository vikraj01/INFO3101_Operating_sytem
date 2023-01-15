// Write a program that creates three child processes. The first child process executes the command “who”, the second child process executes the command “ls –l” and the third child process
// executes the command “date”. The parent process waits for all the child processes to finish and
// prints the termination status of the child.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;

    pid1 = fork();
    if (pid1 == 0) {
        // first child process
        execl("/usr/bin/who", "who", NULL);
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            // second child process
            execl("/bin/ls", "ls", "-l", NULL);
        } else {
            pid3 = fork();
            if (pid3 == 0) {
                // third child process
                execl("/bin/date", "date", NULL);
            } else {
                // parent process
                waitpid(pid1, &status, 0);
                printf("First child process terminated with status %d\n", status);
                waitpid(pid2, &status, 0);
                printf("Second child process terminated with status %d\n", status);
                waitpid(pid3, &status, 0);
                printf("Third child process terminated with status %d\n", status);
            }
        }
    }
    return 0;
}