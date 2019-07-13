#include <stdio.h>
void rFindMaxAr(int *ar, int size, int i, int *index);
int main()
{
 int ar[50],i,maxIndex=0,size;
 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d numbers: \n", size);
 for (i=0; i < size; i++)
 scanf("%d", &ar[i]);
 rFindMaxAr(ar,size,0,&maxIndex);
 printf("Max number: %d\n", ar[maxIndex]);
 printf("Index position: %d\n", maxIndex);
 return 0;
}
void rFindMaxAr(int *ar, int size, int i, int *index)
{
    printf("ar[0]: %d\n", ar[0]);
    printf("size: %d\n", size);
    printf("i: %d\n", i);
    printf("index: %d\n", *index);
    if (size == 0) {
        if (ar[0]>i) {
            i = ar[0];
            *index = -1;
        }
    }
    else {
        if (ar[0]>i) {
            i = ar[0];
            *index = -1;
        }
        rFindMaxAr(ar+1, size-1, i, index);
        if ((ar[0]>i)||(*index>-1)) {
            *index += 1;
        }
        printf("*index: %d\n", *index);
    }
}
