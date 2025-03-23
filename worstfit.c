#include <stdio.h>

void worstfit(int b[], int f[], int nb, int nf)
{
    int i, j, k = 0, temp, highest, flag;
    printf("\nprocess no. \tprocess size\tblock size\n");
    for (i = 0; i < nf; i++) {
        highest = -1;
        flag = 0;
        printf("%d\t\t %d\t\t",i+1,f[i]);
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
            printf(" %d \n",b[k]);
            b[k] = 0; // Mark the block as used
        } else {
            printf("Wait\n");
        }
    }
}

void main()
{
    int i, nb, nf;
   
    printf("Memory Management Scheme - Worst Fit\n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);
    int b[nb], f[nf];

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
