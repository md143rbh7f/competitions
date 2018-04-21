#include <algorithm>
#include <cstdio>
#include <numeric>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 1005;

int ms[N], ss[N], ps[N], bs[N];

ll attempt(int r, int c, ll t) {
	rep (i, c) {
		if (t <= ps[i]) bs[i] = 0;
		else bs[i] = min((ll) ms[i], (t - ps[i]) / ss[i]);
	}
	sort (bs, bs + c);
	return accumulate(bs + c - r, bs + c, 0ll);
}

ll work() {
	int r, b, c;
	scanf("%d%d%d", &r, &b, &c);
	rep (i, c) scanf("%d%d%d", ms + i, ss + i, ps + i);
	ll x = 1, y = 1ll<<62;
	while (y - x > 1) {
		ll z = (x + y - 1) / 2, buy = attempt(r, c, z);
		if (buy < b) x = z + 1;
		else y = z + 1;
	}
	return x;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) printf("Case #%d: %lld\n", i + 1, work());
	return 0;
}
