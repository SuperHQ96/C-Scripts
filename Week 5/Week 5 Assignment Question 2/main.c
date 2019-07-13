#include <stdio.h>
int longWordLength(char *s);
int main()
{
 char str[80];
 printf("Enter a string: \n");
 gets(str);
 printf("longWordLength(): %d\n", longWordLength(str));
 return 0;
}
int longWordLength(char *s)
{
    int i, max_word, count_of, len;
    i = 0;
    len = 0;
    while (s[i]!='\0'){
        len++;
        i++;
    }
    max_word = 0;
    count_of = 0;
    for (i=0;i<len;i++) {
        if ((s[i]==' ')||((i+1)==len)) {
            if (count_of > max_word) {
                max_word = count_of;
            }
            count_of = 0;
        }
        else {
            count_of++;
        }
    }
    return max_word;
}
