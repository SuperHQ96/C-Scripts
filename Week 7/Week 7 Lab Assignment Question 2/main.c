#include <stdio.h>
int rDigitValue1(int num, int k);
int main()
{
 int k, number;

 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("Enter k position: \n");
 scanf("%d", &k);
 printf("rDigitValue1(): %d\n", rDigitValue1(number, k));
 return 0;
}
int rDigitValue1(int num, int k)
{
    int number;
    if ((num%10==k)||(num<10)) {
        if (num%10==k) {
            return 1;
        }
        else
            return 0;
    }
    else {
        number = rDigitValue1(num/10,k);
        if (number==0) {
            return 0;
        }
        else
            return 1+number;
    }
}
