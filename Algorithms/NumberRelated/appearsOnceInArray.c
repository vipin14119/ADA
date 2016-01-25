#include <stdio.h>

/*
* Author : Vipin Chaudhary
*/

// Complexity O(Logn)

// Below function runs only on sorted array
int findTheElement(int A[],int s,int r)  // function to find the element which appears only once in array
{

	// Binary Search Approach
	if (s>r)
	{
		return ;
	}
	if (r==s)
	{
		return A[s];
	}
	else
	{
		int mid=(r+s)/2;
		if (mid%2==0)
		{
			if (A[mid]==A[mid+1])
			{
				return findTheElement(A,mid+1,r);
			}
			else
			{
				return findTheElement(A,s,mid);
			}
		}
		else
		{
			if (A[mid]==A[mid+1])
			{
				return findTheElement(A,s,mid);
			}
			else
			{
				return findTheElement(A,mid+1,r);
			}
		}
	}
}

// O(n) approach
// Below function runs only on any array
int findTheE(int A[],int s,int r) // function the find the required element
{
	int ans=A[s];
	int i;
	for (i = s+1; i <= r; ++i)
	{
		ans^=A[i];
	}
	return ans;
}
int main()
{
	// Input arrays in both functions containe only one element which appears only once in array and all other elements comes exactlt 2 times.
	int A[]={1,2,2,4,4,5,5,6,6}; // Sorted Array
	printf("%d\n",findTheElement(A,0,8)); // output 1
	int B[]={2,5,2,1,5,4,6,4,6};
	printf("%d\n",findTheE(B,0,8));   //output 1
	return 0;
}