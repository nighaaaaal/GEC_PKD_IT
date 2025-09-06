#include <stdio.h>
#include <stdlib.h>

// A structure for a single node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// --- Function Prototypes ---
void insertAtBeginning(struct Node** head_ref, int value);
void insertAtEnd(struct Node** head_ref, int value);
void insertAtPosition(struct Node** head_ref, int value, int position);
void deleteByValue(struct Node** head_ref, int value);
void reverseList(struct Node** head_ref);
int countElements(struct Node* head);
void displayList(struct Node* head);
void freeList(struct Node** head_ref); // For cleaning up memory

// --- Main Program ---
int main() {
    // Start with an empty list. 'head' is now a local variable.
    struct Node* head = NULL;
    int choice, value, position;

    // The main menu loop
    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at a specific position\n");
        printf("4. Display elements\n");
        printf("5. Count elements\n");
        printf("6. Reverse the list\n");
        printf("7. Delete by value\n");
        printf("8. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter the value and position: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Total number of elements: %d\n", countElements(head));
                break;
            case 6:
                reverseList(&head);
                break;
            case 7:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteByValue(&head, value);
                break;
            case 8:
                printf("Freeing all list memory before exiting...\n");
                freeList(&head);
                printf("Exiting program. Goodbye! 👋\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// --- Function Implementations ---

/**
 * @brief Frees all nodes in the list to prevent memory leaks.
 */
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next_node;
    while (current != NULL) {
        next_node = current->next; // Save the next node
        free(current);             // Free the current node
        current = next_node;       // Move to the next one
    }
    *head_ref = NULL; // Mark the list as empty
}

/**
 * @brief Inserts a new node at the beginning of the list.
 */
void insertAtBeginning(struct Node** head_ref, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = value;
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("Inserted %d at the beginning.\n", value);
}

/**
 * @brief Inserts a new node at the end of the list.
 */
void insertAtEnd(struct Node** head_ref, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node* last = *head_ref;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
    printf("Inserted %d at the end.\n", value);
}

/**
 * @brief Inserts a new node at a specific position (1-based index).
 */
void insertAtPosition(struct Node** head_ref, int value, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head_ref, value);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = value;

    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(new_node); // Free the unused node
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    printf("Inserted %d at position %d.\n", value, position);
}

/**
 * @brief Deletes the first node containing the given value.
 */
void deleteByValue(struct Node** head_ref, int value) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head_ref = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

/**
 * @brief Reverses the entire linked list.
 */
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    printf("The linked list has been reversed.\n");
}

/**
 * @brief Counts the total number of elements in the list.
 */
int countElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

/**
 * @brief Displays all elements in the linked list.
 */
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}