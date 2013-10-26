// Finds gcd for two numbers, as well as other fancy things.

// Euclidean algorithm
// for BigIntegers, use BigInteger.gcd(...)
static int gcd(int a, int b)
{
	while(b != 0)
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

// extended Euclidean algorithm
// solves for (x,y) in Bezout's Identity: ax+by = gcd(a,b)
static int[] extended_euclidean(int a, int b)
{
	int x = 0, lx = 1, y = 1, ly = 0;
	while(b != 0)
	{
		int t = a%b, q = a/b;
		a = b; b = t;
		t = x; x = lx-q*x; lx = t;
		t = y; y = ly-q*y; ly = t;
	}
	return new int[]{ lx, ly };
}

// uses extended Euclidean algorithm to calculate inverse of a modulo m
static int modulo_inverse(int a, int m)
{
	int inv = extended_euclidean(a,m)[0];
	if(inv<0) inv += m;
	return inv;
}
