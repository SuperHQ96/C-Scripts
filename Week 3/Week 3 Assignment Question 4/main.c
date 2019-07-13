#include <stdio.h>
#define INIT_VALUE 0
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);
int main()
{
 int number, result = INIT_VALUE;

 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("extOddDigits1(): %d\n", extOddDigits1(number));
 extOddDigits2(number, &result);
 printf("extOddDigits2(): %d\n", result);
 return 0;
}
int extOddDigits1(int num)
{
    int remainder;
    int count1 = 1;
    float result = 0;
    int result2;
    while (((num/10) > 0)||((num >0)&&(num<10))){
        remainder = num % 10;
        if (remainder % 2 == 1) {
            result += remainder;
            result /= 10;
            count1*=10;
        }
        num /= 10;
    }
    result *=count1;
    result2 = (int)result;
    if (result2 == 0) {
        return -1;
    }
    else {
        return result2;
    }
}
void extOddDigits2(int num, int *result) {
    int remainder;
    int count1 = 1;
    float result1 = 0;
    while (((num/10) > 0)||((num >0)&&(num<10))){
        remainder = num % 10;
        if (remainder % 2 == 1) {
            result1 += remainder;
            result1 /= 10;
            count1*=10;
        }
        num /= 10;
    }
    result1 = result1*count1;
    if (result1 == 0.00) {
        *result = -1;
    }
    else {
        *result = (int)result1;
    }
}
