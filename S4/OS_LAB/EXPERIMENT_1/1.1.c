#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int var = 5;

    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        // Child Process Block
        var = var + 1;
        printf("I am a Child Process\n");
        printf("var = %d\n", var);
        printf("PID of Child Process: %d\n", getpid());
    } 
    else {
        // Parent Process Block
        var = var + 5;
        printf("I am a Parent Process\n");
        printf("var = %d\n", var);
        printf("PID of Parent Process: %d\n", getpid());
    }

    return 0;
}
