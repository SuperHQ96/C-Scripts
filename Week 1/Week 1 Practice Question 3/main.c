#include <stdio.h>
#include <stdlib.h>

int main()
{
    float distance, time, speed;
    printf("Enter distance (in km):\n");
    scanf("%f",&distance);
    printf("Enter time (in sec):\n");
    scanf("%f",&time);
    speed = distance/time;
    printf("The speed is %.2f km/sec",speed);
    return 0;
}
