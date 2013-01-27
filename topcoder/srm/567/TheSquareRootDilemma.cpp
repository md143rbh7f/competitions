int gcd( int a, int b )
{
	while( b != 0 )
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

struct TheSquareRootDilemma
{
	int countPairs( int n, int m )
	{
		int ans = 0;
		for( int a = 1; a * a <= n; a++ )
		for( int b = 1; b * b <= m; b++ )
		if( gcd( a, b ) == 1 )
		for( int g = 1; g * a * a <= n && g * b * b <= m; g++ )
			ans++;
		return ans;
	}
};
