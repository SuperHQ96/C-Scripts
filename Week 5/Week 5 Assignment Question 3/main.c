#include <stdio.h>
void maxCharToFront(char *str);
int main()
{
 char str[80];

 printf("Enter a string: \n");
 gets(str);
 printf("maxCharToFront(): ");
 maxCharToFront(str);
 puts(str);
 return 0;
}
void maxCharToFront(char *str)
{
    int i, len, max_index;
    char ch;
    i = 0;
    len = 0;
    while (str[i]!='\0'){
        len++;
        i++;
    }
    if (len == 1) {max_index = 0;}
    else {
        ch = str[0];
        for (i=1;i<len;i++) {
            if (str[i]>ch) {
                    max_index = i;
                    ch = str[i];
            }
        }
        ch = str[0];
        str[0] = str[max_index];
        for (i = max_index;i>=1;i--) {
            str[i] = str[i-1];
        }
        str[1] = ch;
    }
}
