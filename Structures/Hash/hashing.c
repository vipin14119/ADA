// This is seperate chaning hasing method

#include <stdio.h>
#include <stdlib.h>

/* 
* Author ;  Vipin chaudhary
*/

typedef struct Node 
{
	int data;
	struct Node* next;
}node;

typedef struct List
{
	node* head;
}List;
List list[107];

node* create(int data)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
int func(int data)
{
	// Choose your own good hasinng function ,i choosed the simplest one
	return data%107;
}

void addData(int data)  //  function to add data to your list
{
	node *newnode=create(data);
	int i=func(data); // index return by the function 
	if(list[i].head==NULL)  // if there is no data in that index than update the head to the the first data
	{
		list[i].head=newnode;	
	}
	else  // if there is already data in the index than just append another node to the link list
	{
		node* temp=list[i].head; 
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
int main(int argc, char const *argv[])
{
	int i,d;
	for(i=0;i<6;i++)
	{
		scanf("%d",&d);
		addData(d);
	}
	return 0;
}