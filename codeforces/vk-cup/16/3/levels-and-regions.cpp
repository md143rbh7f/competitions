#include <cstdio>
#include <utility>

using namespace std;

using ll = long long;
using ld = long double;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 200005;
constexpr ll INF = 1ll << 60;
int n, k, q[N];
ll u[N];
ld v[N], cur[N], nxt[N];

inline ld f(int i, int j) {
	return cur[i] + u[i] * v[j];
}

inline ld cross(ll x0, ld y0, ll x1, ld y1, ll x2, ld y2) {
	return (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
}

inline bool convex(int i, int j, int k) {
	return cross(u[i], cur[i], u[j], cur[j], u[k], cur[k]) >= 0;
}

int main() {
	scanf("%d%d", &n, &k);
	int x;
	ld inv, tot = 0;
	rep (i, n) {
		scanf("%d", &x);
		inv = 1.0l / x;
		u[i + 1] = u[i] + x;
		v[i + 1] = v[i] + inv;
		tot += u[i + 1] * inv;
	}

	range (_, 1, k) {
		int q0 = 0, q1 = 0;
		rep (i, n) cur[i] -= u[i] * v[i];
		range (i, 1, n + 1) {
			while (q0 + 1 < q1 && convex(q[q1 - 2], q[q1 - 1], i - 1)) q1--;
			q[q1++] = i - 1;
			while (q0 + 1 < q1 && f(q[q0], i) <= f(q[q0 + 1], i)) q0++;
			nxt[i] = f(q[q0], i);
		}
		swap(cur, nxt);
	}
	printf("%Lf\n", tot - cur[n]);

	return 0;
}
