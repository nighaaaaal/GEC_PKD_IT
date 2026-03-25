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

    int request[n], visited[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
        if (request[i] < 0) { printf("Invalid Input\n"); exit(0); }
        visited[i] = 0; // Initialize all as unvisited
    }

    for (int i = 0; i < n; i++) {
        int min_dist = 999999;
        int next_idx = -1;

        // Find the shortest distance from the current head
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(head - request[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    next_idx = j;
                }
            }
        }

        // Update seek, move head, and mark as visited
        visited[next_idx] = 1;
        total_seek += min_dist;
        head = request[next_idx];
    }

    printf("Total Seek Operations (SSTF) = %d\n", total_seek);
    return 0;
}
