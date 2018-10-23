#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

constexpr int S = 200005;

bool is_h[S];
int q[S], x_prev[S], x_next[S], y_prev[S], y_next[S];
ll ans[S];
char buf[5];

int main() {
	int x1, y1, n;
	scanf("%d%d%d", &x1, &y1, &n);

	rep (i, n) {
		scanf("%s%d", buf, q + i);
		if (buf[0] == 'H') is_h[i] = true, y_prev[q[i]] = -1;
		else x_prev[q[i]] = -1;
	}
	x_prev[0] = y_prev[0] = x_prev[x1] = y_prev[y1] = -1;

	int x_last = 0, x_max = 0;
	rep (x, x1 + 1) if (x_prev[x] == -1) {
		x_prev[x] = x_last;
		x_next[x_last] = x;
		x_max = max(x_max, x - x_last);
		x_last = x;
	}

	int y_last = 0, y_max = 0;
	rep (y, y1 + 1) if (y_prev[y] == -1) {
		y_prev[y] = y_last;
		y_next[y_last] = y;
		y_max = max(y_max, y - y_last);
		y_last = y;
	}

	for (int i = n - 1; i >= 0; i--) {
		ans[i] = (ll) x_max * (ll) y_max;
		int c = q[i];
		if (is_h[i]) {
			y_max = max(y_max, y_next[c] - y_prev[c]);
			y_prev[y_next[c]] = y_prev[c];
			y_next[y_prev[c]] = y_next[c];
		} else {
			x_max = max(x_max, x_next[c] - x_prev[c]);
			x_prev[x_next[c]] = x_prev[c];
			x_next[x_prev[c]] = x_next[c];
		}
	}

	rep (i, n) printf("%lld\n", ans[i]);

	return 0;
}
