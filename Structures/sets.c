#include <stdio.h>
int Set[100];
void initSet()
{
	int i;
	for (i = 0; i < 100; ++i)
	{
		Set[i]=-1;
	}
}

void Union(int r1,int r2)
{
	if (Set[r2]<Set[r1])
	{
		Set[r1]=r2;
	}
	else
	{
		if (Set[r1]==Set[r2])
			Set[r1]--;
		Set[r2]=r1;
	}
}

int find(int f)
{
	if(Set[f]<=0)
	{
		return f;
	}
	else
	{
		return find(Set[f]);
	}
}
int main()
{
	initSet();
	Union(2,3);
	Union(3,4);
	Union(1,5);
	Union(9,7);
	Union(3,9);
	printf("%d\n",find(1));
	printf("%d\n",find(2));
	printf("%d\n",find(9));
	printf("%d\n",find(3));
	printf("%d\n",find(5));

	return 0;
}
