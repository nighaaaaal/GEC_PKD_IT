#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, head, total_seek = 0;

    printf("Enter initial head position: ");
    scanf("%d", &head);
    if (head < 0) { printf("Invalid Input\n"); exit(0); }

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
        if (request[i] < 0) { printf("Invalid Input\n"); exit(0); }
    }

    for (int i = 0; i < n; i++) {
        total_seek += abs(head - request[i]);
        head = request[i]; // New head position
    }

    printf("Total Seek Operations (FCFS) = %d\n", total_seek);
    return 0;
}
