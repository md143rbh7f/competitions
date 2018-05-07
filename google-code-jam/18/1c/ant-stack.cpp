#include <algorithm>
#include <cstdio>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int S = 150;
constexpr ll INF = 1ll<<42;

ll best[S];

int work() {
	int n, w;
	scanf("%d", &n);
	range (i, 1, S) best[i] = INF;
	rep (i, n) {
		scanf("%d", &w);
		int l = 0;
		for (; (best[l] + 5) / 6 <= w; l++);
		for (; l; l--) best[l] = min(best[l], best[l - 1] + w);
	}
	rep (l, S) if (best[l] == INF) return l - 1;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) printf("Case #%d: %d\n", i + 1, work());
	return 0;
}
