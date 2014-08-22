#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long double ld;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define M 100005

ld log_fac[M], ans, big = 1e99;
int n, m, k;

inline ld log_choose(int i, int j)
{
	return i >= j ? log_fac[i] - log_fac[j] - log_fac[i - j] : 0;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	range(i, 1, m + 1)
		log_fac[i] = log_fac[i - 1] + log(i);
	rep(r, n + 1) rep(c, n + 1)
	{
		int p = n * (r + c) - r * c;
		if(p > k) continue;
		ans += exp(log_choose(n, r) + log_choose(n, c) + log_choose(m - p, k - p) - log_choose(m, k));
		if(ans >= big) break;
	}
	printf("%.11lf", (double) min(ans, big));
	return 0;
}
