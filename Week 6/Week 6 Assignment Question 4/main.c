#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
 char name[40];
 char telno[40];
 int id;
 double salary;
} Employee;
int readin(Employee *p);
void printEmp(Employee *p, int size) ;
int search(Employee *p, int size, char *target);
int addEmployee(Employee *p, int size, char *target);
int main()
{
 Employee emp[MAX];
 char name[10];
 int k, size, found=0, ans, choice, result;

 printf("Select one of the following options: \n");
 printf("1: readin()\n");
 printf("2: search()\n");
 printf("3: addEmployee()\n");
 printf("4: print()\n");
 printf("5: exit()\n");
 do {
 printf("Enter your choice: \n");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 size = readin(emp);
 break;
 case 2:
 printf("Enter search name: \n");
 scanf("\n");
 gets(name);
 result = search(emp,size,name);
 if (result != 1)
 printf ("Name not found!\n");
 break;
 case 3:
 printf("Enter new name: \n");
 scanf("\n");
 gets(name);
 result = search(emp,size,name);
 if (result != 1)
 size = addEmployee(emp, size, name);
 else
 printf("The new name has already existed in the database");
 break;
 case 4:
 printEmp(emp, size);
 break;
 default:
 break;
 }
 } while (choice < 5);
 return 0;
}
int readin(Employee *p)
{
    int count = 0;
    char temp[40] = "";
    char dummychar;
    while ((temp[0]!='#')&&(count<=100)) {
        scanf("%c", &dummychar);
        printf("Enter name: \n");
        gets(p[count].name);
        strcpy(temp,p[count].name);
        if (strcmp(temp,"#")==0) {break;}
        printf("Enter tel: \n");
        scanf("%s", &p[count].telno);
        printf("Enter id: \n");
        scanf("%d", &p[count].id);
        printf("Enter salary: \n");
        scanf("%lf", &p[count].salary);
        count+=1;
    }
    return count;
}
void printEmp(Employee *p, int size)
{
    printf("The current employee list: \n");
    for (int i=0;i<size;i++) {
        printf("%s %s %d %.2lf\n", p[i].name, p[i].telno, p[i].id, p[i].salary);
    }
}
int search(Employee *p, int size, char *target)
{
    for (int i = 0; i<size;i++) {
        if (strcmp(p[i].name,target)==0) {
            printf("Employee found at index location: %d\n", i);
            printf("%s %s %d %.2lf\n", p[i].name, p[i].telno, p[i].id, p[i].salary);
            return 1;
        }
    }
    return 0;
}
int addEmployee(Employee *p, int size, char *target)
{
    if (size==100) {
        printf("Database is full\n");
        return size;
    }
    else {
        strcpy(p[size].name,target);
        printf("Enter tel: \n");
        scanf("%s", &p[size].telno);
        printf("Enter id: \n");
        scanf("%d", &p[size].id);
        printf("Enter salary: \n");
        scanf("%lf", &p[size].salary);
        printf("Added at position: %d\n", size);
        return size+1;
    }
}
