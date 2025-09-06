#include <stdio.h>

// Define the maximum size of the queue
#define N 5

// Global variables
int queue[N];
int front = -1;
int rear = -1;

// Function to add an element to the queue (enqueue)
void enqueue() {
    int item;

    // Condition to check if the queue is full
    if (rear == N - 1) {
        printf("\nQueue is full! OVERFLOW\n");
        return;
    }
    
    printf("Enter the element to insert: ");
    scanf("%d", &item);

    // If the queue is empty, initialize front
    if (front == -1) {
        front = 0;
    }
    
    // Increment rear and insert the item
    rear = rear + 1;
    queue[rear] = item;
    
    printf("\n%d was enqueued successfully.\n", item);
}

// Function to remove an element from the queue (dequeue)
void dequeue() {
    // Condition to check if the queue is empty
    // front > rear means all elements have been dequeued
    if (front == -1 || front > rear) {
        printf("\nQueue is empty! UNDERFLOW\n");
        // Optional: Reset pointers if queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
        return;
    }

    printf("\n%d was dequeued from the queue.\n", queue[front]);

    // Increment front to remove the element
    front = front + 1;
}

// Function to display all elements in the queue
void display() {
    // Condition to check if the queue is empty
    if (front == -1 || front > rear) {
        printf("\nQueue is empty. Nothing to display.\n");
        return;
    }
    
    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function with a menu-driven interface
int main() {
    int choice;
    do {
        printf("\n--- SIMPLE QUEUE MENU ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}