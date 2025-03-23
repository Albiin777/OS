#include <stdio.h>

int main() {
    int n, i, j, time = 0, completed = 0;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int pid[n], at[n], bt[n], wt[n], tat[n], ct[n], prio[n], remaining_bt[n], is_completed[n];
    
    // Input process details
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        pid[i] = i + 1;  // Store process ID
        printf("Enter Arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst time: ");
        scanf("%d", &bt[i]);
        printf("Enter Priority (lower value means higher priority): ");
        scanf("%d", &prio[i]);
        remaining_bt[i] = bt[i];
        is_completed[i] = 0;
    }
    
    // Perform priority scheduling
    while (completed != n) {
        int highest_priority = -1;
        int selected_process = -1;
        
        // Find process with highest priority among arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= time && is_completed[i] == 0) {
                if (highest_priority == -1 || prio[i] < prio[highest_priority]) {
                    highest_priority = i;
                    selected_process = i;
                }
                // If two processes have the same priority, select the one that arrived first
                else if (prio[i] == prio[highest_priority] && at[i] < at[highest_priority]) {
                    highest_priority = i;
                    selected_process = i;
                }
            }
        }
        
        if (selected_process == -1) {
            // No process is available, advance time to next arrival
            time++;
        } else {
            // Execute the selected process until completion
            time += remaining_bt[selected_process];
            ct[selected_process] = time;
            tat[selected_process] = ct[selected_process] - at[selected_process];
            wt[selected_process] = tat[selected_process] - bt[selected_process];
            
            total_tat += tat[selected_process];
            total_wt += wt[selected_process];
            
            is_completed[selected_process] = 1;
            completed++;
        }
    }
    
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;
    
    
    // Display results
    printf("\nPROCESS\tARRIVAL TIME\tBURST TIME\tPRIORITY\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               pid[i], at[i], bt[i], prio[i], ct[i], wt[i], tat[i]);
    }
    
    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average Turnaround time: %.2f\n", avg_tat);
    
    return 0;
}
