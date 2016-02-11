#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int A[],int l,int r)
{
	int i;
	for (i=l;i<=r; ++i)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}
int findMedian(int A[],int l,int r,int k)
{
	printf("A is \n");
	print(A,l,r);
	int L[l-r+1],M[l-r+1],R[l-r+1];
	memset(L,0,sizeof(L));
	memset(M,0,sizeof(M));
	memset(R,0,sizeof(R));
	int left=0,mid=0,right=0;
	int random=A[(l+r)/2];
	printf("random is %d\n",random );
	int i;
	for (i = l; i <=r ; ++i)
	{
		if (A[i]==random)
		{
			M[mid++]=A[i];
		}
		else if (A[i]<random)
		{
			L[left++]=A[i];
		}
		else if (A[i]>random)
		{
			R[right++]=A[i];
		}
	}
	printf("L is \n");
	print(L,0,left-1);
	printf("M is \n");
	print(L,0,mid);
	printf("R is \n");
	print(L,0,right-1);
	printf("left %d mid %d right %d\n",left,mid,right );
	/*if (k<=left)
	{
		printf("I am here in left\n");
		findMedian(L,0,left,k);
	}
	else if (k<=left+mid && k>left)
	{
		printf("I am here in mid\n");
		return random;
	}
	else
	{
		printf("I am here in right\n");
		findMedian(L,mid,right-1,k-mid-left-1);
	}*/

}
int  main()
{
	int A[]={0,0,1,1,2,2,2};
	printf("%d\n",findMedian(A,0,6,5/2));
	return 0;
}