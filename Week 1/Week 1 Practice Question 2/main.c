#include <stdio.h>
#include <stdlib.h>

int main()
{
    const float pi = 3.14159265;
    float radius, height, volume, surface_area;
    printf("Enter the radius:\n");
    scanf("%f",&radius);
    printf("Enter the height:\n");
    scanf("%f",&height);
    volume = pi*radius*radius*height;
    surface_area = (2*pi*radius*height)+(2*pi*radius*radius);
    printf("The volume is: %.2f\n",volume);
    printf("The surface area is: %.2f\n",surface_area);
}
