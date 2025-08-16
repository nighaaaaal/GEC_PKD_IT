#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Structure definition for the stack
typedef struct{
    int *collection;
    int capacity;
    int size;
} STACK;

// Function prototypes
STACK *create_stack(int capacity);
void destroy_stack(STACK *stack);
bool is_full(STACK *stack);
bool is_empty(STACK *stack);
bool pop(STACK *stack, int *item);
bool push(STACK *stack, int item);
bool peek(STACK *stack, int *item);

int main(){
    int capacity;
    printf("Enter the desired capacity of the stack: ");
    scanf("%d", &capacity);

    // Create the stack with the user-defined capacity
    STACK *stack = create_stack(capacity);

    // Check if stack creation was successful
    if(stack == NULL){
        printf("Error: Could not create the stack. Invalid capacity or memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    printf("Stack created with a capacity of %d.\n", capacity);

    while(1){
        int choice;
        // MODIFIED: Simplified the menu
        printf("\n--- STACK MENU ---\n");
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Peek at top item\n");
        printf("4. Exit\n"); // Changed
        printf("------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: { // Push
                int item;
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                
                if(push(stack, item)){
                    printf("Pushed %d to the stack. Current size: %d\n", item, stack->size);
                } else {
                    printf("Error: Stack is full. Could not push %d.\n", item);
                }
                break;
            }
            case 2: { // Pop
                int popped_item;
                if(pop(stack, &popped_item)){
                    printf("Popped item: %d. Current size: %d\n", popped_item, stack->size);
                } else {
                    printf("Error: Stack is empty. Nothing to pop.\n");
                }
                break;
            }
            case 3: { // Peek
                int peeked_item;
                if(peek(stack, &peeked_item)){
                    printf("Item at the top of the stack is: %d\n", peeked_item);
                } else {
                    printf("Error: Stack is empty. Nothing to peek.\n");
                }
                break;
            }
            case 4: { // Exit
                // MODIFIED: Changed the output message
                printf("Deleted stack to avoid memory leak and exiting.\n");
                destroy_stack(stack);
                return 0; // Exit the program
            }
            default: {
                // MODIFIED: Updated the valid range
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
            }
        }
    }
    return 0;
}

// Creates and initializes a stack
STACK *create_stack(int capacity){
    if(capacity <= 0) return NULL;

    STACK *stack = malloc(sizeof(STACK));
    if(stack == NULL) return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if(stack->collection == NULL){
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;
    return stack;
}

// Frees all memory used by the stack
void destroy_stack(STACK *stack){
    if(stack != NULL){
        free(stack->collection);
        free(stack);
    }
}

// Checks if the stack is full
bool is_full(STACK *stack){
    return stack->size == stack->capacity;
}

// Checks if the stack is empty
bool is_empty(STACK *stack){
    return stack->size == 0; 
}

// Adds an item to the top of the stack
bool push(STACK *stack, int item){
    if(is_full(stack)) return false;

    stack->collection[stack->size] = item;
    stack->size++;
    return true;
}

// Removes an item from the top of the stack
bool pop(STACK *stack, int *item){
    if(is_empty(stack)) return false;

    stack->size--;
    *item = stack->collection[stack->size];
    return true;
}

// Looks at the top item without removing it
bool peek(STACK *stack, int *item){
    if(is_empty(stack)) return false;

    *item = stack->collection[stack->size - 1];
    return true;
}