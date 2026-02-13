#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);
    
    // Open shared memory
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    
    // Attach
    char *str = (char*) shmat(shmid, (void*)0, 0);
    
    printf("Data read from memory: %s\n", str);
    
    // Detach
    shmdt(str);
    
    // Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
// Note: Create a dummy file named 'shmfile' before running.
