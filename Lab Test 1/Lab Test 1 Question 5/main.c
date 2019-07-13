#include <stdio.h>
int platform1D(int ar[], int size);
int main()
{
 int i,b[50],size;
 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d data: \n", size);
 for (i=0; i<size; i++)
 scanf("%d",&b[i]);
 printf("platform1D(): %d\n", platform1D(b,size));
 return 0;
}
int platform1D(int ar[], int size)
{
    int i, platform, j;
    j = 1;
    platform = 0;
    for (i=0;i<size-1;i++) {
        if (*(ar+i)==*(ar+i+1)) {
            j++;
        }
        else if (*(ar+i)!=*(ar+i+1)) {
            if (j>platform) {
                platform = j;
            }
            j = 1;
        }
    }
    return platform;
}
