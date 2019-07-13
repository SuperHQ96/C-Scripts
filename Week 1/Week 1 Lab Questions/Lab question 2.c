#include <stdio.h>
#include <math.h>
// Don't really need the math.h except for APAS
//Need to change this to main()
// Remember to put the & operator
//Remember to put return 0 as well as the semi-colon
//fabs() is the absolute value

int problem2() {
    float a1, b1, c1, a2, b2, c2, x, y;
    printf("Enter the values for a1, b1, c1, a2, b2, c2:\n");
    scanf("%f%f%f%f%f%f",&a1,&b1,&c1,&a2,&b2,&c2); // Optional to put the space in between the %f
    // If you put a comma in between the %f, then you might need to put commas in the command prompt
    // In the console window, you must put a space in between the individual input numbers
    if (fabs(a1*b2-a2*b1) >= 0.0001) { //Computers cannot store  exactly zero
            x = ((b2*c1)-(b1*c2))/((a1*b2)-(a2*b1));
            y = ((a1*c2)-(a2*c1))/((a1*b2)-(a2*b1));
            printf("x = %.2f and y = %.2f", x, y);
    }
    else {
        printf("Unable to compute = denominator is zero!"); // If there is only one statement, then there is no need for the curly brackets
    }
    return 0;
}
