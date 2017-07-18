#include <stdio.h>

#define L 10

int n, ok[] = { 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 }, coeff[] = { 0, 2, 4, 6, 30, 32, 34, 36, 40, 42, 44, 46, 50, 52, 54, 56, 60, 62, 64, 66 }, ans[L], i, s;

int main()
{
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;
		for( i = 0; i < L; i++ ) if(ok[i]) ans[i] = coeff[n%20], n /= 20;
		s = 0;
		for( i = L-1; i >= 0; i-- ) if(ans[i]||s)
		{
			if(s) printf("%03d",ans[i]);
			else printf("%d",ans[i]);
			if(i) printf(",");
			else printf("\n");
			s = 1;
		}
	}
	return 0;
}
