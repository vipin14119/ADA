#include <stdio.h>
#include <stdlib.h>

/*
* Author : Vipin Chaudhary
*/

typedef struct Node // structure of AVl tree node
{
	int data,h; // stores data and nodes height
	struct Node *left,*right;

}node;

node* create(int d)  // function to create new node
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->h=1;  //  initialize height with 1
	return newnode;
}

int height(node* root)  // function to find height of node   
{
	if(root==NULL)
		return -1;
	else
		return root->h;
}

int max(int a,int b)
{
	if(a>=b)
	{
		return a;
	}
	else{
		return b;
	}
}
node* RR(node* root)  // Right Rotation
{
	node *temp,*current;
	current=root->left;
	temp=current->right;

	// Update pointers for rotation
	current->right=root;
	root->left=temp;

	// update heights of updated nodes

	// height is max of both subtrees
	root->h=max(height(root->left),height(root->right))+1;
	current->h=max(height(current->left),height(current->right))+1;

	return current;  // new root
}

node* LR(node* root)  // Left Rotation
{
	node *temp,*current;

	current=root->right;
	temp=current->left;

	// Update pointers for rotation
	current->left=root;
	root->right=temp;

	// update heights of updated nodes

	// height is max of both subtrees
	root->h=max(height(root->left),height(root->right))+1;
	current->h=max(height(current->left),height(current->right))+1;

	return current;  // new root
}

int check(node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

node* addnode(node *root,int d)
{
	// Normal BST insertion

	if(root==NULL)
	{
		return create(d);
	}
	if(d<root->data)
	{
		root->left=addnode(root->left,d);
	}
	else
	{
		root->right=addnode(root->right,d);
	}

	// update height of this inseted node

	root->h=max(height(root->left),height(root->right))+1;

	int C=check(root);
	// Left Left
	if(C>1 && d<root->left->data)
	{
		return RR(root);
	}
	// Right Right
	if (C<-1 && d>root->right->data)
	{
		return LR(root);
	}
	// Left right
	if (C > 1 && d> root->left->data)
    {
        root->left =  LR(root->left);
        return RR(root);
    }
    // Right Left 
    if (C < -1 && d < root->right->data)
    {
        root->right = RR(root->right);
        return LR(root);
    }
 
    /* return the (unchanged) node pointer */
    return root;
}

void preOrder(node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(int argc, char const *argv[])
{
	node* root=NULL;
	/* Constructing tree given in the above figure */
  root = addnode(root, 1);
  root = addnode(root, 3);
  root = addnode(root, 4);
  root = addnode(root, 5);
  root = addnode(root, 6);
  root = addnode(root, 2);
 
  printf("Pre order \n");
  preOrder(root);
  printf("\n");
	
	return 0;
}