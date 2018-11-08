#include <cstdio>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

constexpr int N = 300001, MOD = 1000000007, S = 7;

ll mod_pow(ll a, ll b) {
	if (!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

ll mod_inv(ll a) { return mod_pow(a, MOD - 2); }

int cnt[N], c[N], f[N];

int main() {
	rep (i, N) c[i] = i;

	int n;
	scanf("%d", &n);
	rep (i, n) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}

	range (k, 1, N) for (int m = 2 * k; m < N; m += k)
		cnt[k] += cnt[m];

	int ans = -1;
	range (p, 1, S + 1) {
		for (int k = N - 1; k; k--) {
			f[k] = c[cnt[k]];
			for (int m = 2 * k; m < N; m += k)
				f[k] = M(f[k] - f[m] + MOD);
		}

		if (f[1]) {
			ans = p;
			break;
		}

		int q = mod_inv(p + 1);
		range (k, 1, N)
			c[k] = M(c[k] * M((ll) (k - p) * q));

	}

	printf("%d\n", ans);
	return 0;
}
