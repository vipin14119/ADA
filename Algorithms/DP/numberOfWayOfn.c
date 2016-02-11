#include <stdio.h>
#include <string.h>
int M[10000][10000];
int P(int n,int m)
{
	if(n<=1)
	{
		return 1;
	}
	else if(m>n)
	{
		return P(n,n);
	}
	else
	{
		if(M[n][m]!=-1)
		{
			return M[n][m];
		}
		else
		{
			int sum=0;
			int i;
			for(i=1;i<=m;i++)
			{
				sum+=P(n-i,i);
			}
			M[n][m]=sum;
			return sum;
		}
	}
}
int main()
{
	memset(M,-1,sizeof(M));
	int n;
	scanf("%d",&n);
	printf("n of %d is %d\n",n,P(n,n-1));
}