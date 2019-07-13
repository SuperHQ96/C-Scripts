#include <stdio.h>
void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);
void reverseAr1D(int ar[], int size);
int main()
{
 int ar[10];
 int size, i;

 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d data: \n", size);
 for (i=0; i <= size-1; i++)
 scanf("%d", &ar[i]);
 printReverse1(ar, size);
 printReverse2(ar, size);
 reverseAr1D(ar, size);
 printf("reverseAr1D(): ");
 if (size > 0) {
 for (i=0; i<size; i++)
 printf("%d ", ar[i]);
 }
 return 0;
}
void printReverse1(int ar[], int size)
{
    int i;
    printf("printReverse1(): ");
    for (i=size-1;i>=0;i--)
        printf("%d", ar[i]);
    printf("\n");
}
void printReverse2(int ar[], int size)
{
    int i;
    printf("printReverse2(): ");
    for (i=size-1;i>=0;i--)
        printf("%d", *(ar + i));
    printf("\n");
}
void reverseAr1D(int ar[ ], int size)
{
    int i, temp;
    for (i = 0; i<size/2; i++){
        temp = ar[i];
        ar[i] = ar [size-(i+1)];
        ar[size-(i+1)] = temp;
        // If eight data are inputted, index zero swaps with index seven, index one swaps with index six and so on.
        // This means that the index all adds up to seven.
    }
}
