#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2];
    pid_t pid;
    char write_msg[] = "Hello from Parent!";
    char read_msg[100];

    // Step 3: Create Pipe
    if (pipe(fd) == -1) {
        printf("Pipe Failed\n");
        return 1;
    }

    // Step 4: Fork
    pid = fork();

    if (pid < 0) {
        printf("Fork Failed\n");
        return 1;
    }

    if (pid > 0) {
        // Parent Process (Step 5)
        close(fd[0]); // Close read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]); // Close write end
    } 
    else {
        // Child Process (Step 6)
        close(fd[1]); // Close write end
        read(fd[0], read_msg, 100);
        
        // Step 7: Print
        printf("Child received: %s\n", read_msg);
        close(fd[0]); // Close read end
    }

    return 0;
}
