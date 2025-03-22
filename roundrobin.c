#include<stdio.h>

int q[100];
int f = -1;
int r = -1;

void insert(int n)
{
    if (f == -1)
        f = 0;
    r = r + 1;
    q[r] = n;
}

int delete()
{
    int n;
    n = q[f];
    f = f + 1;
    return n;
}

void main()
{
    int p, tq, n, i, t = 0;
    float twt = 0, ttat = 0;
    printf("\nEnter how many processes: ");
    scanf("%d", &n);

    int a[n][6], bt[10], exist[10] = {0};    
    printf("\nEnter arrival time & burst time of each process:");
    for (i = 0; i < n; i++)
    {
        printf("\nProcess ID: ");
        scanf("%d", &a[i][0]);
        printf("\nA.T of process %d: ", a[i][0]);
        scanf("%d", &a[i][1]);
        printf("\nB.T of process %d: ", a[i][0]);
        scanf("%d", &a[i][2]);
        bt[i] = a[i][2];
        a[i][3] = 0;  
        a[i][4] = 0;  
        a[i][5] = 0;    
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &tq);
    insert(0);
    exist[0] = 1;

    while (f <= r)
    {
        p = delete();
        if (a[p][2] >= tq)
        {
            a[p][2] -= tq;
            t += tq;
        }
        else
        {
            t += a[p][2];
            a[p][2] = 0;
        }

        for (i = 0; i < n; i++) {
            if (exist[i] == 0 && a[i][1] <= t)
            {
                insert(i);
                exist[i] = 1;
            }
        }

        if (a[p][2] == 0)
        {
            a[p][4] = t - a[p][1];  
            a[p][5] = a[p][4] - bt[p];  
            a[p][3] = t;  
            ttat += a[p][4];
            twt += a[p][5];
        }
        else
        {
            insert(p);
        }
    }

    printf("\nP.No.\tAT\tBT\tTAT\tWT\tCT");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", a[i][0], a[i][1], bt[i], a[i][4], a[i][5], a[i][3]);
    }

    printf("\nAverage Turnaround time = %f", ttat / n);
    printf("\nAverage Waiting time = %f", twt / n);
}














#RECORD CODE:

#include <stdio.h>
int main()
{
int n, i, j, time_quantum, total_waiting_time = 0, total_turnaround_time = 0,
total_processes_completed = 0;
float avg_turnaround_time, avg_waiting_time;
printf("Enter the number of processes: ");
scanf("%d", &n);
int burst_time[n], arrival_time[n], remaining_time[n], waiting_time[n],
turnaround_time[n];
printf("Enter the burst time and arrival time for each process:\n");
for (i = 0; i < n; i++) {
    printf("Burst time for process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
    printf("Arrival time for process %d: ", i + 1);
    scanf("%d", &arrival_time[i]);
    remaining_time[i] = burst_time[i];
    }
printf("Enter the time quantum: ");
scanf("%d", &time_quantum);
int current_time = 0;
while (total_processes_completed < n) {
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && arrival_time[i] <= current_time) {
                if (remaining_time[i] <= time_quantum) {
                    current_time += remaining_time[i];
                    turnaround_time[i] = current_time - arrival_time[i];
                    total_turnaround_time += turnaround_time[i];
                    remaining_time[i] = 0;
                    total_waiting_time += turnaround_time[i] - burst_time[i];
                    total_processes_completed++;
                    } 
                else {
                    current_time += time_quantum;
                    remaining_time[i] -= time_quantum;
                    }
            }
            }
    }
avg_turnaround_time = (float)total_turnaround_time / n;
avg_waiting_time = (float)total_waiting_time / n;
printf("\nProcess\tBurst Time\tArrival Time\tTurnaround Time\tWaiting Time\n");
for (i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], arrival_time[i],turnaround_time[i], turnaround_time[i] - burst_time[i]);}
printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
printf("Average Waiting Time: %.2f\n", avg_waiting_time);
return 0;
}
