//////////////////////////////////////////////////////////////////////

// CE1007/CZ1007 Data Structures
// Week 13 Lab and Tutorial - Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
int item;
struct _btnode *left;
struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value) //Double indirection since we need the address of the root node just like insert node function for linked list
{
	if(*node==NULL) {
        *node = malloc(sizeof(BTNode));
        (*node)->item = value;
        (*node)->left=NULL;
        (*node)->right=NULL;
        return;
	}
	//*node != NULL
	if(value<(*node)->item)
        insertBSTNode(&((*node)->left), value);
    else if(value>(*node)->item)
        insertBSTNode(&((*node)->right), value);
    else printf("Already exist in the BST\n"); //This is to prevent repeating values from added into the BST
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	if(node==NULL)
        return;
    printBSTInOrder(node->left);
    printf("%d", node->item);
    printBSTInOrder(node->right);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	//min and max is to provide a range to check whether the value in the node is within that range
	if(node==NULL)
        return 1; //An empty tree is still a BST
    //The node's value should belong to (min, max)
    if(node->item <= min || node->item >= max)
        return 0;
    //Its left node should be smaller than node->item
    //Its right node should be larger than node->item
    return isBST(node->left, min, node->item) && isBST(node->right, node->item, max);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
    BTNode *temp;

    if(node==NULL) {
        printf("value not found in BST\n");
        return NULL; //or return node;
    }
    if(value < node->item)
        node->right = removeBSTNode(node->left, value);
    else if (value > node->item)
        node->right = removeBSTNode(node->right, value);
    else { //Found the node to be removed
        //It has both left and right child nodes
        if(node->left!=NULL&&node->right!=NULL) {
            temp = findMin(node->right);
            node->item = temp->item;
            node->right = removeBSTNode(node->right, temp->item);
        }
        else //It has <= 1 child node
        {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else
                node = node->left;
            free(temp);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p) //For a BST, the minimum node is located at the leftmost, so just keep moving left. No need to use recursion, can just use iteration.
{
    if(p==NULL)
        return NULL;

    while (p->left != NULL) //Move p leftwards until it is the leftmost node
        p = p->left;

    return p;
}

/////////////////////////////////////////
