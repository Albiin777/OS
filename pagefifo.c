#include<stdio.h>
#include<stdlib.h>

typedef struct{
int p_no;
int valid;
}pageframe;

void main(){
int nf,np;
printf("Enter number of pages:");
scanf("%d",&np);
printf("Enter number of page frames:");
scanf("%d",&nf);
pageframe *frames = (pageframe *)malloc(nf * sizeof(pageframe));
if(frames==NULL){
perror("Memory allocation failed");
exit(EXIT_FAILURE);}

for(int i=0;i<nf;i++){
frames[i].valid=0;
frames[i].p_no=-1;}

int *pages = (int *)malloc(nf * sizeof(int));
if(pages==NULL){
perror("Memory allocation failed");
exit(EXIT_FAILURE);}

printf("Enter the page reference string:\n");
for(int i=0;i<np;i++){
scanf("%d",&pages[i]);}

int page_faults=0;
int fifo_index=0;
printf("Page Allocation: FIFO\n");
for(int i=0;i<np;i++){
int current_page = pages[i];
int page_hit = 0;
printf("Referencing page %d: ", current_page);
for (int j = 0; j < nf; j++) {
if (frames[j].valid && frames[j].p_no == current_page) {
page_hit = 1;
break;}
}
if (page_hit) {
printf("Page Hit\n");
}
else {
printf("Page Fault - Replacing page %d\n", frames[fifo_index].p_no);
page_faults++;
frames[fifo_index].p_no = current_page;
frames[fifo_index].valid = 1;
fifo_index = (fifo_index + 1) % nf;
}
printf("Frames: ");
for (int j = 0; j < nf; j++) {
if (frames[j].valid) {
printf("%d ", frames[j].p_no);
} else {
printf("- ");
}
}
printf("\n");
}
printf("\nTotal Page Faults: %d\n", page_faults);
free(frames);
free(pages);
}
