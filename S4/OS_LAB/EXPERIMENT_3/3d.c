#include <stdio.h>

struct Process {
    int pid;
    int bt;
    int rem_bt; // Remaining Burst Time
    int wt;
    int tat;
};

int main() {
    int n, qt;
    int count = 0; // Completed process count
    int total_time = 0; // Global time tracker
    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes\n");
    scanf("%d", &n);
    
    struct Process p[n];

    for(int i=0; i<n; i++) {
        p[i].pid = i + 1; // Manual uses P1, P2 etc.
        printf("Enter the burst time of the process%d ", i+1);
        scanf("%d", &p[i].bt);
        
        // Manual Output check: Invalid Input [cite: 690]
        if(p[i].bt < 0) {
            printf("Invalid Input\n");
            return 0;
        }
        p[i].rem_bt = p[i].bt;
    }

    printf("Enter the quantum time\n");
    scanf("%d", &qt);

    // Step 6: Infinite Loop
    while(1) {
        count = 0; // Reset completed count for this pass check
        
        for(int i=0; i<n; i++) {
            if(p[i].rem_bt == 0) {
                count++;
                continue;
            }

            int exec_time;
            
            if(p[i].rem_bt > qt) {
                exec_time = qt;
                p[i].rem_bt -= qt;
            } else {
                exec_time = p[i].rem_bt;
                p[i].rem_bt = 0;
            }
            
            total_time += exec_time;
            
            // If process just finished, set TAT
            if(p[i].rem_bt == 0) {
                p[i].tat = total_time;
            }
        }
        
        // Step 6.3: Check if all finished
        if(count == n) break;
    }

    // Step 7: Calculate Waiting Time
    printf("\nProcess\tburst time\twaiting time\tturnaround time\n");
    for(int i=0; i<n; i++) {
        p[i].wt = p[i].tat - p[i].bt;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\nAverage waiting time = %f", total_wt / n);
    printf("\nAverage turn around time = %f\n", total_tat / n);

    return 0;
}
