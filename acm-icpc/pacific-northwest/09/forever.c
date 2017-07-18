#include <stdio.h>

int n, a, b, t, c;

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		a = 0, b = 1, t = 0, c = 0;
		do
		{
			c = b;
			b = (a+b)%n;
			a = c;
			t++;
		}
		while(!(a==0&&b==1));
		printf("%d %d\n",n,t);
	}
	return 0;
}
