#include <stdio.h>
#define max 25

void firstfit(int b[], int f[], int nb, int nf)
{
    int i, j, flag;
    for (i = 0; i < nf; i++) {
        flag = 0;
        for (j = 0; j < nb; j++) {
            if (b[j] >= f[i]) {
                printf("\nFile Size %d is put in Block of size %d", f[i], b[j]);
                b[j] = 0;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("\nFile Size %d must Wait", f[i]);
    }
}

int main()
{
    int i, nb, nf;
    int b[max], f[max];
    printf("Memory Management Scheme - First Fit\n");
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
    firstfit(b, f, nb, nf);
    return 0;
}
