#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // Required for sleep()

#define BUFFER_SIZE 5

sem_t empty;
sem_t full;
pthread_mutex_t mutex;
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

void *producer(void *arg) {
    int item;
    // Infinite loop for continuous production
    while(1) {
        item = rand() % 100; // Produce random item
        
        sem_wait(&empty); // Wait for empty slot
        pthread_mutex_lock(&mutex); // Enter Critical Section
        
        // Critical Section: Add item to buffer
        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        
        pthread_mutex_unlock(&mutex); // Exit Critical Section
        sem_post(&full); // Signal that a slot is full
        
        sleep(1); // Sleep for 1 second to make output readable
    }
}

void *consumer(void *arg) {
    int item;
    // Infinite loop for continuous consumption
    while(1) {
        sem_wait(&full); // Wait for filled slot
        pthread_mutex_lock(&mutex); // Enter Critical Section
        
        // Critical Section: Remove item from buffer
        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        
        pthread_mutex_unlock(&mutex); // Exit Critical Section
        sem_post(&empty); // Signal that a slot is empty
        
        sleep(1); // Sleep for 1 second to make output readable
    }
}

int main() {
    pthread_t prod_tid, cons_tid;
    
    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    
    printf("Producer-Consumer Simulation Started (Press Ctrl+C to stop)...\n");

    // Create threads
    pthread_create(&prod_tid, NULL, producer, NULL);
    pthread_create(&cons_tid, NULL, consumer, NULL);
    
    // Wait for threads (Technically unreachable due to while(1))
    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);
    
    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
