#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total, count, lines, input;
    double average;
    int i;
    printf("Enter number of lines: \n");
    scanf("%d", &lines);

    /* Write your program code here */
    for (i=0;i<lines;i++){
        count = 0;
        printf("Enter line %d (end with -1): \n",i+1);
        scanf("%d",&input);
        while (input != -1) {
            count += 1;
            total = total + input;
            scanf("%d",&input);
        }
        average = (double)total/count; //Use double not float. Just cast one not both. Casting has high precedence.
        printf("Average = %.2f\n",average);
    }
    return 0;
}
