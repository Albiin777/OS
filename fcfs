#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process[n], bt[n], at[n];
    int wt[n], tat[n], ct[n];
    
    printf("\nEnter the burst time and arrival time for each process:\n");
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &at[i]);
    }

  
     for (int i = 1; i < n ; i++) {
        for (int j = 0; j < n - i ; j++) {
            if (at[j] > at[j + 1]) {
                
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
             
                temp =bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

   for (int i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i];
        }

        ct[i] = currentTime + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        totalWaitingTime += wt[i];
        totalTurnaroundTime += tat[i];

        currentTime = ct[i];
    }

    
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], bt[i], at[i], wt[i], tat[i], ct[i]);
    }

  
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
