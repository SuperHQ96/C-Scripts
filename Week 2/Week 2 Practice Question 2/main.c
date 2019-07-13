#include <stdio.h>
#include <stdlib.h>

int main()
{
    int salary, merit;
    char grade;

    printf("Enter the salary: \n");
    scanf("%d", &salary);
    printf("Enter the merit: \n");
    scanf("%d",&merit);

    if ((800 <= salary)&&(salary <= 899)) {
        grade = 'A';
    }
    else if ((700 <= salary)&&(salary <= 799)) {
        if (merit < 20) {
            grade = 'B';
        }
        else {
            grade = 'A';
        }
    }
    else if ((650 <= salary)&&(salary <= 699)){
        grade = 'B';
    }
    else if ((600 <= salary)&&(salary<=649)){
        if (merit<10){
            grade = 'C';
        }
        else {
            grade = 'B';
        }
    }
    else if ((500 <= salary)&&(salary <= 599)){
        grade = 'C';
    }

    printf("The grade: %c\n", grade);

    return 0;
}
