#include <stdio.h>
#define INIT_VALUE 999
int stringcmp(char *s1, char *s2);
int main()
{
 char source[80], target[80];
 int result = INIT_VALUE;

 printf("Enter a source string: \n");
 gets(source);
 printf("Enter a target string: \n");
 gets(target);
 result = stringcmp(source, target);
 if (result == 1)
 printf("stringcmp(): greater than");
 else if (result == 0)
 printf("stringcmp(): equal");
 else if (result == -1)
 printf("stringcmp(): less than");
 else
 printf("stringcmp(): error");
 return 0;
}
int stringcmp(char *s1, char *s2)
{
    int i, len1, len2;
    i = 0;
    len1 = 0;
    while (s1[i]!='\0'){
        len1++;
        i++;
    }
    i = 0;
    len2 = 0;
    while (s2[i]!='\0'){
        len2++;
        i++;
    }
    if (len1 > len2) {
        for (i = 0; i<len2;i++) {
            if (s1[i]>s2[i]) {return 1;}
            else if (s1[i]<s2[i]) {return -1;}
        }
        return 1;
    }
    else if (len2 == len1) {
        for (i = 0; i<len2;i++) {
            if (s1[i]>s2[i]) {return 1;}
            else if (s1[i]<s2[i]) {return -1;}
        }
        return 0;
    }
    else if (len1 < len2) {
        for (i = 0; i<len2;i++) {
            if (s1[i]>s2[i]) {return 1;}
            else if (s1[i]<s2[i]) {return -1;}
        }
        return -1;
    }
    return 2;
}
