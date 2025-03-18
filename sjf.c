#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int process[n], burstTime[n], arrivalTime[n];
    int waitingTime[n], turnaroundTime[n], completionTime[n];
    int isCompleted[n];
    
    // Initialize all processes as not completed
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;
    }
    
    // Input burst time and arrival time for each process
    printf("\nEnter the burst time and arrival time for each process:\n");
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &arrivalTime[i]);
    }
    
    int currentTime = 0;
    int completed = 0;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    
    // Process until all processes are completed
    while (completed != n) {
        // Find the process with minimum burst time among the processes that have arrived
        int minBurstTime = __INT_MAX__;
        int selectedProcess = -1;
        
        for (int i = 0; i < n; i++) {
            // Check if the process has arrived and is not completed
            if (arrivalTime[i] <= currentTime && isCompleted[i] == 0) {
                // Select the process with minimum burst time
                if (burstTime[i] < minBurstTime) {
                    minBurstTime = burstTime[i];
                    selectedProcess = i;
                }
            }
        }
        
        // If no process is found, increment time
        if (selectedProcess == -1) {
            currentTime++;
        } else {
            // Execute the selected process
            completionTime[selectedProcess] = currentTime + burstTime[selectedProcess];
            turnaroundTime[selectedProcess] = completionTime[selectedProcess] - arrivalTime[selectedProcess];
            waitingTime[selectedProcess] = turnaroundTime[selectedProcess] - burstTime[selectedProcess];
            
            // Update statistics
            totalWaitingTime += waitingTime[selectedProcess];
            totalTurnaroundTime += turnaroundTime[selectedProcess];
            
            // Mark process as completed and update current time
            isCompleted[selectedProcess] = 1;
            currentTime = completionTime[selectedProcess];
            completed++;
        }
    }
    
    // Calculate average times
    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;
    
    // Display results
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               process[i], burstTime[i], arrivalTime[i], waitingTime[i], turnaroundTime[i], completionTime[i]);
    }
    
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    
    return 0;
}
