#include <cstdio>
#include <utility>

using namespace std;

using ll = long long;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second

pair<ll, int> f0[15];

template <typename It>
int factorise(ll n, It f0) {
	It f1 = f0;
	for (ll p = 2; p * p <= n; p++) if (n % p == 0) {
		int e = 0;
		while (n % p == 0) n /= p, e++;
		*(f1++) = {p, e};
	}
	if (n > 1) *(f1++) = {n, 1};
	return f1 - f0;
}

ll work(ll x) {
	pair<ll, int> *f1 = f0 + factorise(x, f0);
	ll ans = 1;
	range (f, f0, f1) rep (_, f->snd) ans = ans * f->fst + 1;
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	ll x, ans = 0;
	rep (i, n) {
		scanf("%lld", &x);
		ans += work(x);
	}
	printf("%lld\n", ans);
	return 0;
}
