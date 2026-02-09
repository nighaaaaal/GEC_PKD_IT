#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void *print_numbers(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Thread: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    // Create thread
    printf("Creating Thread...\n");
    if (pthread_create(&thread_id, NULL, print_numbers, NULL) != 0) {
        printf("Failed to create thread\n");
        return 1;
    }

    // Main process work
    for (int i = 500; i <= 504; i++) {
        printf("Main: %d\n", i);
        sleep(1);
    }

    // Wait for thread to finish
    pthread_join(thread_id, NULL);
    printf("Thread finished execution.\n");

    return 0;
}
