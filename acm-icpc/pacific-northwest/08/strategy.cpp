#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 15, T = 300;

int n, best_m, best_p, ts[N], xs[N], ss[N], tmp[N], best[N];

void check(int m, int p) {
	if (m < best_m || (m == best_m && p > best_p)) return;
	bool ok = m > best_m || p < best_p;
	best_m = m, best_p = p;
	rep (i, m) tmp[i] = (ss[i] << 4) + xs[i];
	sort(tmp, tmp + m);
	rep (i, m) {
		tmp[i] &= 15;
		if (!ok) {
			if (tmp[i] > best[i]) break;
			if (tmp[i] < best[i]) ok = true;
		}
		best[i] = tmp[i];
	}
}

void rec(int m, int p, int a, int b, int c) {
	check(m, p);
	if (m == n) return;

	if (ts[m] + a <= T) {
		ss[m] = a + ts[m];
		rec(m + 1, p + ss[m], ss[m], b, c);
	}

	if (ts[m] + b <= T) {
		ss[m] = b + ts[m];
		rec(m + 1, p + ss[m], a, ss[m], c);
	}

	if (ts[m] + c <= T) {
		ss[m] = c + ts[m];
		rec(m + 1, p + ss[m], a, b, ss[m]);
	}
}

void work() {
	scanf("%d", &n);

	rep (i, n) scanf("%d", tmp + i), tmp[i] = (tmp[i] << 4) + i;
	sort(tmp, tmp + n);
	rep (i, n) ts[i] = tmp[i] >> 4, xs[i] = tmp[i] & 15;

	best_m = 0, ss[0] = ts[0];
	rec(1, ts[0], ts[0], 0, 0);

	rep (i, best_m) printf(" %c", 'A' + best[i]);
	printf(" %d %d\n", best_m, best_p);
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) {
		printf("Data set %d:", i + 1);
		work();
	}
	return 0;
}
