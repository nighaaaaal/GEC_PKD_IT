#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t cpid;
    
    if (fork() == 0) {
        // Child Process
        printf("Child Process starts. PID = %d\n", getpid());
        sleep(2); // Simulate doing some work
        printf("Child Process finishing.\n");
        exit(0);
    } 
    else {
        // Parent Process
        printf("Parent Process starts. PID = %d\n", getpid());
        
        // Wait for the child to finish
        cpid = wait(NULL); 
        
        printf("Parent resumed. Finished Child PID = %d\n", cpid);
    }

    printf("Parent Terminated.\n");
    return 0;
}
