#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main()
{
 int data[SIZE][SIZE];
 int i,j;
 int rowSize, colSize;
 printf("Enter the array size (rowSize, colSize): \n");
 scanf("%d %d", &rowSize, &colSize);
 printf("Enter the matrix (%dx%d): \n", rowSize, colSize);
 for (i=0; i<rowSize; i++)
 for (j=0; j<colSize; j++)
 scanf("%d", &data[i][j]);
 printf("compress2D(): \n");
 compress2D(data, rowSize, colSize);
 return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize)
{
    int count;
    int variable;
    for (int i = 0; i < rowSize; i++) {
        variable = data[i][0];
        count = 0;
        for (int j = 0; j < colSize; j++) {
            if (j < colSize-1) {
                if (variable == data[i][j]) {
                count++;
                }
                else if (variable != data[i][j]) {
                    printf("%d ", variable);
                    printf("%d ", count);
                    count = 1;
                    variable = data[i][j];
                }
            }
            else if (j == (colSize-1)) {
                if (variable == data[i][j]) {
                count++;
                }
                else if (variable != data[i][j]) {
                printf("%d ", variable);
                printf("%d ", count);
                count = 1;
                variable = data[i][j];
                }
                printf("%d ", variable);
                printf("%d ", count);
            }
        }
        printf("\n");
    }
}
