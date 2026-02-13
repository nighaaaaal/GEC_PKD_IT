#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {
    key_t key = ftok("shmfile", 65);
    
    // Create shared memory
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    
    // Attach
    char *str = (char*) shmat(shmid, (void*)0, 0);
    
    printf("Write Data : ");
    fgets(str, 100, stdin); // Write to shared memory
    
    printf("Data written in memory: %s\n", str);
    
    // Detach
    shmdt(str);
    return 0;
}
