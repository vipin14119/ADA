#include <stdio.h>
/*
* Author Name : Vipin Chaudhary
*/

void merge(int A[],int s,int m,int r)
{
	int n1,n2;
	n1=m-s+1;
	n2=r-m;
	int Left[n1],Right[n2];
	int i,j,k;
	for (i=0;i<n1; ++i)
	{
		Left[i]=A[s+i];
	}
	for (j=0;j<n2; ++j)
	{
		Right[j]=A[m+j+1];
	}
	i=0,j=0,k=s;
	while(i<n1 && j<n2)
	{
		if (Left[i]<=Right[j])
		{
			A[k]=Left[i];
			i++;
		}
		else
		{
			A[k]=Right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		A[k]=Left[i];
		i++;k++;
	}
	while(j<n2)
	{
		A[k]=Right[j];
		j++;k++;
	}

}

void mergeSort(int A[],int s,int r)
{
	if(s<r)
	{
		int m=(s+r)/2;
		mergeSort(A,s,m);
		mergeSort(A,m+1,r);
		merge(A,s,m,r);
	}
}
int main()
{
	int arr[] = {2,1,5,3,15,7,3,7,23,0};
    mergeSort(arr, 0, 9);
 
    printf("\nSorted array is \n");
    int i;
    for (i=0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
	return 0;
}