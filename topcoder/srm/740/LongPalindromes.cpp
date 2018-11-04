#include <string>
#include <vector>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

constexpr int MOD = 1000000007;

template <typename T> using matrix = vector<vector<T>>;

template <typename T>
matrix<T> id(int n) {
	matrix<T> a(n, vector<T>(n));
	rep (i, n) a[i][i] = 1;
	return a;
}

template <typename T>
matrix<T> operator*(matrix<T> a, matrix<T> b) {
	int n = a.size(), p = b.size(), m = b[0].size();
	matrix<T> c(n, vector<T>(m));
	rep (i, n) rep (j, m) rep (k, p)
		c[i][j] = M(c[i][j] + M((ll) a[i][k] * b[k][j]));
	return c;
}

template <typename T>
matrix<T> operator^(matrix<T> a, ll b) {
	if (!b) return id<T>(a.size());
	matrix<T> next = (a * a)^(b / 2);
	return b % 2 ? next * a : next;
}

struct LongPalindromes {
int count(int m, string s) {
	int n = s.size();
	matrix<int> h = id<int>(2 * n);
	rep (l, n) {
		matrix<int> g(2 * n, vector<int>(2 * n));
		rep (i, n) {
			g[i][i]++;
			g[i][(i + 1) % n]++;
			g[n + i][i]++;
			if (s[i] != s[(i + l) % n]) g[i][n + (i + 1) % n] = MOD - 1;
		}
		h = g * h;
	}
	h = h ^ m;
	int ans = 0;
	rep (i, n) ans = M(ans + h[0][i]);
	return ans;
}
};
