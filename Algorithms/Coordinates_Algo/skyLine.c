#include <stdio.h>
#include <stdlib.h>


typedef struct Snode
{
	int x;
	int height;
}SkylineStrips;

typedef struct S
{
	SkylineStrips *SkylineArray;
	int len;
}Skyline;

Skyline * createSkyline(int size)
{
	Skyline * S=(Skyline*)malloc(sizeof(Skyline));
	S->len=size;
	S->SkylineArray=(SkylineStrips*)malloc(size*sizeof(SkylineStrips));	
	return S;
}


typedef struct b
{
	int x1;	
	int heightOfBuilding;
	int x2;
}building;

void print(Skyline *S)
{
	int i;
	for(i=0;i<S->len;i++)
	{
		printf("%d %d\n",S->SkylineArray[i].x,S->SkylineArray[i].height);
	}
}

int max(int h1,int h2)
{
	if(h1<=h2)
	{
		return h2;
	}
	else
	{
		return h1;
	}
}

Skyline * mergeSkyline(Skyline *S1,Skyline *S2)
{
	SkylineStrips Temp;
	Skyline *S=createSkyline(S1->len+S2->len);
	int i=0,j=0,k=0,h1=0,h2=0;
	while(i<S1->len && j<S2->len)
	{
		if (S1->SkylineArray[i].x<=S2->SkylineArray[j].x)
		{
			Temp.x=S1->SkylineArray[i].x;
			h1=S1->SkylineArray[i].height;
			Temp.height=max(h1,h2);
			if (S->SkylineArray[k-1].height!=Temp.height)
			{
				if (k>0)
				{
					if (S->SkylineArray[k-1].x==Temp.x)
					{
						S->SkylineArray[k-1].height=max(S->SkylineArray[k-1].height,Temp.height);
						i++;
					}
					else
					{
						S->SkylineArray[k]=Temp;
						k++;
						i++;	
					}
				}
				else
				{
					S->SkylineArray[k]=Temp;
						k++;
						i++;
				}
				
			}
			else
			{
				i++;
				continue;
			}
		}
		else
		{
			Temp.x=S2->SkylineArray[j].x;
			h2=S2->SkylineArray[j].height;
			Temp.height=max(h1,h2);
			if (S->SkylineArray[k-1].height!=Temp.height)
			{
				if (k>0)
				{
					if (S->SkylineArray[k-1].x==Temp.x)
					{
						S->SkylineArray[k-1].height=max(S->SkylineArray[k-1].height,Temp.height);
						j++;
					}
					else
					{
						S->SkylineArray[k]=Temp;
						k++;
						j++;
					}
				}
				else
				{
					S->SkylineArray[k]=Temp;
						k++;
						j++;
				}
			}
			else
			{
				j++;
				continue;
			}	
		}
	}
	while(i<S1->len)
	{
		Temp.x=S1->SkylineArray[i].x;
		//h1=S1->SkylineArray[i].height;
		Temp.height=S1->SkylineArray[i].height;
			if (S->SkylineArray[k-1].height!=Temp.height)
			{
				if (k>0)
				{
					if (S->SkylineArray[k-1].x==Temp.x)
					{
						S->SkylineArray[k-1].height=max(S->SkylineArray[k-1].height,Temp.height);
						i++;
					}
					else
					{
						S->SkylineArray[k]=Temp;
						k++;
						i++;	
					}
				}
				else
				{
					S->SkylineArray[k]=Temp;
						k++;
						i++;
				}
				
			}
			else
			{
				i++;
				continue;
			}
	}
	while(j<S2->len)
	{
		Temp.x=S2->SkylineArray[j].x;
			//h2=S2->SkylineArray[j].height;
			Temp.height=S2->SkylineArray[j].height;
			if (S->SkylineArray[k-1].height!=Temp.height)
			{
				if (k>0)
				{
					if (S->SkylineArray[k-1].x==Temp.x)
					{
						S->SkylineArray[k-1].height=max(S->SkylineArray[k-1].height,Temp.height);
						j++;
					}
					else
					{
						S->SkylineArray[k]=Temp;
						k++;
						j++;
					}
				}
				else
				{
					S->SkylineArray[k]=Temp;
						k++;
						j++;
				}
			}
			else
			{
				j++;
				continue;
			}
	}
	S->len=k;
	return S;

}

Skyline* SkylineBuild(building B[],int left,int right)
{
	if (left==right)
	{
		Skyline * S=createSkyline(2);
		S->SkylineArray[0].x=B[left].x1;
		S->SkylineArray[0].height=B[left].heightOfBuilding;
		S->SkylineArray[1].x=B[left].x2;
		S->SkylineArray[1].height=0;
		return S;
	}
	else
	{
		int mid=(left+right)/2;
		Skyline *S1=SkylineBuild(B,left,mid);
		Skyline *S2=SkylineBuild(B,mid+1,right);
		Skyline *S=mergeSkyline(S1,S2);
		return S;
	}
}
int main()
{
	building B[]={{1, 11, 5}, {2, 6, 7}, {3, 13, 9},
                      {12, 7, 16}, {14, 3, 25}, {19, 18, 22},
                      {23, 13, 29}, {24, 4, 28}};
	Skyline *S;
	S=SkylineBuild(B,0,7);
	printf("Skyline is \n");
	print(S);
	return 0;
}