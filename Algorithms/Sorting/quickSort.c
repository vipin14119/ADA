#include <stdio.h>

void quicksort(int A[],int left,int right)
{
	int pivot,temp,i,j;
	if(left<right)
	{
		pivot=(left+right)/2;
		i=left;
		j=right;
		while(i<j)
		{
			while(A[i]<=A[pivot])
			{
				i++; 
			}
			while(A[j]>A[pivot])
			{
				j--;
			}
			if (i<j)
			{
				temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
		temp=A[pivot];
		A[pivot]=A[j];
		A[j]=temp;

		quicksort(A,left,j-1);
		quicksort(A,j+1,right);
	}
}
int main()
 {
 	int A[]={4,2,8,7,0,5,3};
 	quicksort(A,0,6);
 	int i;
 	for (i = 0; i < 7; ++i)
 	{
 		printf("%d ",A[i]);
 	}
 	printf("\n");
 	return 0;
 }