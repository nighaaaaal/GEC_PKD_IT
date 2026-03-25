#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, max_disk, total_seek = 0;

    printf("Enter max disk size: ");
    scanf("%d", &max_disk);
    if (max_disk < 0) { printf("Invalid Input\n"); exit(0); }

    printf("Enter initial head position: ");
    scanf("%d", &head);
    if (head < 0) { printf("Invalid Input\n"); exit(0); }

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n + 3];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        if (req[i] < 0 || req[i] > max_disk) { printf("Invalid Input\n"); exit(0); }
    }
    
    // Add ends and head to the array
    req[n] = head;
    req[n+1] = max_disk; 
    req[n+2] = 0;
    n = n + 3;

    // Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                int temp = req[j]; req[j] = req[j + 1]; req[j + 1] = temp;
            }
        }
    }

    int pos;
    for (int i = 0; i < n; i++) {
        if (req[i] == head) { pos = i; break; }
    }

    // Move Right to End
    for (int i = pos; i < n; i++) {
        total_seek += abs(head - req[i]);
        head = req[i];
    }
    
    // Jump to 0 (Left End) and move Right again
    head = 0;
    total_seek += max_disk; // The movement from end back to 0
    for (int i = 1; i < pos; i++) {
        total_seek += abs(head - req[i]);
        head = req[i];
    }

    printf("Total Seek Operations (C-SCAN) = %d\n", total_seek);
    return 0;
}
