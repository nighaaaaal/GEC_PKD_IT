#include <stdio.h>
#include <stdlib.h>

// A structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// --- Function Prototypes ---
void insertNode(struct Node** head_ref);
void displayList(struct Node* node);
void freeList(struct Node** head_ref); // Prototype for the new function

// --- Main Program ---
int main() {
    // Start with an empty list
    struct Node* head = NULL; 
    int choice;

    // The main menu loop continues until the user chooses to exit
    while (1) {
        printf("\n--- Simple Linked List Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Display the list\n");
        printf("3. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertNode(&head); // Pass the address of the head pointer
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                freeList(&head); // Free all allocated memory
                printf("All memory freed. Exiting program. Goodbye! 👋\n");
                exit(0); // Terminate the program
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}

/**
 * @brief Inserts a new node at the beginning of the linked list.
 * @param head_ref A pointer to the head pointer of the list.
 */
void insertNode(struct Node** head_ref) {
    int data;
    printf("\nEnter the number to insert: ");
    scanf("%d", &data);

    // 1. Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    // 2. Assign data and link it to the list
    new_node->data = data;
    new_node->next = (*head_ref);

    // 3. Move the head to point to the new node
    (*head_ref) = new_node;

    printf("%d has been inserted successfully.\n", data);
}

/**
 * @brief Displays all the elements in the linked list.
 * @param node The head node of the list to be displayed.
 */
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("\nThe list is empty. 🙁\n");
        return;
    }

    printf("\n--- Linked List Elements ---\n");
    struct Node* current = node;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("--------------------------\n");
}

/**
 * @brief Frees all the nodes in the linked list to prevent memory leaks.
 * @param head_ref A pointer to the head pointer of the list.
 */
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref; // Start at the current head
    struct Node* next_node;

    // Traverse the list
    while (current != NULL) {
        next_node = current->next; // Save a pointer to the *next* node
        free(current);             // Free the *current* node's memory
        current = next_node;       // Move to the next node to continue
    }

    // Finally, set the original head pointer in main() to NULL.
    // This is good practice to prevent using a dangling pointer.
    *head_ref = NULL;
}