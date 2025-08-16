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
        // Added Peek and corrected the menu formatting
        printf("\n--- STACK MENU ---\n");
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Peek at top item\n");
        printf("4. Destroy entire stack and exit\n");
        printf("5. Exit\n");
        printf("------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: { // Push
                int item;
                printf("Enter the item to be pushed: ");
                scanf("%d", &item);
                
                // Try to push the item and check if it was successful
                if(push(stack, item)){
                    printf("Pushed %d to the stack. Current size: %d\n", item, stack->size);
                } else {
                    printf("Error: Stack is full. Could not push %d.\n", item);
                }
                break;
            }
            case 2: { // Pop
                int popped_item;
                // Try to pop the item and check if it was successful
                if(pop(stack, &popped_item)){ // Pass the address of the variable
                    printf("Popped item: %d. Current size: %d\n", popped_item, stack->size);
                } else {
                    printf("Error: Stack is empty. Nothing to pop.\n");
                }
                break;
            }
            case 3: { // Peek
                int peeked_item;
                // Try to peek and check if it was successful
                if(peek(stack, &peeked_item)){
                    printf("Item at the top of the stack is: %d\n", peeked_item);
                } else {
                    printf("Error: Stack is empty. Nothing to peek.\n");
                }
                break;
            }
            case 4: { // Destroy and Exit
                printf("Destroying the stack and exiting.\n");
                destroy_stack(stack);
                return 0; // Exit the program
            }
            case 5: { // Exit
                printf("Exiting without destroying the stack (Note: this will cause a memory leak).\n");
                // In a real application, you'd want to ensure cleanup happens.
                // For this example, we show the difference from choice 4.
                return 0;
            }
            default: {
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
            }
        }
    }

    // This part is now unreachable due to the exit conditions in the loop,
    // but it's good practice to have a final cleanup.
    destroy_stack(stack);
    return 0;
}

// Creates and initializes a stack
STACK *create_stack(int capacity){
    if(capacity <= 0) return NULL;

    STACK *stack = malloc(sizeof(STACK));
    if(stack == NULL) return NULL;

    stack->collection = malloc(sizeof(int) * capacity);
    if(stack->collection == NULL){
        free(stack); // Clean up the allocated stack structure if collection fails
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0; // The stack starts empty
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
    stack->size++; // CORRECTED: Increment size *before* returning
    return true;
}

// Removes an item from the top of the stack
bool pop(STACK *stack, int *item){
    if(is_empty(stack)) return false;

    stack->size--; // CORRECTED: Decrement size *first*
    *item = stack->collection[stack->size]; // Get the item at the new top index
    return true;
}

// Looks at the top item without removing it
bool peek(STACK *stack, int *item){
    if(is_empty(stack)) return false;

    // We look at the item at index size - 1
    *item = stack->collection[stack->size - 1];
    return true;
}