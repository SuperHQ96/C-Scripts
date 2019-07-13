#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, height;
    int num;
    printf("Enter the height: \n");
    scanf("%d", &height);
    printf("Pattern: \n");

    /* Write your program code here */
    for (row = 0; row<height;row++){
        for (col = 0; col<row+1; col++){
            num = row%3;
            printf("%d",num+1); //Don't put the newline character here
        }
        printf("\n");
    }

    return 0;
}
