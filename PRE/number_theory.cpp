// alternatively, use __gcd (requires #include <algorithm>)
int gcd(int a, int b)
{
	while(b)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void extended_euclidean(int a, int b, int & lx, int & ly)
{
	int x = 0, y = 1;
	lx = 1, ly = 0;
	while(b)
	{
		int t = a % b, q = a / b;
		a = b; b = t;
		t = x; x = lx - q * x; lx = t;
		t = y; y = ly - q * y; ly = t;
	}
}

int mod_inv(int a, int m)
{
	int lx, ly;
	extended_euclidean(a, m, lx, ly);
	if(lx < 0) lx += m;
	return lx;
}

ll mod_exp(ll a, ll b)
{
	if(!b) return 1;
	if(b % 2) return M(a * mod_exp(M(a * a), b / 2));
	return mod_exp(M(a * a), b / 2);
}

vll get_factors(ll n)
{
	vll ans;
	ll f = 1;
	for(; f * f < n; f++) if(!(n % f)) ans.push_back(f), ans.push_back(n / f);
	if(f * f == n) ans.push_back(f);
	sort(all(ans));
	return ans;
}
