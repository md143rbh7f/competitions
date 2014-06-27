#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

int n, x[500005], m;
long long ans;

int main()
{
	scanf("%d", &n);
	rep(i, n)
	{
		scanf("%d", x + m);
		while(m > 1 && x[m - 2] >= x[m - 1] && x[m - 1] <= x[m])
		{
			ans += min(x[m - 2], x[m]);
			x[m - 1] = x[m];
			m--;
		}
		m++;
	}
	range(i, 1, m - 1) ans += min(x[i - 1], x[i + 1]);
	printf("%I64d", ans);
	return 0;
}
