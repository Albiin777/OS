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
