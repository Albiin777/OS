#include <stdio.h>
void bestfit (int f[], int b[], int nf, int nb)
{printf("\nprocess no. \tprocess size\tblock size\n");
for(int i=0; i<nf; i++)
{
int flag=0;
printf("%d\t\t %d\t\t",i+1,f[i]);

for(int j=0; j<nb; j++)
{
int temp = b[j]-f[i];
if(temp>=0)
{
printf("%d \n",b[j]);
b[j]=0;
flag=1;
break;
}
}
if (flag == 0)
printf ("Wait\n");
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
