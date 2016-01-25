#include <stdio.h>

/*
* Author name : VIpin Chaudhary
*/

// Logn approach
long long int rootlogn(long long int n)  // Divide conquer to compute square root of a number
{
	if (n==0 || n==1)
	{
		return n;
	}
	else
	{
		long long int s=1;long long int e=n/2,ans=0;  // start from 1 to n/2 and pick its mid and check the value of its square and adjust limits just like binary search algo
		while(s<=e)
		{
			long long int mid=(s+e)/2;
			if (mid*mid==n)
			{
				return mid;
			}
			else if (mid*mid<n)
			{
				s=mid+1;
				ans=mid;
			}
			else
			{
				e=mid-1;
			}
		}
		return ans;
	}
}
long long int main()
{
	printf("%lld\n",rootlogn(81));
}