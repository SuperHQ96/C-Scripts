#include <stdio.h>
int rDigitPos1(int num, int digit);
void rDigitPos2(int num, int digit, int *pos);
int main()
{
 int number, digit, result=0;
 printf("Enter the number: \n");
 scanf("%d", &number);
 printf("Enter the digit: \n");
 scanf("%d", &digit);
 printf("rDigitPos1(): %d\n", rDigitPos1(number, digit));
  rDigitPos2(number, digit, &result);
 printf("rDigitPos2(): %d\n", result);
 return 0;
}
int rDigitPos1(int num, int digit)
{
    int pos;

    if (num % 10 == digit)
        return 1;
    else if (num < 10)
        return 0;
    else {
        pos = rDigitPos1(num/10, digit);
        if (pos > 0)
            return pos + 1;
        else
            return pos;
    }
}
void rDigitPos2(int num, int digit, int *pos)
{
    if (num % 10 == digit) //Terminating/stopping case 1 (Digit is found)
        *pos = 1;
    else if (num < 10) //Terminating/stopping case 2 (digit is NOT found)
        *pos = 0;
    else { //Recursive/continuing case
        rDigitPos2(num/10,digit,pos);
        if (*pos > 0)
            *pos += 1;
        else
            *pos == 0;
    }
}
