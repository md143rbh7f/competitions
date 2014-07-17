#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 1005
#define K 1000005

int n, m, k, p, r[N], c[N];
ll rans[K], cans[K];

void work(int * x, ll * y, int a, int b)
{
	priority_queue<int> q;
	rep(i, a) q.push(x[i]);
	rep(t, k)
	{
		int x0 = q.top();
		y[t + 1] = y[t] + x0;
		q.pop(), q.push(x0 - b * p);
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &p);
	rep(i, n) rep(j, m)
	{
		int a;
		scanf("%d", &a);
		r[i] += a, c[j] += a;
	}
	work(r, rans, n, m);
	work(c, cans, m, n);
	ll ans = -(1ll<<62);
	rep(t, k + 1)
		ans = max(ans, rans[t] + cans[k - t] - (ll) p * t * (k - t));
	printf("%I64d", ans);
	return 0;
}
