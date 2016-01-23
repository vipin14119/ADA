#include <stdio.h>

int gcd(int a,int b)
{
	int r;
	while(b>0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	printf("gcd is %d\n",gcd(44,12));
	return 0;
}