#include <stdio.h>
int square1(int num);
void square2(int num, int *result);
int main()
{
int number, result=0;
printf("Enter the number: \n");
scanf("%d", &number);
printf("square1(): %d\n", square1(number));
square2(number, &result);
printf("square2(): %d\n", result);
return 0;
}
int square1(int num)
{
    int counter = 1;
    int square = 0;
    for (int i = 0; i<num;i++){
        square+=counter;
        counter+=2;
    }
    return square;
}
void square2(int num, int *result)
{
    int counter = 1;
    *result = 0;
    for (int i = 0; i<num;i++){
        *result+=counter;
        counter+=2;
    }
}
