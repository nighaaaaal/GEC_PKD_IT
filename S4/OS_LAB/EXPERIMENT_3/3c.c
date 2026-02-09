#include <stdio.h>
#include <stdlib.h> // Required for exit()

struct Process {
    int pid;
    int bt;  // Burst Time
    int pri; // Priority
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};

int main() {
    int n;
    struct Process temp;
    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    struct Process p[n];

    // Input Loop
    for (int i = 0; i < n; i++) {
        p[i].pid = i;
        printf("Enter Burst Time and Priority Number of Process %d:\n", i);
        scanf("%d %d", &p[i].bt, &p[i].pri);

        // ERROR CHECKING:
        // If Burst Time OR Priority is negative, stop immediately.
        if (p[i].bt < 0 || p[i].pri < 0) {
            printf("Invalid Input\n");
            exit(0); // Terminate the program strictly as per manual
        }
    }

    // Sort by Priority (Bubble Sort)
    // Assumption: Lower number = Higher Priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].pri > p[j + 1].pri) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculation
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    total_tat += p[0].tat;

    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
        
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    // Output Table
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].pri, p[i].wt, p[i].tat);
    }

    // Averages
    printf("\nAverage Waiting Time -- %f", total_wt / n);
    printf("\nAverage Turnaround Time -- %f\n", total_tat / n);

    return 0;
}
