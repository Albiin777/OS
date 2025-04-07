#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main() {
    int num_processes;
    int num_resources;
   
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
   
    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);
   
    int available[MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];
   
    printf("Enter the available resources:\n");
    for (int i = 0; i < num_resources; i++) {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }
   
    printf("Enter the maximum resource requirements for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("For process P%d: ", i);
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }
   
    printf("Enter the current resource allocation for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("For process P%d: ", i);
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
           
            if (need[i][j] < 0) {
                printf("Error: Allocation exceeds maximum for P%d, resource %d\n", i, j);
                return 1;
            }
        }
    }
   
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            work[j] = available[j];
        }
    }
   
    int finish[MAX_PROCESSES] = {0};
    int safe_sequence[MAX_PROCESSES];
    int safe_count = 0;
   
    while (safe_count < num_processes) {
        int found = 0;
       
        for (int i = 0; i < num_processes; i++) {
            if (!finish[i]) {
                int can_allocate = 1;
               
                for (int j = 0; j < num_resources; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
               
                if (can_allocate) {
                    for (int j = 0; j < num_resources; j++) {
                        work[j] += allocation[i][j];
                    }
                   
                    finish[i] = 1;
                    safe_sequence[safe_count++] = i;
                    found = 1;
                }
            }
        }
       
        if (!found) {
            printf("System is in an unsafe state (potential deadlock).\n");
           
            printf("Processes that could not be allocated resources: ");
            for (int i = 0; i < num_processes; i++) {
                if (!finish[i]) {
                    printf("P%d ", i);
                }
            }
            printf("\n");
           
            return 0;
        }
    }
   
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d", safe_sequence[i]);
        if (i < num_processes - 1) {
            printf(" ");
        }
    }
    printf("\n");
   
    return 0;
}
