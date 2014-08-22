#include <algorithm>
#include <cstdio>
#include <iterator>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N 100005
#define M 10005

template <int S>
struct FenwickTree
{
int y[S];

void add(int i, int d)
{
	for(; i < S; i += i&(-i)) y[i] += d;
}

int sum(int i)
{
	int ans = 0;
	for(; i; i -= i&(-i)) ans += y[i];
	return ans;
}

int find(int s)
{
	int i, del = 1;
	for(i = S / 2; i; i /= 2) del *= 2;
	for(i = 0; del; del /= 2) if(i + del < S && y[i + del] < s)
		i += del, s -= y[i];
	return i;
}
};

FenwickTree<M> cnt, tot;
vi cost[N], ord[N];
int n, ans = 1234567890, s, t;

int main()
{
	scanf("%d", &n);

	s = n;
	rep(i, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(b) cost[a].push_back(b), t += b;
	}

	rep(i, N)
	{
		sort(all(cost[i]), greater<int>());
		rep(j, cost[i].size()) ord[j].push_back(cost[i][j]);
	}

	rep(v, n)
	{
		int d = v + 1 - s, u = 0;
		if(d > 0)
		{
			int i = cnt.find(d);
			u = tot.sum(i) + (d - cnt.sum(i)) * (i + 1);
		}
		ans = min(ans, t + u);
		for(auto x : ord[v]) s--, t -= x, cnt.add(x, 1), tot.add(x, x);
	}
	printf("%d", ans);

	return 0;
}
