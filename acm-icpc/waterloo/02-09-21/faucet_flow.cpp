#include <algorithm>
#include <cstdio>

using namespace std;

#define N 1005

int hs[N], xs[N];

inline int vol(int i) {
	return (xs[i + 1] - xs[i]) * min(hs[i], hs[i + 1]);
}

bool run() {
	int l, r;
	scanf("%d%d", &l, &r);
	if (!l && !r) return false;

	int n = 0, hi = -1;
	for (int x = l; x <= r; x += 2) {
		int h;
		scanf("%d", &h);

		int lvl = min(hi, h);
		while (n > 0 && hs[n - 1] < lvl) n--;
		hs[n] = h, xs[n] = x;
		n++;
		hi = max(hi, h);
	}

	r = 0;
	while (xs[r] < 0) r++;
	l = r - 1;

	int ans = vol(l), lcur = 0, rcur = 0;
	while (true) {
		if (hs[l] > hs[l + 1]) {
			if (r + 1 == n) break;
			ans += vol(r) - rcur;
			rcur = 0;
			r++;
		} else if (hs[r] > hs[r - 1]) {
			if (l == 0) break;
			ans += vol(l - 1) - lcur;
			lcur = 0;
			l--;
		} else {
			if (r + 1 == n || l == 0) break;
			int fill = min(vol(l - 1) - lcur, vol(r) - rcur);
			ans += 2 * fill;
			lcur += fill;
			if (lcur == vol(l - 1)) lcur = 0, l--;
			rcur += fill;
			if (rcur == vol(r)) rcur = 0, r++;
		}
	}
	printf("%d\n", ans);

	return true;
}

int main() {
	while (run());
	return 0;
}
