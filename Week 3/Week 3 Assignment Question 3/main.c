#include <stdio.h>
#define INIT_VALUE -1
int allEvenDigits1(int num);
void allEvenDigits2(int num, int *result);
int main()
{
     int number, result = INIT_VALUE;
     printf("Enter a number: \n");
     scanf("%d", &number);
     printf("allEvenDigits1(): ");
     result = allEvenDigits1(number);
     if (result == 1)
     printf("All Even\n");
     else if (result == 0)
     printf("Not All Even\n");
     else
     printf("Error\n");
     allEvenDigits2(number, &result);
     printf("allEvenDigits2(): ");
     if (result == 1)
     printf("All Even\n");
     else if (result == 0)
     printf("Not All Even\n");
     else
     printf("Error\n");
     return 0;
}
int allEvenDigits1(int num)
{
    int q;
    q = (num+1) % 2;
    while ((num % 2 != 1)&&((num/10) > 0)){
        num /= 10;
        q = (num+1) % 2;
    }
    return q;
}
void allEvenDigits2(int num, int *result)
{
    *result = (num+1) % 2;
    while ((num % 2 != 1)&&((num/10) > 0)){
        num /= 10;
        *result = (num+1) % 2;
    }
}
