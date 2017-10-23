#include <cstdio>
#include <utility>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 100005;
constexpr ll INF = 1ll << 60;
int n, k, s[N], q[N];
ll cur[N], nxt[N];

inline ll f(int i, int j) {
	return cur[i] + (ll) i * s[j];
}

inline ll cross(int x0, ll y0, int x1, ll y1, int x2, ll y2) {
	return (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
}

inline bool convex(int i, int j, int k) {
	return cross(i, cur[i], j, cur[j], k, cur[k]) >= 0;
}

int main() {
	scanf("%d%d", &n, &k);
	int x;
	ll tot = 0;
	rep (i, n) {
		scanf("%d", &x);
		s[i + 1] = s[i] + x;
		tot += x * i;
	}

	range (_, 1, k) {
		int q0 = 0, q1 = 0;
		rep (i, n) cur[i] -= (ll) i * s[i];
		range (i, 1, n + 1) {
			while (q0 + 1 < q1 && convex(q[q1 - 2], q[q1 - 1], i - 1)) q1--;
			q[q1++] = i - 1;
			while (q0 + 1 < q1 && f(q[q0], i) <= f(q[q0 + 1], i)) q0++;
			nxt[i] = f(q[q0], i);
		}
		swap(cur, nxt);
	}
	printf("%lld\n", tot - cur[n]);

	return 0;
}
