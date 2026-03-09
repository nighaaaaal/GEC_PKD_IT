#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Array of 5 semaphores representing the 5 chopsticks
sem_t chopstick[5];

void *philosopher(void *arg) {
    int i = *(int *)arg;
    
    // Infinite loop as per the algorithm: do { ... } while(1);
    while(1) {
        printf("Philosopher %d is THINKING.\n", i);
        sleep(1); // Sleep to simulate thinking time

        printf("Philosopher %d is hungry and waiting for chopsticks.\n", i);
        
        // Pick up chopsticks
        sem_wait(&chopstick[i]);          // wait(chopstick[i])
        sem_wait(&chopstick[(i+1) % 5]);  // wait(chopstick[(i+1)%5])

        // Eating the rice
        printf("Philosopher %d is EATING THE RICE.\n", i);
        sleep(2); // Sleep to simulate eating time

        // Put down chopsticks
        sem_post(&chopstick[i]);          // signal(chopstick[i])
        sem_post(&chopstick[(i+1) % 5]);  // signal(chopstick[(i+1)%5])
        
        printf("Philosopher %d finished eating and put down chopsticks.\n", i);
    }
}

int main() {
    pthread_t tid[5];
    int phil_num[5];

    // Initialize the semaphores to 1
    for(int i = 0; i < 5; i++) {
        sem_init(&chopstick[i], 0, 1);
    }

    printf("Dining Philosophers Simulation Started (Press Ctrl+C to stop)...\n\n");

    // Create the philosopher threads
    for(int i = 0; i < 5; i++) {
        phil_num[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &phil_num[i]);
    }

    // Wait for the threads to finish (Technically unreachable due to while(1))
    for(int i = 0; i < 5; i++) {
        pthread_join(tid[i], NULL);
    }

    // Destroy semaphores
    for(int i = 0; i < 5; i++) {
        sem_destroy(&chopstick[i]);
    }

    return 0;
}
