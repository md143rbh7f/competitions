#include <cstdio>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 100005;

int nxt[N], cnt[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int prev = -1, cur, fst;
	rep (i, n) {
		scanf("%d", &cur);
		if (prev == -1) fst = cur;
		else nxt[prev] = cur;
		prev = cur;
	}

	m--;
	rep (j, m) {
		prev = -1;
		rep (i, n) {
			scanf("%d", &cur);
			if (prev != -1 && nxt[prev] == cur) cnt[prev]++;
			prev = cur;
		}
	}

	ll ans = n;
	int len = 0;
	cur = fst;
	rep (i, n - 1) {
		if (cnt[cur] == m) len++;
		else len = 0;
		ans += len;
		cur = nxt[cur];
	}
	printf("%lld\n", ans);
	return 0;
}
