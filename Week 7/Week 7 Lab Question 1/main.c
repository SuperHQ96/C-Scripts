#include <stdio.h>
int rNumDigits1(int num);
void rNumDigits2(int num, int *result);
int main()
{
 int number, result=0;

 printf("Enter the number: \n");
 scanf("%d", &number);
 printf("rNumDigits1(): %d\n", rNumDigits1(number));
 rNumDigits2(number, &result);
 printf("rNumDigits2(): %d\n", result);
 return 0;
}
int rNumDigits1(int num)
{
    if (num < 10)
        return 1;
    else
        return rNumDigits1(num/10) +1; //Drop the rightmost digit
 }
void rNumDigits2(int num, int *result)
{
    if (num < 10)
        *result = 1;
    else {
        rNumDigits1(num/10, result) //Pass in the address, which does not require & operator.
        (*result)++; //Here, you let another recursive function process the remaining digits which will place the result somewhere which is accessible to the calling function.
    }
 }
