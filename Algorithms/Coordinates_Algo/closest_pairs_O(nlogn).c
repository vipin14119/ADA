#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INT_MAX 2147483647
typedef struct node
{
	int x;
	int y;
}node;

typedef struct pair
{
	int x1,y1,x2,y2;
	float minV;
}CPair;

CPair CP;
int cmp(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}

int cmp2(const void *a,const void *b)
{
	const node *e1=a;
	const node *e2=b;
	if (e1->y<e2->y)
	{
		return -1;
	}
	else if(e1->y>e2->y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

float distance(node P1,node P2)
{
	float D=sqrt(pow(P1.x-P2.x,2)+pow(P1.y-P2.y,2));
	return D;
}

float Min(float a,float b)
{
	if (a>=b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

CPair MininThree(node Points[],int s,int n)
{
	CPair CP;
	/*float minD=3.402823e+38;*/
	CP.x1=Points[s].x;
	CP.y1=Points[s].y;
	CP.x2=INT_MAX;
	CP.y2=INT_MAX;
	CP.minV=3.402823e+38;
	int i,j;
	for (i=s;i<=n;++i)
	{
		for (j=i+1;j<=n; ++j)
		{
			if (distance(Points[i],Points[j])<CP.minV)
				{
					CP.minV=distance(Points[i],Points[j]);
					CP.x1=Points[i].x;
					CP.y1=Points[i].y;
					CP.x2=Points[j].x;
					CP.y2=Points[j].y;
				}
		}
	}
	//printf("min distance is %f\n",CP.minV);
	return CP;
}

CPair closestAcrossMedian(node Points[],int left,int size,CPair dis)
{
	CPair CP=dis;
	/*float minD=3.402823e+38;*/
	/*CP.x1=Points[left].x;
	CP.y1=Points[left].y;
	CP.x2=INT_MAX;
	CP.y2=INT_MAX;
	CP.minV=dis.minV;*/

	//qsort(Points,size-left+1,sizeof(node),cmp2);
	int i,j;
	for (i = left; i <=size; ++i)
	{
		for (j=i+1;j<=size; ++j)
		{
			if (Points[j].y-Points[i].y<CP.minV)
			{
				if (distance(Points[i],Points[j])<CP.minV)
				{
					CP.minV=distance(Points[i],Points[j]);
					CP.x1=Points[i].x;
					CP.y1=Points[i].y;
					CP.x2=Points[j].x;
					CP.y2=Points[j].y;
				}
			}
		}
	}
	return CP;
}

CPair MinNode(CPair N1,CPair N2)
{
	if (N1.minV<N2.minV)
	{
		return N1;
	}
	else
	{
		return N2;
	}
}

CPair ClosestInParts(node SortX[],node SortY[],int s,int r)
{
	if (r-s<3)
	{
		//printf("s and r is %d and %d\n",s,r);
		return MininThree(SortX,s,r);
	}
	else
	{
		//printf("here is else\n");
		int mid=(s+r)/2;
		node Median=SortX[mid];
		node LeftY[mid],RightY[r-s-mid];
		int i,li=0,ri=0;
		for (i = s; i <=r; i++)
    	{
      		if (SortY[i].x <= Median.x)
         		{
         			LeftY[li++] = SortY[i];
         		}
      		else
         		{
         			RightY[ri++] = SortY[i];
         		}
    	}
    	// li-1, ri-1

		//printf("Median is %d %d\n",Median.x,Median.y );
		CPair minL=ClosestInParts(SortX,LeftY,s,mid-1);
		CPair minR=ClosestInParts(SortX,RightY,mid+1,r);
		CPair minD=MinNode(minL,minR);
		//printf("min is %f\n",minD.minV);
		//printf("size of strip is %d\n",r-s+1 );
		node Strip[r-s+1];
		int size=0;
		for (i=s;i<=r;++i)
		{
			//printf("here i am\n");
			if (abs(SortY[i].x-Median.x)<minD.minV)
			{
				Strip[size]=SortY[i];
				//printf("value of Strip node is %d %d\n",Strip[size].x,Strip[size].y );
				size++;
			}
		}
		//printf("value of size is %d\n",size );
		return MinNode(minD,closestAcrossMedian(Strip,0,size-1,minD));
	}
}

CPair closetPair(node Points[],int s,int r)
{
	node SortX[r-s+1],SortY[r-s+1];
	int i;
	for (i=s;i<=r;++i)
	{
		SortX[i]=Points[i];
		SortY[i]=Points[i];
	}
	qsort(SortX,r-s+1,sizeof(node),cmp);
	qsort(SortY,r-s+1,sizeof(node),cmp2);

	return ClosestInParts(SortX,SortY,s,r);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	node P[n+1];
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d",&P[i].x,&P[i].y);
	}
	CPair CP=closetPair(P,0,n-1);
	printf("Closest Pair is (%d,%d) and (%d,%d) with distance %f\n",CP.x1,CP.y1,CP.x2,CP.y2,CP.minV);
	
	return 0;
}