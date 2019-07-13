// CX1007 DataStructures
// Week 12 Lab Tutorial - Binary Tree

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////
////////////

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;

} BTNode;

////////////////////////////////////////////////////////////////////
////////////

void mirrorTree(BTNode *node);

void printSmallerValues(BTNode *node, int m);
int smallestValue(BTNode *node);
int hasGreatGrandchild(BTNode *node);

void printTree_InOrder(BTNode *node);

////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]){

	int i;
	BTNode *root, *root2;
	BTNode btn[15]; //Array of structures, memory allocated already (15 structures).

	// Create the tree in Q1
	// Using manual dynamic allocation of memory for BTNodes

	root = malloc(sizeof(BTNode)); //Creates the root node
	root->item = 4; //Initiates the root node item

	root->left = malloc(sizeof(BTNode)); //Creates the left node
	root->left->item = 5; //Initiates the value of the left node as 5

	root->right = malloc(sizeof(BTNode)); //Creates the right node of the root node
	root->right->item = 2;//Initiates the item of the right node of the root node as 2

	root->left->left = NULL; //Sets the left node of the left node of the root node as NULL

	root->left->right = malloc(sizeof(BTNode));//Creates a right node at the left node of the root node
	root->left->right->item = 6;//Initiates the value of this node as 6

	root->left->right->left = NULL;
	root->left->right->right = NULL;

	root->right->left = malloc(sizeof(BTNode));
	root->right->left->item = 3;

	root->right->right = malloc(sizeof(BTNode));
	root->right->right->item = 1;

	root->right->left->left = NULL;

	root->right->left->right = NULL;

	root->right->right->left = NULL;

	root->right->right->right = NULL;
	//This hard codes out the binary tree.

	printTree_InOrder(root);
	printf("\n");
	mirrorTree(root);
	printTree_InOrder(root);
	printf("\n\n");

	//question 2
	printf("\n input m for question 2:");
	scanf("%d", &i);
	printf("the values smaller than %d are:", i);
	printSmallerValues(root, i);
	printf("\n\n");

	//question 3
	printf("The smallest value in the tree is %d:\n", smallestValue(root));

	//question 4
	// Create a tree for Q4: Tall enough so some nodes have great-grandchildren
	// Use array of BTNodes, create tree by linking nodes together
	for (i = 0; i <= 6; i++){
		btn[i].item = i;
		btn[i].left = &(btn[i * 2 + 1]);
		btn[i].right = &(btn[i * 2 + 2]);
	}

	for (i = 7; i <= 14; i++){
		btn[i].item = i;
		btn[i].left = NULL;
		btn[i].right = NULL;
	}
	root2 = &btn[0];

	printf("The tree for question 4 visited by in-order is \n");
	printTree_InOrder(root2);
	printf("\nthe values stored in all nodes of the tree that have at least one great-grandchild are: ");
	/*btn[13].right=malloc(sizeof(BTNode));
	btn[13].right->item = 15;
	btn[13].right->left = NULL;
	btn[13].right->right=NULL; */
	hasGreatGrandchild(root2);

	return 0;
}

void mirrorTree(BTNode *node){
    BTNode *temp; //This is used as a temporary pointer for the swapping.

    if(node == NULL)
    {
        /*Do nothing for terminating case*/
        return;
    }
    else
    {
        //swap left and right node
        temp = node->left;
        node->left=node->right;
        node->right=temp;

        mirrorTree(node->left);
        mirrorTree(node->right);
        //This is pre-order. You can use post-order. However, in-order does not work.
    }
}

int hasGreatGrandchild(BTNode *node){
    //This recursive function returns an integer. This is to take advantage of the common property of nodes with great grandchildren.
    //Nodes that have great grandchildren have height greater than or equal to 3.
    //Therefore, we create a function with return value is the height of the node and print out the nodes with height greater than or equal to zero
    int height, l, r;

    //Calculate the height of the height of each node in the tree
    //Print out (data stored in) node that has height > n
    if(node == NULL)
    {
        return -1; //This is so that when we have a leaf node, we will get height = -1+1 = 0.
    }
    else
    {
        l = hasGreatGrandchild(node->left); //will print out nodes that have great-grandchildren in both subtrees
        r = hasGreatGrandchild(node->right);

        if(l>r) //left node has greater height than right node
            height = 1+l;
        else
            height = 1+r;

        if(height>=3) //nodes with great-grandchildren have height >=3
            printf("%d", node->item);

        return height;
    }
}

void printSmallerValues(BTNode *node, int m){
    //Similar to the code for printTree_InOrder
    if(node==NULL)
        return;
    printSmallerValues(node->left,m);

    if(node->item<m)
        printf("%d", node->item);

    printSmallerValues(node->right, m);
    //In order
}

int smallestValue(BTNode *node) {
	int l, r;

	// write your code here
	if(node==NULL)
    {
        return INT_MAX; //This is so as to return a very big integer such that the leaf node returns the value in the leaf node. WHen you do this, you must include limits.h at the start.
    }
    else
    {
        l = smallestValue(node->left);
        r = smallestValue(node->right);

        if(l<node->item&&l<r)
            return l;
        else if (r<node->item&&r<l);
            return r;
        else
            return node->item;
    }
}


//////////////////////////////////////////////////////////////////

void printTree_InOrder(BTNode *node){

	if (node == NULL) return;
	printTree_InOrder(node->left);
	printf("%d, ", node->item);
	printTree_InOrder(node->right);
	return;
}
