#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int INF = 123456789;

struct Solution { int a, b, l, m; };

inline Solution add(int x, Solution &s, Solution &t) {
	if (x == s.a) return {x, s.b, s.l + 1, s.m + 1};
	return {x, t.a, (x == t.b ? t.l : t.m) + 1, 1};
}

void work() {
	int n, ans = 0, cnt = 0;
	scanf("%d", &n);
	Solution s {INF, INF, 0, 0}, t {INF, INF, 0, 0};
	rep (i, n) {
		int w, x, y;
		scanf("%d%d%d", &w, &x, &y);
		Solution u = add(w + x, s, t), v = add(w - y, t, s);
		s = u, t = v;
		if (s.l > ans) ans = s.l, cnt = 0;
		if (t.l > ans) ans = t.l, cnt = 0;
		if (s.l == ans || t.l == ans) cnt++;
	}
	printf("%d %d\n", ans, cnt);
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) {
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
