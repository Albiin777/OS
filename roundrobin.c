#include <stdio.h>

int main() {
    int n, i, tq, total_wt = 0, total_tat = 0, totalpc = 0;
    float avg_tat, avg_wt;
    
    printf("Enter Number of processes: ");
    scanf("%d", &n);
    
    int at[n], bt[n], wt[n], ret[n], tat[n], ct[n];
    
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Enter Arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst time: ");
        scanf("%d", &bt[i]);
        ret[i] = bt[i];  // Remaining time initialized to burst time
        wt[i] = 0;       // Initialize waiting time to zero
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    
    int current_time = 0;
    
    while (totalpc < n) {
        int done = 1; // Check if all processes are completed
        
        for (i = 0; i < n; i++) {
            if (ret[i] > 0 && at[i] <= current_time) {
                done = 0;  // At least one process is still running
                
                if (ret[i] <= tq) {
                    current_time += ret[i];
                    ct[i] = current_time; // Store Completion Time
                    tat[i] = ct[i] - at[i]; // Turnaround Time
                    wt[i] = tat[i] - bt[i]; // Waiting Time
                    
                    total_tat += tat[i];
                    total_wt += wt[i];
                    
                    ret[i] = 0; // Process is completed
                    totalpc++; 
                } else {
                    current_time += tq;
                    ret[i] -= tq;
                }
            }
        }
        
        if (done) break; // Exit if all processes are completed
    }
    
    avg_tat = (float) total_tat / n;
    avg_wt = (float) total_wt / n;
    
    // Printing results
    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);
    
    return 0;
}
