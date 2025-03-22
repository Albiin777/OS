#include <stdio.h>
void bestfit (int f[], int b[], int nf, int nb)
{
for(int i=0; i<nf; i++)
{
int flag=0;
for(int j=0; j<nb; j++)
{
int temp = b[j]-f[i];
if(temp>=0)
{
printf("\n File size %d is put in %d partition", f[i],b[j]);
b[j]=0;
flag=1;
break;
}
}
if (flag == 0)
printf ("\n File with size %d has to wait", f[i]);
}
}
void main()
{
int nb,nf;
printf ("Enter no of memory blocks: ");
scanf ("%d", &nb);
int b[nb];
printf ("Enter no of files: ");
scanf ("%d", &nf);
int f[nf], i, j;
printf("Enter the sizes of memory blocks in order: ");
for (int i=0 ; i<nb; i++)
scanf("%d", &b[i]);
printf("Enter the sizes of files in order: ");
for (i=0; i<nf; i++)
scanf ("%d", &f[i]);
for (i=0; i<(nb-1); i++)
for (j=i+1; j<nb; j++)
if(b[j]<b[i])
{
int temp=b[j];
b[j]=b[i];
b[i] = temp;
}
bestfit(f,b,nf,nb); }




"""
#include <stdio.h>

void bestfit(int f[], int b[], int nf, int nb) {
    // Create arrays to track remaining block sizes and allocation status
    int remaining[nb];
    int allocation[nf];
    
    // Initialize remaining space in each block
    for (int i = 0; i < nb; i++) {
        remaining[i] = b[i];
    }
    
    // Initialize allocation status
    for (int i = 0; i < nf; i++) {
        allocation[i] = -1;  // -1 means not allocated
    }
    
    // Process each file
    for (int i = 0; i < nf; i++) {
        // Find the best fit block for current file
        int bestIdx = -1;
        
        for (int j = 0; j < nb; j++) {
            // If this block can fit the file
            if (remaining[j] >= f[i]) {
                // If this is the first suitable block found OR 
                // if this block is smaller than the previous best fit
                if (bestIdx == -1 || remaining[j] < remaining[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        
        // If we found a suitable block
        if (bestIdx != -1) {
            // Allocate file to this block
            allocation[i] = bestIdx;
            // Reduce available space in this block
            remaining[bestIdx] -= f[i];
            printf("\nFile size %d is allocated to block of size %d (Remaining: %d)", 
                   f[i], b[bestIdx], remaining[bestIdx]);
        } else {
            // No suitable block found
            printf("\nFile size %d cannot be allocated", f[i]);
        }
    }
    
    // Print allocation summary
    printf("\n\nAllocation Summary:");
    printf("\nFile No.\tFile Size\tBlock No.\tOriginal Block Size\tRemaining");
    for (int i = 0; i < nf; i++) {
        printf("\n%d\t\t%d\t\t", i+1, f[i]);
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t\t%d", 
                   allocation[i]+1, b[allocation[i]], remaining[allocation[i]]);
        } else {
            printf("Not Allocated");
        }
    }
}

int main() {
    int nb, nf;
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    
    printf("Enter number of files: ");
    scanf("%d", &nf);
    
    int b[nb], f[nf];
    
    printf("Enter sizes of memory blocks:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
    }
    
    printf("Enter sizes of files:\n");
    for (int i = 0; i < nf; i++) {
        scanf("%d", &f[i]);
    }
    
    // No need to sort blocks for Best Fit algorithm
    // We'll find the best fit dynamically
    
    bestfit(f, b, nf, nb);
    
    return 0;
}
