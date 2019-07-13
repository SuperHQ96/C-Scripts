#include <stdio.h>

// '1' is the character 1 while "1" is the string 1

int main() {
    char loop;

    puts("Presenting the alphabet:"); //puts means to display a string. It is similar to printf but automatically puts a \n at the back

    for (loop='A';loop<='Z';loop++); // Loop character is represented by ASCII // You shouldn't have the semi-colon. If not, the loop executes 26 times until loop becomes the '[' character. Which is why this program outputs [.
        putchar(loop); //putchar() is equivalent to printf("%c",loop)

    return 0;
}

//In a for loop, it is one line but within the line, there are multiple instructions (Debugger))
