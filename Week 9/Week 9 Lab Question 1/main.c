// CX1007 Data Structures
// Week 9 Lab Tutorial - DynamicData-Linked Lists

#include <stdlib.h>
#include "stdio.h"
//If you use angle brackets, the compiler will go straight to the folder to get from there. If you use inverted commas, they will try to find the header file in your folder. When it cannot find, it will also go to the standard library to find. Therefore, inverted commas is mostly used for your own header files.

////////////////////////////////////////////////////////////

void insert(char *s,int n);
void removes(char *s, int n); //There is a remove function in stdio so we must put an s behind remove when naming the function.

//////////////////////////////////////////////////////////
int main ()
{
	int n;
    char *s; //No memory for the string yet. So you cannot just use gets(s).
	int choice;


	printf("How many characters do you want to input:");
	scanf("%d", &n);

	s=malloc((n+1)*sizeof(char)); //n+1 to allocate one memory space for the null character. No need explicit casting (char *) here. You only need it for C++.

    if (s==NULL) //If not enough memory to store s.
	{
		printf("can't allocate the memory!");
		return 1; //Return 1 here
	}

	printf("Input the string:");
	scanf("%s",s);

	printf("The string is %s\n", s);

	do
	{
		printf("Do you want to 1-insert or 2-remove or 3-quit?:");
		scanf("%d",&choice);
		//getchar(); //to clear the return carriage in the buffer

		if (choice==1)
			insert(s,n);
		else if (choice==2)
			removes(s,n);
	}while (choice!=3);

	return 0;

}

//////////////////////////////////////////
void removes(char *s, int n)
{
    int i;

    for (i = 0; i<n; i++){
        *(s+i) = *(s+i+1); //Or you can use array notation: s[i] = s[i+1]
    }

    printf("Resulting string:%s\n", s);
}

//////////////////////////////////////////
void insert(char *s, int n)
{
    int i;

    for (i = n-1; i>0; i--)
    {*(s+i) = *(s+i-1);} //Can also use index notation: s[i] = s[i-1].
    printf("What is the character ypu want to insert:");
    getchar(); //flush the input buffer
    scanf("%c", s); //Don't need to put & operator since s is already a pointer.

    printf("Resulting string:%s\n", s);
}
