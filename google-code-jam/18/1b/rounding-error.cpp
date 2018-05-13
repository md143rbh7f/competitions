#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

using pii = pair<int,int>;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second

constexpr int T = 200, N = 100005;

int steps(int x, int n) {
	int y = T * x, k = T * n;
	while (y < k && y / n % 2 == 0) {
		y += n - y % n + T - 1;
		y -= y % T;
	}
	return y / T - x;
}

pii xs[N];

int work() {
	int n, m;
	scanf("%d%d", &n, &m);
	int k = n;
	rep (i, m) {
		int x;
		scanf("%d", &x);
		k -= x;
		xs[i] = {steps(x, n), x};
	}
	while (m < T) xs[m++] = {steps(0, n), 0};
	sort(xs, xs + m);
	int ans = 0;
	range (x, xs, xs + m) {
		int d = min(k, x->fst);
		k -= d;
		ans += (T * (x->snd + d) + n) / n / 2;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) printf("Case #%d: %d\n", i + 1, work());
	return 0;
}
