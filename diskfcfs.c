#include <stdio.h>
#include <stdlib.h>

int main() {
int num_requests;
printf("Enter the number of disk requests: ");
scanf("%d", &num_requests);
int *requests = (int *)malloc(num_requests * sizeof(int));
if (requests == NULL) {
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}
printf("Enter the disk request sequence (separated by spaces):\n");
for (int i = 0; i < num_requests; i++) {
scanf("%d", &requests[i]);
}
int head_position;
printf("Enter the initial head position: ");
scanf("%d", &head_position);
int total_head_movement = 0;
printf("\nFCFS Disk Scheduling Simulation:\n");
printf("Request Sequence: ");

for (int i = 0; i < num_requests; i++) {
printf("%d ", requests[i]);
}
printf("\n");
printf("Head Movement:\n");
for (int i = 0; i < num_requests; i++) {
int distance = abs(requests[i] - head_position);
total_head_movement += distance;
printf("Move from %d to %d (Distance: %d)\n", head_position, requests[i], distance);
head_position = requests[i];
}
printf("\nTotal Head Movement: %d\n", total_head_movement);
free(requests);
return 0;
}
