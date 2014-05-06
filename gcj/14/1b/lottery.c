#include "stdio.h"
#include "string.h"

typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define N 30

ll ways[N + 1][2][2][2];

ll work()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	memset(ways, 0, sizeof(ways));
	ways[0][1][1][1] = 1;
	rep(i, N)
	{
		rep(x, 2) rep(u, 2) if(x || u <= a % 2)
		rep(y, 2) rep(v, 2) if(y || v <= b % 2)
		rep(z, 2) rep(w, 2) if(z || w <= c % 2)
		if((u & v) == w)
			ways[i + 1][x][y][z] +=
				ways[i][x || u < a % 2][y || v < b % 2][z || w < c % 2];
		a /= 2, b /= 2, c /= 2;
	}
	return ways[N][0][0][0];
}

int main()
{
	int n;
	scanf("%d", &n);
	rep(i, n) printf("Case #%d: %lld\n", i + 1, work());
	return 0;
}
