#include <algorithm>
#include <cstdio>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)

constexpr int N = 4005;

int s[N][N], cur[N], nxt[N];

int read() {
	int c = 0;
	while (c < '0' || c > '9') c = getchar();
	return c - '0';
}

void rec(int n0, int n1, int k0, int k1) {
	if (n1 - n0 < 1) return;
	int n = (n0 + n1) / 2;

	int best_k = k0;
	nxt[n] = 0;
	range (k, k0, min(k1, n)) {
		int test = cur[k] + s[k][n] - s[k][k];
		if (test > nxt[n]) nxt[n] = test, best_k = k;
	}

	rec(n0, n, k0, best_k + 1);
	rec(n + 1, n1, best_k, k1);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	rep (i, n) rep (j, n)
		s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] + read() - s[i][j];

	range (_, 1, k) {
		rec (1, n + 1, 0, n);
		swap(cur, nxt);
	}

	printf("%d\n", s[n][n] / 2 - cur[n]);

	return 0;
}
