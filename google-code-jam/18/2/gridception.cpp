#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

constexpr int N = 21;

int n, m, n2, m2;
char base[2][2], buf[N][N], buf2[2 * N][2 * N], pat[N][N];
bool seen[N][N];

int dfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m || seen[i][j]) return 0;
	seen[i][j] = true;
	if (buf[i][j] != pat[i][j]) return 0;
	return 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i, j + 1);
}

int check(int mask) {
	rep (b, 4) base[b & 1][b >> 1] = 1 & (mask >> b) ? 'W' : 'B';

	bool ok = false;
	rep (i, n2 - 1) rep (j, m2 - 1) {
		bool match = true;
		rep (di, 2) rep (dj, 2)
			match &= buf2[i + di][j + dj] == base[di][dj];
		ok |= match;
	}
	if (!ok) return 0;

	int ans = 0;
	rep (i0, n) rep (j0, m) {
		rep (i, n) rep (j, m) pat[i][j] = base[i > i0][j > j0];
		clr0(seen);
		rep (i, n) rep (j, m) if (!seen[i][j]) ans = max(ans, dfs(i, j));
	}
	return ans;
}

int work() {
	scanf("%d%d", &n, &m);
	rep (i, n) scanf("%s", buf[i]);

	n2 = 2 * n, m2 = 2 * m;
	rep (i, n2) rep (j, m2) buf2[i][j] = buf[i / 2][j / 2];

	int ans = 1;
	rep (mask, 16) ans = max(ans, check(mask));
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	rep (i, t) printf("Case #%d: %d\n", i + 1, work());
	return 0;
}
