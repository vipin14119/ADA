#include <stdio.h>
#include <stdlib.h>

/*
* Author : Vipin Chaudhary
*/

typedef struct Node // structure of node
{
	int data;  // stores data
	struct Node* left;  // pointer to left child
	struct Node* right;  // pointer to right child
}node;

node *create(int d)  // function to create node
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
node* addnode(node* root,int d)  // function to insert node in BST
{
	if(root==NULL)  // if tree is empty
	{
		return create(d);  // create its first node and return its address
	}
	else if (d<root->data)  // If data is less than current node data then move to its left subtree
	{
		root->left=addnode(root->left,d);
	}
	else  // If data is greater then current node data then move to right subtree
	{
		root->right=addnode(root->right,d);
	}
	return root; // return its address
}

void search(node* root,int d)  // function to search data in BSt
{
	if(root==NULL )  // If tree is empty 
	{
		printf("Tree empty\n");
	}
	if(root->data==d)  // if data is in current node then raise founded
	{
		printf("Founded \n"); 
		
	}
	else if(root->data<d)  // If data is greater than current node data then move to right subtree
	{
		search(root->right,d);
	}
	else if (root->data>d)  // If data is less than current node data then move to left subtree
	{
		search(root->left,d);
	}
	else  // IF data is not in tree
	{
		printf("Not founded\n");
	}
}

void printT(node* root)  // function to print tree(Preorder)
{
	if(root!=NULL)
	{
		printf("%d ",root->data );
		printT(root->left);
		printT(root->right);
	}
}
void findMin(node * root) // function to find minimum data in the tree
{
	if(root==NULL)  // if tree is empty
	{
		printf("Tree empty\n");
	}
	else if (root->left==NULL)  // if there is no left child of current node then its min
	{
		printf("%d\n",root->data );
	}
	else  // if there is left child then move to left subtree
	{
		findMin(root->left);
	}
}
void findMax(node * root)   // function to find maximum data in the tree
{
	if(root==NULL)  // if tree is empty
	{
		printf("tree empty\n");
	}
	else if(root->right==NULL)  // if there is no right child of current node then its max
	{
		printf("%d\n",root->data );
	}
	else  // if there is right child then move to right subtree
	{
		findMax(root->right);
	}
}
int main(int argc, char const *argv[])
{
	
	node* root=NULL;
	int i,d;
	for(i=0;i<6;i++)
	{
		scanf("%d",&d);
		root=addnode(root,d);
	}
	printT(root);
	printf("\nEnter\n");
	scanf("%d",&d);
	search(root,d);
	
	findMin(root);
	findMax(root);
	return 0;
}