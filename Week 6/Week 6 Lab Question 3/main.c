#include <stdio.h>
#include <string.h>
struct student{
 char name[20]; /* student name */
 double testScore; /* test score */
 double examScore; /* exam score */
 double total; /* total = (testScore+examScore)/2 */
};
double average();
int main()
{
 printf("average(): %.2f\n", average());
 return 0;
}
double average()
{
    /*struct student e[50];
    int i = 0;
    double totalx = 0.00;
    do {
        printf("Enter student name: \n");
        scanf("%s", &e[i].name);
    }
    while (e[i].name != "END"); {
        printf("Enter test score: \n");
        scanf("%lf", &e[i].testScore);
        printf("Enter exam score: \n");
        scanf("%lf", &e[i].examScore);
        e[i].total = (e[i].testScore+e[i].examScore)/2;
        printf(" Student %s total = %lf", e[i].name, e[i].total);
        i++;
    }
    for (int j = 0; j<i; j++) {
        totalx += e[j].total;
    }
    return totalx/((double)i);*/
    struct student stud[50];
    double sum = 0;
    int j = 0;
    char dummychar;

    printf("Enter student name: \n");
    gets(stud[i].name);
    while (strcmp(stud[i].name, "END")!=0) {
        printf(Enter test score: \n);
        scanf("%lf", &stud[i].testscore);
        printf("Enter exam score: \n");
        scanf("%lf", &stud[i].examscore);
        /* Compute total*/
        stud[i].total = (stud[i].testScore + stud[i].examScore)/2;
        printf("Student %s total = %.2f\n", stud[i].name,stud[i].total);
        /*sum students' total and count students*/
        sum += stud[i].total;
        i++;
        /*Read the next student name*/
        printf("ENter student name: \n");
        scanf("%c", &dummychar);
        gets(stud[i].name);
    }
    if (i!=0)
        return (sum/i);
    else
        return 0;
}
