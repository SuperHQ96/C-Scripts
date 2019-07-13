#include <stdio.h>
#define INIT_VALUE -1
int palindrome(char *str);
int main()
{
 char str[80];
 int result = INIT_VALUE;

 printf("Enter a string: \n");
 gets(str);
 result = palindrome(str);
 if (result == 1)
 printf("palindrome(): A palindrome\n");
 else if (result == 0)
 printf("palindrome(): Not a palindrome\n");
 else
 printf("An error\n");
 return 0;
}
int palindrome(char *str)
{
    int i, len;
    i = 0;
    len = 0;
    while (str[i]!='\0'){
         len++;
         i++;
    }
    i = 0;
    len -= 1;
    while ((i<len)&&(i!=len)) {
        if (str[i]!=str[len]) {
            return 0;
        }
        i++;
        len--;
    }
    return 1;
}
