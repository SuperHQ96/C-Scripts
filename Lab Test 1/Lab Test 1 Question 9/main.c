#include <stdio.h>
void processString(char *str, int *totVowels, int *totDigits);
int main()
{
 char str[50];
 int totVowels, totDigits;
 printf("Enter the string: \n");
 gets(str);
 processString(str, &totVowels, &totDigits);
 printf("Total vowels = %d\n", totVowels);
 printf("Total digits = %d\n", totDigits);
 return 0;
}
void processString(char *str, int *totVowels, int *totDigits)
{
    int vowels, digits;
    vowels = 0;
    digits = 0;
    while (*str != '\0') {
        if ((*str == 'a')||(*str == 'A')) {vowels++;}
        if ((*str == 'e')||(*str == 'E')) {vowels++;}
        if ((*str == 'i')||(*str == 'I')) {vowels++;}
        if ((*str == 'o')||(*str == 'O')) {vowels++;}
        if ((*str == 'u')||(*str == 'U')) {vowels++;}
        if (*str == '0') {digits++;}
        if (*str == '1') {digits++;}
        if (*str == '2') {digits++;}
        if (*str == '3') {digits++;}
        if (*str == '4') {digits++;}
        if (*str == '5') {digits++;}
        if (*str == '6') {digits++;}
        if (*str == '7') {digits++;}
        if (*str == '8') {digits++;}
        if (*str == '9') {digits++;}
        str++;
    }
    *totVowels = vowels;
    *totDigits = digits;
}
