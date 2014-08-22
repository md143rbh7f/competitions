#include <cmath>
#include <cstdio>
#include <deque>
#include <utility>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005
#define S 320

int cnt[S][N], n, s, q;
deque<int> ls[S];

int main()
{
	scanf("%d", &n);

	s = ceil(sqrt(n));
	rep(i, n)
	{
		int x;
		scanf("%d", &x);
		cnt[i / s][x]++;
		ls[i / s].push_back(x);
	}

	scanf("%d", &q);
	int ans = 0;
	while(q--)
	{
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		l = (l + ans - 1) % n;
		r = (r + ans - 1) % n;
		if(l > r) swap(l, r);
		int la = l / s, lb = l % s;
		int ra = r / s, rb = r % s;
		if(t == 1)
		{
			int x = ls[ra][rb];
			ls[la].insert(ls[la].begin() + lb, x), cnt[la][x]++;
			ls[ra].erase(ls[ra].begin() + rb + (la == ra && l < r)), cnt[ra][x]--;
			range(a, la, ra)
			{
				int x = ls[a].back();
				ls[a].pop_back(), cnt[a][x]--;
				ls[a + 1].push_front(x), cnt[a + 1][x]++;
			}
		}
		else
		{
			int k;
			scanf("%d", &k);
			k = (k + ans - 1) % n + 1;
			ans = 0;
			auto li = ls[la].begin(), ri = ls[ra].begin();
			rep(i, lb) ans -= *(li++) == k;
			rep(i, rb + 1) ans += *(ri++) == k;
			range(a, la, ra) ans += cnt[a][k];
			printf("%d\n", ans);
		}
	}

	return 0;
}
