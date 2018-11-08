#include <algorithm>
#include <cstdio>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 300005;

int xs[N], ys[N], sorted[N];
ll ans[N];

bool by_delta(int a, int b) {
	return xs[a] - ys[a] < xs[b] - ys[b];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	ll sum_x = 0, sum_y = 0;
	rep (i, n) {
		scanf("%d%d", xs + i, ys + i);
		sorted[i] = i;
		sum_y += ys[i];
	}
	sort(sorted, sorted + n, &by_delta);

	rep (j, n) {
		int i = sorted[j];
		sum_y -= ys[i];
		ans[i] = sum_x + (ll) j * ys[i] + (ll) (n - j - 1) * xs[i] + sum_y;
		sum_x += xs[i];
	}

	int a, b;
	rep (_, m) {
		scanf("%d%d", &a, &b);
		a--, b--;
		int score = min(xs[a] + ys[b], xs[b] + ys[a]);
		ans[a] -= score, ans[b] -= score;
	}

	rep (i, n) printf("%lld ", ans[i]);
	printf("\n");

	return 0;
}
