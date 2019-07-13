#include <stdio.h>
#define SIZE 10
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize);
int main()
{
 int ar[SIZE][SIZE], rowSize, colSize;
 int i,j,min;

 printf("Enter row size of the 2D array: \n");
 scanf("%d", &rowSize);
 printf("Enter column size of the 2D array: \n");
 scanf("%d", &colSize);
 printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
 for (i=0; i<rowSize; i++)
 for (j=0; j<colSize; j++)
 scanf("%d", &ar[i][j]);
 min=minOfMax2D(ar, rowSize, colSize);
 printf("minOfMax2D(): %d\n", min);
 return 0;
}
int minOfMax2D(int ar[][SIZE], int rowSize, int colSize)
{
    int i, j, maximum, minofmax;
    for (i=0;i<colSize;i++){
        maximum = *(*(ar + i) + 0);
        for (j=1;j<rowSize;j++) {
            if (maximum < *(*(ar + i)+j)){
                maximum = *(*(ar + i) +j);
            }
        }
        if (i==0) {
            minofmax = maximum;
        }
        else {
            if (minofmax > maximum) {
                minofmax = maximum;
            }
        }
    }
    return minofmax;
}
