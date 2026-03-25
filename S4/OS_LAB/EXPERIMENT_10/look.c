#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total_seek = 0;

    printf("Enter initial head position: ");
    scanf("%d", &head);
    if (head < 0) { printf("Invalid Input\n"); exit(0); }

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n + 1];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        if (req[i] < 0) { printf("Invalid Input\n"); exit(0); }
    }
    
    req[n] = head;
    n++;

    // Sort the requests
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

    // Move Right to last request (Not to the end of the disk)
    for (int i = pos; i < n; i++) {
        total_seek += abs(head - req[i]);
        head = req[i];
    }
    // Reverse and move Left to first request
    for (int i = pos - 1; i >= 0; i--) {
        total_seek += abs(head - req[i]);
        head = req[i];
    }

    printf("Total Seek Operations (LOOK) = %d\n", total_seek);
    return 0;
}
