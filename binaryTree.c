#include <stdio.h>
#include <stdlib.h>

/*
* Author : Vipin Chaudhary
*/

typedef struct Node  // structure of tree node
{
	int data;  // data of node    
	struct Node* left;  // pointer to left child
	struct Node* right;  // pointer to right child
}node;


typedef struct address  // list to maintain addresses of nodes of binary trees
{
	node* BTnode;
}Map;

node* create(int data)   // function to create new node
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->left=NULL; // no childs in creating a node
	newnode->right=NULL;
	return newnode;
}

void addnode(Map List[],int P,int C)  // function to add an edge between parent and child 
{
	node* current=List[P].BTnode;
	if (current->left!=NULL && current->right!=NULL)  // if node have both childs 
	{
		printf("Cant add more than 2 childrens\n");
	}
	else if (current->left==NULL)    // if there is no left child 
	{
		current->left=List[C].BTnode;
	}
	else  // if there is no right child
	{
		current->right=List[C].BTnode;
	}
}

void printT(node* Root)  // function to print Tree
{
	if(Root!=NULL)
	{
		printf("%d ",Root->data);
		printT(Root->left);
		printT(Root->right);
	}

} 
void init(Map List[],int n)  // function to initialise tree
{
	int i;
	for (i=1; i <=n; ++i)
	{
		node* newnode=create(i);  // create all nodes in starting and add there address to list for better convinience
		List[i].BTnode=newnode;  
	}
}
int main(int argc, char const *argv[])
{
	
	int n,P,C;
	scanf("%d",&n);
	Map List[n+1];
	init(List,n);
	node *Root=List[1].BTnode;  // give addess of first node to root pointer
	int i;
	for (i = 0; i < 6; ++i)
		{
			scanf("%d %d",&P,&C);
			addnode(List,P,C);
		}	
		printT(Root);
		printf("\n");
	return 0;
}