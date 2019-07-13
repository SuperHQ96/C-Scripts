#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hours;
    float tax, grossPay, netPay;
    printf("Enter hours of work: \n");
    scanf("%d", &hours);
    if (hours <= 40) {
        grossPay = hours*6.00;
    }
    else if (hours > 40) {
        grossPay = (40.00*6.00) + ((hours-40)*9.00);
    }
    if (grossPay<=1000.00) {
        tax = grossPay *0.10;
    }
    else if ((1000.00<grossPay)&&(grossPay<=1500)) {
        tax = (1000.00*0.10) + ((grossPay-1000.00)*0.20);
    }
    else {
        tax = (1000.00*0.10) + (500.00*0.20) + ((grossPay-1500.00)*0.30);
    }
    netPay = grossPay-tax;
    printf("Gross pay = %.2f\n", grossPay);
    printf("Tax = %.2f\n", tax);
    printf("Net pay = %.2f\n", netPay);
    return 0;
}
