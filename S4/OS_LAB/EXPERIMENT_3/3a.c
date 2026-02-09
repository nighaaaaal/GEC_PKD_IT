#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int bt; // Burst Time
    int wt; // Waiting Time
    int tat; // Turnaround Time
};

int main() {
    int n;
    float total_wt = 0, total_tat = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i=0; i<n; i++) {
        p[i].pid = i;
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &p[i].bt);
        
        // Manual Output check: Invalid Input for negative numbers [cite: 530]
        if(p[i].bt < 0) {
            printf("Invalid Input\n");
            return 0;
        }
    }

    // Step 4: First process calculation
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    total_tat += p[0].tat;

    // Step 5: Loop for remaining processes
    for(int i=1; i<n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        p[i].tat = p[i].wt + p[i].bt;
        
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    // Output Table
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    // Step 6: Averages
    printf("\nAverage Waiting Time: %f", total_wt / n);
    printf("\nAverage Turnaround Time: %f\n", total_tat / n);

    return 0;
}
