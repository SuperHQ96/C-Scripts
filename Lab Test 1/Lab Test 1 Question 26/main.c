#include <stdio.h>
int rAllOddDigits1(int num);
int main()
{
 int number;
 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("rAllOddDigits1(): %d\n", rAllOddDigits1(number));
 return 0;
}
int rAllOddDigits1(int num)
{
    int i, temp;
    i = num%10;
    if (num<10) {
        if (i%2==0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else {
        temp = rAllOddDigits1(num/10);
        if (temp==0) {
            return 0;
        }
        else if (temp==1) {
            if (i%2==0) {
            return 0;
        }
        else {
            return 1;
        }
        }
    }
}
