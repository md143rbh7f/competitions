#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

constexpr int N = 200005, MOD = 1000000007, INV = 166666668;

int n, xs[N], q[N];
set<int> s {-1};

ll tri(ll n) { return M(n * M((n + 1) * M((n - 1) * INV))); }
ll s1(ll n) { return M(n * (n - 1) / 2); }
ll s2(ll n) { return M(n * M((n - 1) * M((2 * n - 1) * INV))); }
ll dbl(ll a, ll b) {
	if (a > b) swap(a, b);
	return M(s2(a) + s1(a) * (b - a));
}

ll cnt(int m) {
	auto it = s.find(m);
	int l = *prev(it), r = *next(it);
	s.erase(it);
	ll bad = M(tri(m - l) + tri(r - m));
	if (l == -1 && r == n) return M(s1(s1(n + 1) + 1) - bad - dbl(m, n - m) + 2 * MOD);
	ll ans = M(tri(r - l) - bad + MOD);
	if (l == -1) {
		l = *prev(prev(s.end()));
		ans = M(ans + dbl(r, n - l) - dbl(m, n - l) + MOD);
	}
	if (r == n) {
		r = *next(s.begin());
		ans = M(ans + dbl(r, n - l) - dbl(n - m, r) + MOD);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	s.insert(n);
	rep (i, n) {
		scanf("%d", xs + i);
		s.insert(i);
		q[i] = i;
	}
	sort(q, q + n, [](int a, int b) { return xs[a] < xs[b]; });
	int ans = 0;
	rep (i, n) ans = M(ans + M(cnt(q[i]) * xs[q[i]]));
	printf("%d\n", ans);
	return 0;
}
