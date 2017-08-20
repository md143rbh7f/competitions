// alternatively, use __gcd from <algorithm>
int gcd(int a, int b)
{
	while(b) tie(a, b) = tup(b, a % b);
	return a;
}

void extended_euclidean(int a, int b, int & lx, int & ly)
{
	int x = 0, y = 1;
	lx = 1, ly = 0;
	while(b)
	{
		int q = a / b;
		tie(a, b) = tup(b, a % b);
		tie(x, lx) = tup(lx - q * x, x);
		tie(y, ly) = tup(ly - q * y, y);
	}
}

// modulo inverse using the extended Euclidean algorithm
int mod_inv(int a, int m)
{
	int lx, ly;
	extended_euclidean(a, m, lx, ly);
	if(lx < 0) lx += m;
	return lx;
}

ll mod_pow(ll a, ll b)
{
	if(!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

// modulo inverse using exponentiation
ll mod_inv(int a)
{
	return mod_pow(a, MOD - 2);
}

// The number of divisors grows rather slowly. For example, for all n <= 10^9,
// d(n) <= 1344, where d(n) is the number of divisors of n. See
// "count_number_factors.cpp" for more information.
vll get_divisors(ll n)
{
	vll ans;
	ll x = 1;
	for(; x * x < n; x++) if(!(n % x)) ans.push_back(x), ans.push_back(n / x);
	if(x * x == n) ans.push_back(x);
	sort(all(ans));
	return ans;
}

vector<pair<ll, int>> factorise(ll n)
{
	vector<pair<ll, int>> ans;
	for(ll f = 2; f * f <= n; f++) if(!(n % f))
	{
		int p = 0;
		while(!(n % f)) n /= f, p++;
		ans.emplace_back(f, p);
	}
	if(n > 1) ans.emplace_back(n, 1);
	return ans;
}

// A modified sieve of Eratosthenes which generates the smallest prime factor
// of each integer in [0, ..., n - 1]. This lookup allows us to factorise x
// in O(f), where f is the number of factors of x.
vi smallest_factor(int n)
{
	vi ans(n);
	for(int p = 2; p * p < n; p++) if(!ans[p])
	{
		ans[p] = p;
		for(int q = p * p; q < n; q += p)
			ans[q] = p;
	}
	return ans;
}

// This not a function, but rather a technique for computing
// f(x) = g(x) - (sum of f(y) for all y such that y divides x)
// This can be useful in many number theory problems (e.g. SRMs 603 and 626).
int g(int x) { /* dummy function */ return x; }
void divisor_summation(int n)
{
	vll ds = get_divisors(n);
	int m = ds.size();
	vll f(m);
	rep(i, m)
	{
		ll x = ds[i];
		f[i] = M(g(x) - f[i] + MOD);
		range(j, i + 1, m)
		{
			ll y = ds[j];
			if(y % x) continue;
			cnt[j] = M(cnt[j] + cnt[i]);
		}
	}
}
