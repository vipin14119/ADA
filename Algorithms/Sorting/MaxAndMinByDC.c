#include <stdio.h>

typedef struct  n
{
	int max;
	int min;
}node;

node check(int a,int b)
{
	node N;
	if(a>=b)
	{
		N.max=a;
		N.min=b;
	}
	else
	{
		N.min=a;
		N.max=b;
	}
	return N;
}

int max(int a,int b)
{
	if(a>=b)
	{
		return a;
	}		
	else
	{	
		return b;
	}
}

int min(int a,int b)
{
	if(a>=b)
	{
		return b;
	}		
	else
	{	
		return a;
	}
}

	node Find(int A[],int l,int r)
	{
		node N;
		if(r==l+1)
		{
			N.max=max(A[l],A[r]);
			N.min=min(A[l],A[r]);
			//N=check(A[l],A[r]);
			return N;
		}
		else if(l==r)
		{
			N.max=A[l];
			N.min=A[l];
			return N;
		}
		else
		{
			int mid=(l+r)/2;
			node Al=Find(A,l,mid);
			node Rl=Find(A,mid+1,r);
			N.max=max(Al.max,Rl.max);
			N.min=min(Al.min,Rl.min);
			return N;
		}
	}
	int main()
	{
		int n;
		node N;
		scanf("%d",&n);
		int A[n+1];
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
		}
		N=Find(A,0,n-1);
		printf("Max is %d and Min is %d\n",N.max,N.min);
	}
