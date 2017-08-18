#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 200005

double p[N];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i, n) scanf("%lf", p + i);
	sort(p, p + n);
	double ans = 0;
	int s = min((1<<k) - 1, n);
	rep(i, s) ans += p[n - i - 1];
	printf("%.8lf", ans);
	return 0;
}
