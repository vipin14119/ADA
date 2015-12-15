#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	Graph *graph=(Graph*)malloc(sizeof(Graph));
	graph->V=V;  // number of vertices in the graph
	graph->list=(LNode*)malloc(V*sizeof(LNode));  // dyanmically allocated  array of the number of vertices
	int i;
	for (i=0;i<V;++i)  // initializing all head pointers to NULL
	{
		graph->list[i].head=NULL;
	}
	return graph;
}

void addEdgeD(Graph *graph,int s,int d,int Indegree[])  // function to add a new DIRECTED edge between two points
{
	Indegree[d]++;
	node* newnode=createNode(d);
	if(graph->list[s].head==NULL)  // if its source head is null then just change its head
	{
		graph->list[s].head=newnode;
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

void addEdgeU(Graph *graph,int s,int d,int Indegree[])  // function to add new UNDIRECTED edge between two vertices
{
	addEdgeD(graph,s,d,Indegree);
	addEdgeD(graph,d,s,Indegree);
} 
int f=-1,e=-1;
void enque(int Q[],int D)
{
	if(e<0)
	{
		Q[++e]=D;
		f++;
	}
	else
	{
		Q[++e]=D;
	}
}
int isEmpty()
{
	if(e<0 || f>e)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}
int deque(int Q[])
{
	int R;
	if (e<0)
	{
		printf("Queue empty\n");
	}
	else if(e==0)
	{
		R=Q[0];
		e=-1;
		f=-1;
	}
	else if(f==e)
	{
		R=Q[f];
		f=-1;
		e=-1;
	}
	else
	{
		R=Q[f];
		f++;
	}
	return R;
}
void topSort(Graph *graph,int Indegree[],int TopNum[])
{
	int Q[graph->V];
	int i;
	int counter=0;
	int flag=-1;
	for (i=0;i<graph->V;++i)
	{
		if(Indegree[i]==0)
		{
			enque(Q,i);
			flag=1;
		}
	}
	if (flag==-1)           ///////////////////////////////// PROBLEM IN CODE HERE////////////////////////
	{
		/* code */
	}
	while(isEmpty()!=0)
	{
		int W=deque(Q);
		TopNum[W]=++counter;
		node* temp=graph->list[W].head;
		while(temp)
		{
			if (--Indegree[temp->data]==0)
			{
				enque(Q,temp->data);
			}
		}
	} 
	if(counter!=graph->V)
	{
		printf("Error\n");
	}
	for (i = 0; i < graph->V; ++i)
	{
		printf("%d ",TopNum[i]);
	}
	printf("\n");
}
void printGraph(Graph *graph)
{
	int i;
	for (i = 0; i < graph->V; i++)
	{
		printf("%d : ",i );
		node* temp=graph->list[i].head;
		while(temp)
		{
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
int main()
{
	Graph * graph=createGraph(7);
	int Indegree[7];
	int TopNum[7];
	int i;
	memset(Indegree,0,sizeof(Indegree));
	addEdgeD(graph,0,1,Indegree);
	addEdgeD(graph,0,2,Indegree);
	addEdgeD(graph,1,3,Indegree);
	addEdgeD(graph,1,4,Indegree);
	addEdgeD(graph,2,0,Indegree);
	addEdgeD(graph,2,5,Indegree);
	addEdgeD(graph,3,2,Indegree);
	addEdgeD(graph,3,4,Indegree);
	addEdgeD(graph,3,5,Indegree);
	addEdgeD(graph,3,6,Indegree);
	addEdgeD(graph,4,6,Indegree);
	addEdgeD(graph,6,5,Indegree);

	printGraph(graph);
	for (i = 0; i < graph->V; ++i)
	{
		printf("%d ",Indegree[i] );
	}
	printf("\n");
	topSort(graph,Indegree,TopNum);
	for (i = 0; i < graph->V; ++i)
	{
		printf("%d ",TopNum[i] );
	}
	printf("\n");

	return 0;
}