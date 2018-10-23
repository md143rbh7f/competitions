#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define clr1(i) CLR(i,-1)

namespace FFT {
constexpr int P = 1053818881;
constexpr int K = 20, R = 526909441, E[2] = {933643223, 973782742};

template <typename T>
void fft(T s, T t, bool inv = false) {
	int n = t - s, k = 0;
	while (1 << k < n) k++;

	int j = 0;
	rep (i, n) {
		if (i < j) swap(s[i], s[j]);
		int b = n >> 1;
		while (j & b) b >>= 1;
		j ^= n - b;
	}

	rep (m, k) {
		int l = 1 << m, e = E[inv];
		rep (_, K - 1 - m) e = (ll) e * e % P;
		for (int i = 0; i < n; i += 2 * l) {
			int w = 1;
			rep (j, l) {
				int u = s[i + j], v = (ll) w * s[i + j + l] % P;
				s[i + j] = (u + v) % P;
				s[i + j + l] = (u - v + P) % P;
				w = (ll) w * e % P;
			}
		}
	}

	if (inv) {
		int r = 1;
		rep (_, k) r = (ll) r * R % P;
		rep (i, n) s[i] = (ll) r * s[i] % P;
	}
}
};

constexpr int N = 200005, C = 4, S = 524288;
constexpr char cs[S] = "ACGT";

int t[C][N], xs[S], ys[S], score[N];
char buf[N];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	scanf("%s", buf);
	rep (i, n) rep (c, C) t[c][i + 1] = t[c][i] + (buf[i] == cs[c]);
	scanf("%s", buf);

	int l = n - m + 1;
	rep (c, C) {
		clr0(xs), clr0(ys);
		rep (i, n) xs[i] = t[c][max(0, i - k)] < t[c][min(n, i + k + 1)];
		FFT::fft(xs, xs + S);
		rep (i, m) ys[i] = buf[m - 1 - i] == cs[c];
		FFT::fft(ys, ys + S);
		rep (i, S) xs[i] = (ll) xs[i] * ys[i] % FFT::P;
		FFT::fft(xs, xs + S, true);
		rep (i, l) score[i] += xs[m - 1 + i];
	}

	int ans = 0;
	rep (i, l) ans += score[i] == m;
	printf("%d\n", ans);

	return 0;
}
