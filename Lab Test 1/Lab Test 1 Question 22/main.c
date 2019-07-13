#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
 char name[20];
 char telno[20];
} PhoneBk;
int readin(PhoneBk *p);
void search(PhoneBk *p, int size, char *target);
int main()
{
 PhoneBk s[MAX];
 char t[20];
 int size;
 size = readin(s);
  printf("Enter search name: \n");
 gets(t);
 search(s,size,t);
 return 0;
}
int readin(PhoneBk *p)
{
    int sentinel_value, countt;
    sentinel_value = 0;
    countt = 0;
    char dummy;
    while (sentinel_value != -1) {
        printf("Enter name:\n");
        gets(p[countt].name);
        if (strcmp(p[countt].name, "#")!=0) {
            printf("Enter tel:\n");
            scanf("%s", p[countt].telno);
            scanf("%c", &dummy);
        }
        else {
            sentinel_value = -1;
        }
        countt++;
    }
    return countt;
}
void search(PhoneBk *p, int size, char *target)
{
    int i, j;
    j = 0;
    for (i=0;i<size;i++) {
        if (strcmp(p[i].name, target)==0) {
            printf("Name = %s, Tel = %s\n", p[i].name, p[i].telno);
            j = 1;
        }
    }
    if (j==0) {
        printf("Name not found!\n");
    }
}
