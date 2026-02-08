#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child Process
        printf("Child Process PID = %d\n", getpid());
        
        // Sleep keeps the child alive while parent dies
        sleep(10); 
        
        printf("Child wakes up (I was an orphan for a few seconds).\n");
    } 
    else {
        // Parent Process
        printf("Parent Process PID = %d\n", getpid());
        printf("Parent terminating...\n");
        exit(0); // Parent dies instantly
    }

    return 0;
}
