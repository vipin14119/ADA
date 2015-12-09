// A heap is like a binary tree and it is left justified
#include <stdio.h>
#include <stdlib.h>

/*
* Auhor : Vipin Chaudhary
*/

int Heap[100]; // assume a size of 100 for the heap(Min Heap)
// NOTE : Our heap is 1 based indexing so childrens are 2i & 2i+1
int last=0;  // will be used to keep track of the position of last element in heap

void swap(int i,int j)
{
	int temp=Heap[i];
	Heap[i]=Heap[j];
	Heap[j]=temp;
}
void insert(int data)
{
	Heap[++last]=data;  // add data to heap at last position
	int i=last;
	while(i>1)
	{
		if(Heap[i]<Heap[i/2]) // checking equality with its parent ,
		{
			swap(i,i/2);  //if it is less than parent then swap
			i=i/2; // move current location to its swaped position and check up to the root
		}
		else
		{
			return;
		}

	}
}

int main()
{
	int i,d;
	for (i = 0; i < 5; ++i)
	{
		scanf("%d",&d);
		insert(d);
	}
	for (i = 1; i <= last; ++i)
	{
		printf("%d ",Heap[i] );
	}
	printf("\n");
	insert(3);
	for (i = 1; i <= last; ++i)
	{
		printf("%d ",Heap[i] );
	}
	printf("\n");
	
	return 0;
}
