#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second

constexpr int N = 105;

pair<int, double> cs[N];
int p;
double sum[N];

inline double check(int lo, double hi) {
	if (hi <= p) return hi;
	if (lo <= p && p < hi) return p;
	return -1;
}

double rec(int i, int lo, double hi) {
	if (i < 0) return check(lo, hi);
	if (lo + cs[i].fst < hi) return check(lo, hi + sum[i + 1]);
	return max(rec(i - 1, lo, hi), rec(i - 1, lo + cs[i].fst, hi + cs[i].snd));
}

double work() {
	int n, w, h, have = 0;
	scanf("%d%d", &n, &p);

	auto ce = cs;
	rep (i, n) {
		scanf("%d%d", &w, &h);
		*(ce++) = {2 * min(w, h), 2 * hypot(w, h)};
		have += 2 * (w + h);
	}
	sort(cs, ce);
	rep (i, n) sum[i + 1] = sum[i] + cs[i].snd;

	return rec(n - 1, have, have);
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) printf("Case #%d: %.8lf\n", i + 1, work());
	return 0;
}
