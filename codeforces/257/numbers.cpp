#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define B 20
#define N (1<<B)
#define MOD 1000000007

int f[N], p[N];

int main()
{
	int n;
	scanf("%d", &n);

	p[0] = 1;
	rep(i, n) p[i + 1] = M(2 * p[i]);

	rep(i, n)
	{
		int x;
		scanf("%d", &x);
		f[x]++;
	}

	rep(b, B) rep(x, N) if(!(x & (1 << b))) f[x] += f[x ^ (1 << b)];

	int ans = 0;
	rep(x, N) ans = M(ans + (__builtin_popcount(x) & 1 ? MOD - p[f[x]] : p[f[x]]));
	printf("%d", ans);

	return 0;
}
