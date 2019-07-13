#include <stdio.h>
void swapMinMax1D(int ar[], int size);
int main()
{
 int ar[50],i,size;

 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d data: \n", size);
 for (i=0; i<size; i++)
 scanf("%d",ar+i);
 swapMinMax1D(ar, size);
 printf("swapMinMax1D(): ");
 for (i=0; i<size; i++)
 printf("%d ",*(ar+i));
 return 0;
}
void swapMinMax1D(int ar[], int size)
{
    int *min_num;
    int *max_num;
    int temp;
    min_num = ar;
    max_num = ar;
    for (int i = 0; i < size; i++) {
        if (*min_num >= ar[i]) {
            min_num = (ar + i);
        }
        if (*max_num <= ar[i]) {
            max_num = (ar + i);
        }
    }
    temp = *min_num;
    *min_num = *max_num;
    *max_num = temp;
}
