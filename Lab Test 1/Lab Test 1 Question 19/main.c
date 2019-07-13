#include <stdio.h>
typedef struct {
 char name[20];
 int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);
int main()
{
 Person man[3], middle;

 readData(man);
 middle = findMiddleAge(man);
 printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
 return 0;
}
void readData(Person *p)
{
    printf("Enter person 1:\n");
    scanf("%s", p[0].name);
    scanf("%d", &p[0].age);
    printf("Enter person 2:\n");
    scanf("%s", p[1].name);
    scanf("%d", &p[1].age);
    printf("Enter person 3:\n");
    scanf("%s", p[2].name);
    scanf("%d", &p[2].age);
}
Person findMiddleAge(Person *p)
{
    int i;
    if ((p[0].age>=p[1].age)&&(p[0].age<=p[2].age)) {i = 0;}
    if ((p[0].age>=p[2].age)&&(p[0].age<=p[1].age)) {i = 0;}
    if ((p[1].age>=p[0].age)&&(p[0].age<=p[2].age)) {i = 1;}
    if ((p[1].age>=p[2].age)&&(p[0].age<=p[0].age)) {i = 1;}
    if ((p[2].age>=p[1].age)&&(p[0].age<=p[0].age)) {i = 2;}
    if ((p[2].age>=p[0].age)&&(p[0].age<=p[1].age)) {i = 2;}
    return p[i];
}
