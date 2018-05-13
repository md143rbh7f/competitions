#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

constexpr int N = 105, INF = 1234567890;

int n, g[N][2], have[N], np[N], q[N];
ll need[N];
bool mark[N];

ll work() {
	scanf("%d", &n);
	rep (i, n) {
		scanf("%d%d", g[i], g[i] + 1);
		g[i][0]--, g[i][1]--;
	}
	rep (i, n) scanf("%d", have + i);

	clr0(need), need[0] = 1;
	clr0(mark);
	ll ans = 0;
	while (true) {
		int can = INF;
		rep (i, n) if (need[i]) can = min(can, (int)(have[i] / need[i]));

		if (can > 0) {
			ans += can;
			rep (i, n) if (need[i]) have[i] -= need[i] * can;
		}

		rep (i, n) if (have[i] < need[i]) mark[i] = true;

		clr0(np);
		rep (i, n) if (mark[i]) for (auto j : g[i]) if (mark[j]) np[j]++;

		int *q0 = q, *q1 = q;
		rep (i, n) if (mark[i] && np[i] == 0) *(q1++) = i;
		for (; q0 < q1; q0++) {
			for (auto j : g[*q0]) if (mark[j]) {
				np[j]--;
				if (np[j] == 0) *(q1++) = j;
			}
		}

		int m = accumulate(mark, mark + n, 0);
		if (q0 != q + m) break;

		for (q0 = q; q0 != q1; q0++) if (have[*q0] < need[*q0]) {
			for (auto j : g[*q0]) need[j] += need[*q0] - have[*q0];
			need[*q0] = have[*q0];
		}
	}

	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) printf("Case #%d: %lld\n", i + 1, work());
	return 0;
}
