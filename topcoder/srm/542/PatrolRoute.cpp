struct PatrolRoute
{
	int countRoutes( int x, int y, int t0, int t1 )
	{
		long long ans = 0;
		for( int i = 2; i < x; i++ ) for( int j = 2; j < y; j++ ) if( t0 <= 2 * ( i + j ) && 2 * ( i + j ) <= t1 )
			ans = ( ans + 6 * ( (long long) ( x - i ) * ( i - 1 ) * ( y - j ) * ( j - 1 ) ) ) % 1000000007;
		return ans;
	}
};
