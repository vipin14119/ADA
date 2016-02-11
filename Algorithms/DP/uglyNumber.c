#include <stdio.h>

int min(int a,int b,int c)
{
	if(a<=b && a<=c)
	{
		return a;
	}
	else if(b<=a && b<=c)
	{
		return b;
	}
	else if(c<=a && c<=b)
	{
		return c;
	}
}
int main()
{
	int n=150;
	int i;
	int ugly[n+1];
	ugly[0]=1;
	int i2=0,i3=0,i5=0;
	int next2=ugly[0]*2,next3=ugly[0]*3,next5=ugly[0]*5;
	int nextU=1;
	for(i=1;i<n;i++)
	{
		
		nextU=min(next2,next3,next5);
		ugly[i]=nextU;
		printf("%d\n",ugly[i]);
		if (nextU==next2)
		{
			i2++;
			next2=ugly[i2]*2;
		}
		if (nextU==next3)
		{
			i3++;
			next3=ugly[i3]*3;
		}
		if (nextU==next5)
		{
			i5++;
			next5=ugly[i5]*5;
		}
		
		
	}
	printf("%d\n",nextU);
}