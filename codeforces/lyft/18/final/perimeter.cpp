#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 300005;

int xs[N], ys[N], by_x[2], by_y[2];

int main() {
	int n;
	scanf("%d", &n);

	rep (i, n) {
		scanf("%d%d", xs + i, ys + i);
		if (xs[i] < xs[by_x[0]]) by_x[0] = i;
		if (xs[i] > xs[by_x[1]]) by_x[1] = i;
		if (ys[i] < ys[by_y[0]]) by_y[0] = i;
		if (ys[i] > ys[by_y[1]]) by_y[1] = i;
	}

	int ans = 0;
	rep (i, 2) {
		int x0 = xs[by_x[i]], y0 = ys[by_x[i]];
		rep (j, 2) {
			int x1 = xs[by_y[j]], y1 = ys[by_y[j]];
			rep (k, n)
				ans = max(ans,
					max(xs[k], max(x0, x1)) - min(xs[k], min(x0, x1))
					+
					max(ys[k], max(y0, y1)) - min(ys[k], min(y0, y1))
				);
		}
	}
	printf("%d", 2 * ans);

	ans = 2 * (ys[by_y[1]] - ys[by_y[0]] + xs[by_x[1]] - xs[by_x[0]]);
	range (j, 4, n + 1) printf(" %d", ans);
	printf("\n");

	return 0;
}
