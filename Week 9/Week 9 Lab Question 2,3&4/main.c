#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;

int searchList(ListNode *head, int value);

int main()
{
    ListNode *head = NULL;
    ListNode *p; //I make use of this p to point to the last node so that it will be easier when I want to add values to the end of the linked list. It is also used to transverse the linked list to print out all the values.
    ListNode *temp;

    int num; // To read in the values
    int index; //Used to capture the return value of the function searchList.

    printf("Enter a list of numbers, terminated by the value -1:\n");

    //begin to build the linked list
    scanf("%d", &num);

    while (num != -1){
        if (head == NULL) {
            head = malloc(sizeof(ListNode));
            p = head; //p points to whatever head is pointing to. It is not the case that p points to head.
        }
        else {
            p -> next = malloc(sizeof(ListNode));
            p = p->next;
        }
        p -> item = num;
        scanf("%d", &num);
    }
    p -> next = NULL;

    //Print the items of the current linked list

    printf("Current list: ");
    p = head;

    while (p != NULL) {
        printf("%d ", p->item);
        p = p->next;
    }

    printf("\n");
    //Can also use for loop

    for (p = head; p!=NULL; p = p->next) {
        printf("%d ", p->item);
    }

    printf("\n");

    printf("Enter value to search for: ");
    scanf("%d", &num);
    index = searchList(head, num);
    printf("Value found at index %d\n", num, index);

    p = head;
    while (p!= NULL) {
        temp = p->next;
        free(p);
        p=temp;
    } //Must use a temporary pointer because once you free p, p->next will be gone so you cannot assign p->next directly to p after you have freed up p.

    return 0;
}//end of main()

int searchList(ListNode *head, int value){
    int i = 0; //keeps track of the position of each node during traversal since linked list does not have an index, unlike arrays
    ListNode *p = head; //points to first node (position of first node is 0)

    while (p != NULL) {
        if (p->item == value) {return i;}
        i++;
        p = p->next;
    }
    head = NULL; //Must set head back to NULL as well since it is still pointing to a particular storage.
    //No need to free up temp, head and p since they are allocated into the stack which will be freed up after the program execution.

    return -1;//value not found
}
