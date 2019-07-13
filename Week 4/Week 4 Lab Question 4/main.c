#include <stdio.h>
#define SIZE 10
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize);
void display(int ar[][SIZE], int rowSize, int colSize);
int main()
{
 int ar[SIZE][SIZE], rowSize, colSize;
 int i,j;
 printf("Enter row size of the 2D array: \n");
 scanf("%d", &rowSize);
 printf("Enter column size of the 2D array: \n");
 scanf("%d", &colSize);
 printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
 for (i=0; i<rowSize; i++)
 for (j=0; j<colSize; j++)
 scanf("%d", &ar[i][j]);
 reduceMatrix2D(ar, rowSize, colSize);
 printf("reduceMatrix2D(): \n");
 display(ar, rowSize, colSize);
 return 0;
}
void display(int ar[][SIZE], int rowSize, int colSize)
{
 int l,m;
 for (l = 0; l < rowSize; l++) {
 for (m = 0; m < colSize; m++)
 printf("%d ", ar[l][m]);
 printf("\n");
 }
}
void reduceMatrix2D(int ar[][SIZE], int rowSize, int colSize)
{
    int row, col;
    int sum; //For summing up each column

    for (col = 0; col < colSize && col < rowSize;col++){ // for each column //For this code to work, the number of columns should not be more than the number of rows, which is why we add the && col < rowSize.
        sum = 0; // reset sum back to zero at the start of every loop.
        //process the rows of the column
        for (row = col+1; row < rowSize;row++) { //Since we use col+1, we are excluding  the diagonal element in the sum.
            sum += ar[row][col];
            ar[row][col] = 0;
        }
        ar[col][col] += sum;
    }
}
