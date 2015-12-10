#include <stdio.h>
#include <stdlib.h>

/*
* Author : Vipin Chaudhary
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

void percolateUp(int last)  // // Function to fit a value to its correct position dragging from bottom to Top
{
	int i=last;
	while(i>1)
	{
		if(Heap[i]<Heap[i/2]) // checking equality with its parent 
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

void insert(int data)  // function to insert a data in the heap
{
	Heap[++last]=data;  // add data to heap at last position
	percolateUp(last);  // fit this data to its correct position
}

void deleteMin()  // function to delete the root(As root is minimum in Min Heap)
{
	printf("%d ",Heap[1]);
	swap(1,last);  // swap root with last position 
	last--;
	percolateDown(1);  // and find the correct position of new root
}

void buildHeap(int A[],int n)  // function to initiate an array to data into heap
{
	int i;
	for (i=1;i<=n;++i)
	{
		insert(A[i]);
	}
}
void heapSort(int A[],int n)  // function to sort the data
{
	int i;
	buildHeap(A,n);  // first build the heap of the data
	for (i=1;i<=n;++i)
	{
		deleteMin();  // delete min from heap exactly n number of times 
	}
	printf("\n");
}
int main()
{
	int n,A[100],i;
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		scanf("%d",&A[i]);
	}
	heapSort(A,n);
	return 0;
}