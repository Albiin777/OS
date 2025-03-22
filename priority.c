#include <stdio.h>

int main() {
    int n, i, temp, j;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], wt[n], tat[n], ct[n], prio[n];
    for (i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Enter Arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst time: ");
        scanf("%d", &bt[i]);
        printf("Enter Priority: ");
        scanf("%d", &prio[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = prio[j];
                prio[j] = prio[j + 1];
                prio[j + 1] = temp;
            }
        }
    }

    ct[0] = bt[0] + at[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    total_wt += wt[0];
    total_tat += tat[0];

    for (i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;

    printf("\nPROCESS\tARRIVAL TIME\tBURST TIME\tPRIORITY\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], prio[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average Turnaround time: %.2f\n", avg_tat);

    return 0;
}




#W0ORKING CODE:

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
    
    // Sort by process ID for display
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pid[j] > pid[j + 1]) {
                // Swap all arrays to keep data aligned
                int temp;
                
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
                
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                
                temp = prio[j];
                prio[j] = prio[j + 1];
                prio[j + 1] = temp;
                
                temp = ct[j];
                ct[j] = ct[j + 1];
                ct[j + 1] = temp;
                
                temp = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp;
                
                temp = tat[j];
                tat[j] = tat[j + 1];
                tat[j + 1] = temp;
            }
        }
    }
    
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
