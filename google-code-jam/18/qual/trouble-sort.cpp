#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 50005;

int xs[N], ys[N];

int work() {
	int n, *x = xs, *y = ys;
	scanf("%d", &n);
	rep (i, n) scanf("%d", (i & 1 ? y : x)++);
	sort(xs, x), sort(ys, y);
	x = xs, y = ys;
	rep (i, n - 1) {
		if (*x > *y) return i;
		x++;
		swap(x, y);
	}
	return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) {
		printf("Case #%d: ", i + 1);
		int ans = work();
		if (ans >= 0) printf("%d\n", ans);
		else printf("OK\n");
	}
	return 0;
}
