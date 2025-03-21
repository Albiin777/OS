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
