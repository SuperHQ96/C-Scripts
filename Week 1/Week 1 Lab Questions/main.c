#include <stdio.h>
#include <stdlib.h>

int problem1()
{
    float farenheit, celsius;
    printf("Enter the temperature in degree F:\n");
    scanf("%f", &farenheit);
    celsius = ((float)5/9)*(farenheit-(float)32);
    printf("Converted degree in C: %.2f", celsius);
    return 0;
}
