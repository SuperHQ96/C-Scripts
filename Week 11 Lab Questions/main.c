//CE1007/CZ1007 Data Structures
// Week 11 Lab Tutorial - Stacks and Queues

////////////////////////////////////////////////////////////

#include "stdio.h"
#include <stdlib.h>

//////////////////////////////////   linked list //////////////////////////////////////////////

typedef struct _listnode{
	int item;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
	int size;
	ListNode *head;
	ListNode *tail;
} LinkedList;

////////////////////////////////// stack    //////////////////////////////////////////////
typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////////////////// queue ////////////////////////////////////////////

typedef struct _queue{
	LinkedList ll;
} Queue;

////////////////////////////////////////////////////////////////////////////////
void printList(ListNode *head);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

//////////////////////////////////////////////////

void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

//////////////////////////////////////////////////

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int isEmptyQueue(Queue *s);

///////////////////////////////////////////////////////////////
// four questions
void removeUntil(Stack *s, int value);
void recursiveReverse(Queue *q);
int palindrome(char *word);
int balanced(char *expression);

//////////////////////////////////////////////////////////////////
/////

int main()
{
	Stack s;
	Queue q;
	int item[] = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };
	int i;
	char *word1 = "A man a plan a canal Panama";
	char *word2 = "Superman in the sky";

	//for question 1
	//initialize the stack
	s.ll.head = NULL;
	s.ll.size = 0;
	s.ll.tail = NULL;

	for (i = 0; i<11; i++)
		push(&s, item[i]);

	printList(s.ll.head);
	removeUntil(&s, 5);
	printList(s.ll.head);

	//for question 2
	//initialize the queue
	q.ll.head = NULL;
	q.ll.size = 0;
	q.ll.tail = NULL;

	for (i = 0; i<10; i++)
		enqueue(&q, i);
	printList(q.ll.head);
	recursiveReverse(&q);
	printList(q.ll.head);

	//for question 3
	palindrome(word1); //*word1="A man a plan a canal Panama";
	palindrome(word2);// *word2="Superman in the sky";


	//for question 4
	if (balanced("()")) printf("not balanced!\n"); //If it is balanced I return a zero (false), if it is not balanced, I return a -1(true).
	else
		printf("balanced!\n");

	if (balanced("[()]")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("{[]()[]}")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	if (balanced("[({{)])")) printf("not balanced!\n");
	else
		printf("balanced!\n");

	return 0;
}

////////////////////////////////////////////////////////////////
//Question 1

void removeUntil(Stack *s, int value){
    while (!isEmptyStack(s)) {
        if(peek(s)==value)
            break;
        pop(s);
    }
    /*
    Alternate way:
    while (!isEmptyStack(s) && peek(s)!= value)
        pop(s);
    */
}

////////////////////////////////////////////////////////////
//Question 2

void recursiveReverse(Queue *q){
    int item;
    //No need to show terminating case here since you just do nothing when the list is empty.
    if (!isEmptyQueue(q)) //For recursive function, you are passing a smaller and smaller problem to your partner. This can be done here by passing a smaller queue to the partner. For queues, you can only remove items from the front, so the front element is removed if you want to pass a smaller queue.
    {
        item = dequeue(q); //Remove the front element of q.
        recursiveReverse(q); //Reverse the elements (excluding the removal element) in q.
        enqueue(q, item); //Enqueue the removed element to the back of q.
        //This implementation is good since you can't tell that you are using linked lists underlying the queue.
    }
}

////////////////////////////////////////////////////////////
//Question 3

int palindrome(char *word){
    Stack s;
    Queue q;
    int i = 0;

    //Initialize Stack
    s.ll.head = s.ll.tail = NULL;
    q.ll.size = 0;

    //Push and enqueue each character to s & q
    while (*(word+i) != '\0') {
        if (*(word+i)!=' ') {
            push(&s, toupper(*word));
            enqueue(&q, toupper(*word)); //You can push characters into the stack and queue with nodes that contains integers since C treats characters like integers using their ASCII values.
        }
        i++; //Cannot use word++ here since you won't be able to print out the sentence later since you would have moved the pointer.
    }
    //Pop and dequeue characters to check for mismatch
    while (!isEmptyStack(&s))
    {
        if(pop(&s)!=dequeue(&q))
        {
            printf("The string \"%s\" is not a palindrome\n", word);
            return -1;
        }
    }
    //Corresponding characters match throughout
    printf("The string is a palindrome\n");
    return 0;
}



////////////////////////////////////////////////////////////
//Question 4

int balanced(char *expression){
    /*
    Strategy:
    Use a stack
    For each bracket in expression, if it is ([ or {, push it to the stack. It it is ),] or }, pop from the stack.( If stack is empty, return -1. If the popped open bracket does not match with the close bracket, return -1.)
    In the end, if the stack is empty, return 0, else return -1.
    */
    Stack s;
    //Initialize Stack
    s.ll.head = s.ll.tail = NULL;
    s.ll.size = 0;
    //Process each character in expression according to the strategy
    while (*expression != '\0')
    {
        if (*expression=='('||*expression=='['||*expression=='{')
                push(&s, *expression);
        else if (*expression==')'){
            if(isEmptyQueue(&s)||pop(&s)!='(') //Need to make sure that the stack is not empty as trying to pop from an empty stack will give an error.
                return -1;
        }else if (*expression==']'){
            if(isEmptyQueue(&s)||pop(&s)!='[')
                return -1;
        }else if (*expression=='}'){
            if(isEmptyQueue(&s)||pop(&s)!='{')
                return -1;
        }
        expression++;
    }
    //Stack has to be empty in the end for balanced brackets
    if(isEmptyQueue(&s))
        return 0;
    else
        return 1;
}

////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, int item){
	insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
	int item;

	item = ((s->ll).head)->item;
	removeNode(&(s->ll), 0);
	return item;
}

int peek(Stack *s){
	return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
	if ((s->ll).size == 0)
		return 1;
	return 0;
}


////////////////////////////////////////////////////////////////////////////////

void enqueue(Queue *q, int item){
	insertNode(&(q->ll), q->ll.size, item);
}

int dequeue(Queue *q){
	int item;
	item = ((q->ll).head)->item;
	removeNode(&(q->ll), 0);
	return item;
}

int isEmptyQueue(Queue *q){
	if ((q->ll).size == 0)
		return 1;
	return 0;
}



////////////////////////////////////////////////////////////////////////////////

void printList(ListNode *head){

	ListNode *temp = head;

	if (temp == NULL)
		return;

	while (temp != NULL){
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->tail = ll->head;
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}

	// Inserting as new last node
	if (index == ll->size){
		pre = ll->tail;
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		ll->tail = pre->next;
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));

		if (index == ll->size)
			ll->tail = pre->next;

		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}

int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		if (ll->size == 0)
			ll->tail = 0;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		// Removing the last node, update the tail pointer
		if (index == ll->size - 1){
			ll->tail = pre;
			free(pre->next);
			pre->next = NULL;
		}
		else{
			cur = pre->next->next;
			free(pre->next);
			pre->next = cur;
		}
		ll->size--;
		return 0;
	}

	return -1;
}
