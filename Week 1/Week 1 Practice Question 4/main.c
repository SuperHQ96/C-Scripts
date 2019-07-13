#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x1,y1,x2,y2,distance,a,b;
    printf("Enter the first point x1 y1:\n");
    scanf("%f%f", &x1,&y1);
    printf("Enter the second point x2 y2:\n");
    scanf("%f%f",&x2,&y2);
    a = x1-x2;
    b = y1-y2;
    distance = sqrt(a*a+b*b);
    printf("The distance is %.2f",distance);
}
