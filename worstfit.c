#include <stdio.h>
#define max 25

void worstfit(int b[], int f[], int nb, int nf)
{
    int i, j, k = 0, temp, highest, flag;
    for (i = 0; i < nf; i++) {
        highest = -1;
        flag = 0;
        for (j = 0; j < nb; j++) {
            temp = b[j] - f[i];
            if (temp >= 0) {
                if (highest < temp) {
                    k = j;
                    highest = temp;
                }
                flag = 1;
            }
        }
        if (flag == 1) {
            printf("\nFile Size %d is put in Block of size %d", f[i], b[k]);
            b[k] = 0; // Mark the block as used
        } else {
            printf("\nFile Size %d must wait", f[i]);
        }
    }
}

void main()
{
    int i, nb, nf;
    int b[max], f[max];
   
    printf("Memory Management Scheme - Worst Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);
   
    printf("Enter the size of the blocks:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }
   
    printf("Enter the size of the files:\n");
    for (i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }
   
    worstfit(b, f, nb, nf);
}






"""
#include <stdio.h>
#define MAX 25

void worstfit(int b[], int f[], int nb, int nf) {
    // Create arrays to track remaining block sizes and allocation status
    int remaining[MAX];
    int allocation[MAX];
    
    // Initialize remaining space in each block
    for (int i = 0; i < nb; i++) {
        remaining[i] = b[i];
    }
    
    // Initialize allocation status for each file
    for (int i = 0; i < nf; i++) {
        allocation[i] = -1;  // -1 means not allocated
    }
    
    // Process each file
    for (int i = 0; i < nf; i++) {
        int worstIdx = -1;
        int worstRemainder = -1;
        
        // Find the worst fit block for current file
        for (int j = 0; j < nb; j++) {
            // If this block can fit the file
            if (remaining[j] >= f[i]) {
                // Calculate remaining space after potential allocation
                int remainder = remaining[j] - f[i];
                
                // If this leaves more space than previous worst fit
                if (remainder > worstRemainder) {
                    worstRemainder = remainder;
                    worstIdx = j;
                }
            }
        }
        
        // If we found a suitable block
        if (worstIdx != -1) {
            // Allocate file to this block
            allocation[i] = worstIdx;
            // Reduce available space in this block
            remaining[worstIdx] -= f[i];
            printf("\nFile size %d is allocated to block %d (Original: %d, Remaining: %d)", 
                   f[i], worstIdx+1, b[worstIdx], remaining[worstIdx]);
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
    int b[MAX], f[MAX];
    
    printf("Memory Management Scheme - Worst Fit\n");
    
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    
    printf("Enter the number of files: ");
    scanf("%d", &nf);
    
    printf("Enter the size of the blocks:\n");
    for (int i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }
    
    printf("Enter the size of the files:\n");
    for (int i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }
    
    worstfit(b, f, nb, nf);
    
    return 0;
}
