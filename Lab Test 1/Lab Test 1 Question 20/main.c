#include <stdio.h>
#include <string.h>
typedef struct {
 char source;
 char code;
} Rule;
void encodeChar(Rule table[5], char *s, char *t);
int main()
{
 char s[80],t[80];
 Rule table[5] = {{'a','d'}, {'b','z'}, {'z','a'}, {'d','b'}, {'\0','\0'} };

 printf("Source string: \n");
 gets(s);
 encodeChar(table,s,t);
 printf("Encoded string: %s\n", t);
 return 0;
}
void encodeChar(Rule table[5], char *s, char *t)
{
    int i;
    while (*s!='\0') {
        for (i=0;i<5;i++) {
            printf("*s: %c\n", *s);
            printf("table[i].source: %c\n", table[i].source);
            if (*s==table[i].source) {
                printf("1\n");
                //*t = table[i].code;
                strncat(t, &table[i].code, 1);
            }
            else {
                printf("0\n");
                //*t = *s;
                strncat(t, s, 1);
            }
        }
        printf("*t: %c\n", *t);
        s++;
        t++;
    }
    if (*s=='\0') {
        //*t = *s;
        strncat(t, s, 1);
    }
}
