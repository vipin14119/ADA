#include <stdio.h>

/*
* Author : Vipin Chaudhary
*/
typedef struct Node  //structure for graph vertices
{
	int data;  // to hold the data
	struct Node* next;  // to hold the pointer to next location 
}node;

typedef struct ListNode  // structure of the adjacency list
{
	node* head;  // head pointer of all the vertices 
}LNode;

typedef struct Graph  // structure of the graph
{
	int V;  // number of the vertices in the graph
	LNode * list;  // array of the head pointers of all the vertices
}Graph;

node * createNode(int d)  // function to create a new node
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=d;
	newnode->next=NULL;
	return newnode;
}

Graph* createGraph(int V)  // function to create a new graph
{
	Graph *graph=(graph*)malloc(sizeof(graph));
	graph->V=V;  // number of vertices in the graph
	graph->list=(LNode*)malloc(V*sizeof(LNode));  // dyanmically allocated  array of the number of vertices
	int i;
	for (i=0;i<V;++i)  // initializing all head pointers to NULL
	{
		graph->list[i].head=NULL;
	}
	return graph;
}

void addEdgeD(Graph *graph,int s,int d)  // function to add a new DIRECTED edge between two points
{
	node* newnode=createNode(d);
	if(graph->list[s].head==NULL)  // if its source head is null then just change its head
	{
		head=newnode;
	}
	else  // otherwise traverse through the list and add new node in the end of list
	{
		node* temp=graph->list[s].head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}

void addEdgeU(Graph *graph,int s,int d)  // function to add new UNDIRECTED edge between two vertices
{
	addEdgeD(graph,s,d);
	addEdgeD(graph,d,s);
} 

int main()
{
	
	return 0;
}