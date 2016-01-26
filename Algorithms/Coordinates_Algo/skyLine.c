#include <stdio.h>
#include <stdlib.h>

/*
* Author : Vipin Chaudhary
*/

// complexity id O(nlogn)

typedef struct Snode  // structure of skyline strips 
{
	int x;  // x coordinate of strip
	int height;  // height of strip
}SkylineStrips;

typedef struct S  // structure of Skyline 
{
	SkylineStrips *SkylineArray;  // Array of Skyline
	int len;  // Size of Skyline array
}Skyline;

Skyline * createSkyline(int size)  // function to create a skyline
{
	Skyline * S=(Skyline*)malloc(sizeof(Skyline));  // creating a space for skyline
	S->len=size; // length of skyline
	S->SkylineArray=(SkylineStrips*)malloc(size*sizeof(SkylineStrips));  // mallocing array of appropiate size	
	return S;  // returning its address
}


typedef struct b  // structure of buildings
{
	int x1;	 // left coordinate
	int heightOfBuilding;  // height
	int x2;  // right coordinate
}building;


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

Skyline* addinResult(Skyline* S,SkylineStrips Temp)  // function to add strip into resulting skyline
{
	if (S->len==0)  // if len of Skyline is 0 ,then add the strip
	{
		S->SkylineArray[S->len]=Temp;  // add the strip
		S->len++;  // increment the Skyline length
		return S;
	}
	else if (S->len>0 && S->SkylineArray[S->len-1].height!=Temp.height)  // if len is greater than 0 and strip height is not equal to previous strip in resulting skyline
	{
			if (S->SkylineArray[S->len-1].x==Temp.x)  // if strip cordinate is equal to previous strip in resulting skyline 
			{
				S->SkylineArray[S->len-1].height=max(S->SkylineArray[S->len-1].height,Temp.height);  // then update the previous strip height to max of them and do not add stip into skyline
				return S;
			}
			else
			{
				S->SkylineArray[S->len]=Temp;  // if strips height and coordinate is not equal to previous strip then add it to skyline
				S->len++;  // increment skyline size
				return S;
			}
	}
	else  // if strip height of strip is equal to previous strip height then dont do anything just return 
	{
		return S;
	}  
}

Skyline * mergeSkyline(Skyline *S1,Skyline *S2)  // function to merge two skyline (Just as merge function of mergeSort)
{
	SkylineStrips Temp;  // create a temp strip we will decide if its going to be add in resulting skyline or not
	Skyline *S=createSkyline(S1->len+S2->len);  // create a skyline of appropriate size(This is out Resulting skyline)
	S->len=0;  // make the skyline empty
	int i=0,j=0;  // initiate both skylines indexes from zero
	int h1=0,h2=0;  // initiate height of both strips to 0
	while(i<S1->len && j<S2->len)  // loop till one of them gets empty
	{
		if (S1->SkylineArray[i].x<=S2->SkylineArray[j].x)  // if coordinate of S1 is less than S2
		{
			Temp.x=S1->SkylineArray[i].x;  // then select that coordinate 
			h1=S1->SkylineArray[i].height;  // update the h1 as S1 is selected
			Temp.height=max(h1,h2);  // choose the max between h1 and h2
			S=addinResult(S,Temp);  // check its redundancy if its alloweded then it will be added to resulting skyline S
			i++;  // increments S1 index 

		}
		else  // if coordinate of S1 is greater than S2
		{
			Temp.x=S2->SkylineArray[j].x;  // then select S2 coordinate
			h2=S2->SkylineArray[j].height;  // update h2 as S2 is selected
			Temp.height=max(h1,h2);  // choose max
			S=addinResult(S,Temp);  // again check the Temp strip to add
			j++;	// increment S2 index			
		}
	}

	// Now take the remaining strips that must be left in one of the S1 or S2 , just check their redundancy and add them to result
	while(i<S1->len)
	{
		Temp.x=S1->SkylineArray[i].x;
		Temp.height=S1->SkylineArray[i].height;
		S=addinResult(S,Temp);
		i++;	
	}
	while(j<S2->len)
	{
		Temp.x=S2->SkylineArray[j].x;
			Temp.height=S2->SkylineArray[j].height;
			S=addinResult(S,Temp);
			j++;
	}

	return S;  // Return resulting merged Skyline

}

Skyline* SkylineBuild(building B[],int left,int right)  // function to recursively divide the buildings to convert them to skylines
{
	if (left==right)  // if only one building then there will be two strips in skyline
	{
		Skyline * S=createSkyline(2);  // skyline of size 2
		S->SkylineArray[0].x=B[left].x1;  // Strip 1
		S->SkylineArray[0].height=B[left].heightOfBuilding;
		S->SkylineArray[1].x=B[left].x2;  // Strip 2
		S->SkylineArray[1].height=0;
		return S;
	}
	else  // if more than 1 building 
	{
		// divide it into two parts , recuresily solve them and then merge them 
		int mid=(left+right)/2;
		Skyline *S1=SkylineBuild(B,left,mid);  // first half
		Skyline *S2=SkylineBuild(B,mid+1,right);  // second half
		Skyline *S=mergeSkyline(S1,S2);  // Merge both halfs
		return S;  // return result
	}
}


void print(Skyline *S)  // function to print the skyline
{
	int i;
	for(i=0;i<S->len;i++)
	{
		printf("%d %d\n",S->SkylineArray[i].x,S->SkylineArray[i].height);
	}
}

int main()
{
	building B[]={{2, 6, 7}, {3, 13, 9},{3,7,8}
                      ,{12, 7, 16}, {14, 3, 25}, {19, 18, 22},
                      {23, 13, 29}, };
	Skyline *S;
	S=SkylineBuild(B,0,6);
	printf("Skyline is \n");
	print(S);
	return 0;
}