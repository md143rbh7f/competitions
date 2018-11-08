// Alternatively, use __gcd from <algorithm>.
int gcd(int a, int b) {
	while (b) tie(a, b) = tup(b, a % b);
	return a;
}

void extended_euclidean(int a, int b, int & lx, int & ly) {
	int x = 0, y = 1;
	lx = 1, ly = 0;
	while (b) {
		int q = a / b;
		tie(a, b) = tup(b, a % b);
		tie(x, lx) = tup(lx - q * x, x);
		tie(y, ly) = tup(ly - q * y, y);
	}
}

// Modulo inverse using the extended Euclidean algorithm.
int mod_inv(int a, int m) {
	int lx, ly;
	extended_euclidean(a, m, lx, ly);
	if (lx < 0) lx += m;
	return lx;
}

ll mod_pow(ll a, ll b) {
	if (!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

// Modulo inverse using exponentiation.
// Note that this only works when MOD is prime (by Fermat's little theorem).
ll mod_inv(ll a) { return mod_pow(a, MOD - 2); }

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

template <typename It>
int divisors(ll n, It d0) {
	ll d = 1, *d1 = d0;
	for (; d * d < n; d++) if (n % d == 0) *(d1++) = d, *(d1++) = n / d;
	if (d * d == n) *(d1++) = d;
	sort(d0, d1);
	return d1 - d0;
}

// A modified sieve of Eratosthenes which generates the smallest prime factor
// of each integer in [0, ..., n - 1]. This lookup allows us to factorise x
// in O(f), where f is the number of factors of x.
template <typename It>
void smallest_prime_factors(int n, It f) {
	for (int p = 2; p * p < n; p++) if (!f[p]) {
		f[p] = p;
		for (int q = p * p; q < n; q += p) f[q] = p;
	}
}

// This not a function, but rather a technique for computing
// f(x) = g(x) - (sum of f(y) for all y such that y divides x)
// This can be useful in many number theory problems (e.g. SRMs 603 and 626).
int g(int x) { /* dummy function */ return x; }
void divisor_summation(int n) {
	vll ds = get_divisors(n);
	int m = ds.size();
	vll f(m);
	rep (i, m) {
		ll x = ds[i];
		f[i] = M(g(x) - f[i] + MOD);
		range (j, i + 1, m) {
			ll y = ds[j];
			if (y % x) continue;
			cnt[j] = M(cnt[j] + cnt[i]);
		}
	}
}
