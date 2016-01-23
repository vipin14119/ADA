#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
	int data;
	int status;
}node;

int cmpfunc (const void * a, const void * b)
{
   return (*(int*)a - *(int*)b);
}

int main()
{
	int t,n,i,c,cm;
	printf("Number of test cases:: \n");
	scanf("%d",&t);
	
	while(t--)
	{
		c=0,cm=0;
		printf("Numeber of pairs:: \n");
		scanf("%d",&n);
		
		node *A=(node*)malloc((2*n+1)*sizeof(node));
		for (i=0;i<2*n;++i)
		{
			if (i%2==0)
			{
				scanf("%d",&A[i].data);
				
				A[i].status=0;	
			}
			else
			{	
				scanf("%d",&A[i].data);
				
				A[i].status=1;
			}			
		}
		qsort(A,2*n,sizeof(node),cmpfunc);
		
		node temp;
		for (i=0;i<2*n;++i)
		{
			if (A[i].data==A[i+1].data && A[i].status==0 && A[i+1].status==1)
			{
				temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;			
			}
		}
	for (i = 0; i < 2*n; ++i)
		{
			if (A[i].status==0)
			{
				c++;				
			}
			else
			{
				c--;
			}
			if(c>=cm)
				{
					cm=c;
				}
		}
		printf("Maximum number of pairs:: %d\n",cm);
	}
}