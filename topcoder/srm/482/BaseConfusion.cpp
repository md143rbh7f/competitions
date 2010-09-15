typedef long long ll;

ll s( int n, int b )
{
	if(!n) return 0;
	ll B = 1, BB = 1, bb = b+1;
	while(n/B) B *= b, BB *= bb;
	B /= b, BB /= bb;
	int dig = n/B;
	ll ans = (dig*(dig-1)/2*B+dig*((n%B)+1))*BB, coeff = dig*B*(b-1)/2;
	while(BB) BB /= bb, ans += coeff*BB;
	return ans+s(n%B,b);
}

struct BaseConfusion
{
	ll sum( int m, int n, int b )
	{
		return s(n,b)-s(m-1,b);
	}
};
