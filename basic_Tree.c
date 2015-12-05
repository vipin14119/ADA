#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* Author : Vipin Chaudhary
*/

typedef struct node // node of tree
{
	int element;  // data of node 
	struct node *nextS; // pointer to next (sibling) NOTE: this is sibling NOT child
}node;

typedef struct graph // Tree as a structure of graph
{
	int element;  // data of node
	node * head; // pointer to first child of node
}Graph; 

void initTree(Graph Tree[],int n)  // function initialise the tree
{
	int i;
	for (i = 1; i <=n; i++)
	{
		Tree[i].element=i; // assume data is its index number
		Tree[i].head=NULL;  // there is no child in starting 
	}
	printf("Tree initialised\n");
}

node * create(int element)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->element=element;
	newnode->nextS=NULL;
	return newnode;
}
void addChild(Graph Tree[], int P,int C)  // add child C of the particular node P
{
	node *child=create(C);   // first create the child node
	node *temp;              // to treverse thgrough the list of particular node siblings 

	if(Tree[P].head==NULL)   // if there is NO child to this node
	{
		Tree[P].head=child;  // update the head from null to first child C
	}
	else
	{
		temp=Tree[P].head;
		while(temp->nextS!=NULL)
		{
			temp=temp->nextS;
		}
		temp->nextS=child;
	}
	printf("Child added with parent %d\n",P);
}

void printTree(Graph Tree[],int n)  // print the Tree Structure 
{
	int i;
	node *temp;

	for (i = 1; i <=n; i++)
	{
		printf("%d :",Tree[i].element);
		
		if(Tree[i].head==NULL)
		{
			printf("-> NULL\n");
		}
		else
		{
			temp=Tree[i].head;
			while(temp)
			{
				printf("-> %d",temp->element);
				temp=temp->nextS;
			}
			printf("-> NULL\n");
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,in;
	int P,C;
	printf("enter the nodes of tree\n");
	scanf("%d",&n);
	Graph Tree[n+1];
	initTree(Tree,n);
	while(1)
	{
		printf("Enter the choice\n");
		scanf("%d",&in);
		if(in==0)
		{
			printf("Enter parent and child \n");
			scanf("%d %d",&P,&C);
			addChild(Tree,P,C);		
		}
		else
		{
			printTree(Tree,n);
		}
	}
	
	return 0;
}