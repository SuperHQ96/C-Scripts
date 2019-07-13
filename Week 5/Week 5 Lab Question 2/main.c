#include <stdio.h>
char *stringncpy(char *s1, char *s2, int n);
int main()
{
 char sourceStr[40], targetStr[40], *target;
 int length;
 printf("Enter the string: \n");
 gets(sourceStr);
 printf("Enter the number of characters: \n");
 scanf("%d", &length);
 target = stringncpy(targetStr, sourceStr, length);
 printf("stringncpy(): %s\n", target);
 return 0;
}
char *stringncpy(char *s1, char *s2, int n)
{
    int len,i;
    i = 0;
    len = 0;
    while (s2[i]!='\0'){
     len++;
     i++;
     }
    if (len>n) {
        for (i=0;i<n;i++) {
            s1[i] = s2[i];
        }
        s1[n] = '\0';
    }
    else if (len <= n) {
        for (i = 0; i<len;i++) {
            s1[i] = s2[i];
        }
        for (i=len;i<=n;i++) {
            s1[i] = '\0';
        }
    }
    return s1;
}
