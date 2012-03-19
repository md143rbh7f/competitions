bool ok( int n, int x, int y )
{
	for( int z = 0; z <= n; z += x ) if( ( n - z ) % y == 0 ) return true;
	return false;
}

struct KingXNewCurrency
{
	int howMany( int a, int b, int x )
	{
		if( a % x == 0 && b % x == 0 ) return -1;
		int ans = 0;
		for( int y = 1; y <= a || y <= b; y++ ) if( ok( a, x, y ) && ok( b, x, y ) ) ans++;
		return ans;
	}
};
