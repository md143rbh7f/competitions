#include <cstdio>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)
constexpr int MOD = 1000000007, N = 1000005;

int f[N];

ll mod_pow(ll a, ll b) {
	if (!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

ll mod_inv(ll a) {
	return mod_pow(a, MOD - 2);
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	ll fac = f[0] = 1;
	range (i, 1, n) {
		f[i] = M(mod_inv(i) * (f[i - 1] + (i > k ? MOD - f[i - k - 1] : 0)) + f[i - 1]);
		fac = M(fac * i);
	}
	printf("%d\n", (int) M(fac * M(n - f[n - 1] + MOD)));
	return 0;
}
