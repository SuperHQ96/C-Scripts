#include <stdio.h>
#include <stdlib.h>

int main()
{
    int list, coe = 0, cat;
    double discounted, luxury = 0, gst, total;

    printf("Please enter the list price: \n");
    scanf("%d", &list);
    printf("Please enter the category: \n");
    scanf("%d", &cat);

    discounted = list * 0.90;

    if (discounted <= 100000.00) {
        gst = 0.03*discounted;
    }
    else if (discounted > 100000.00) {
        luxury = 0.10*discounted;
        gst = (discounted+luxury)*0.03;
    }

    switch (cat) {
        case 1: {
            coe = 70000;
            break;
        }
        case 2: {
            coe = 80000;
            break;
        }
        case 3: {
            coe = 23000;
            break;
        }
        case 4: {
            coe = 600;
            break;
        }
        default: {
            break;
        }
    }

    total = discounted + luxury + gst + coe;

    printf("Total price is $%.2lf\n",total);
    return 0;
}
