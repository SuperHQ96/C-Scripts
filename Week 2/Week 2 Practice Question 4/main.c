#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ccount = 0, dcount = 0;
    char ch;
    printf("Enter your characters (# to end): \n");

    do {
        scanf("%c", &ch);
        if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
            ccount++;
        }
        else if (ch >= '0' && ch <= '9') {
            dcount++;
        }
    }
    while (ch != '#');

    printf("The number of digits: %d\n", dcount);
    printf("The number of letters: %d\n", ccount);
    return 0;
}
