#include <stdio.h>
int rLookupAr(int array[], int size, int target);
int main()
{
 int numArray[80];
 int target, i, size;
 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d numbers: \n", size);
 for (i=0; i < size; i++)
 scanf("%d", &numArray[i]);
 printf("Enter the target number: \n");
 scanf("%d", &target);
 printf("rLookupAr(): %d", rLookupAr(numArray, size, target));
 return 0;
}
int rLookupAr(int array[], int size, int target)
{
    int number;
    if (size<=1) {
        if (array[0]==target) {
            return 0;
        }
        else {
            return -1;
        }
    }
    else {
        number = rLookupAr(array+1, size-1, target);
        if (number==-1) {
            if (array[0]==target) {
                return 0;
            }
            else
                return number;
        }
        else {
            return 1 + number;
        }
    }
}
