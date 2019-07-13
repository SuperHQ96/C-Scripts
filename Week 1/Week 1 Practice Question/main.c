#include <stdio.h>
#include <stdlib.h>

int main()
{
    float current;
    float resistance;
    float power;

    printf("Enter the current:\n");
    scanf("%f", &current);
    printf("Enter the resistance:\n");
    scanf("%f", &resistance);
    power = current*current*resistance;
    printf("The power loss is: %.2f", power);
}
