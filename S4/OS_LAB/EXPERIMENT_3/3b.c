#include <stdio.h>

struct Process {
    int pid;
    int bt;
    int wt;
    int tat;
};

int main() {
    int n;
    struct Process temp;
    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Step 3: Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i;
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &p[i].bt);

        // Manual Output check: Invalid Input [cite: 577]
        if (p[i].bt < 0) {
            printf("Invalid Input\n");
            return 0;
        }
    }

    // Step 4: Sort by Burst Time (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].bt > p[j + 1].bt) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Step 5 & 6: Calculation
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    total_tat += p[0].tat;

    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
        p[i].tat = p[i].wt + p[i].bt;
        
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    // Output
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    // Step 7: Averages
    printf("\nAverage Waiting Time -- %f", total_wt / n);
    printf("\nAverage Turnaround Time -- %f\n", total_tat / n);

    return 0;
}
