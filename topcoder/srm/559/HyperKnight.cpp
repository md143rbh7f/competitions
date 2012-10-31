struct HyperKnight
{
	long long countCells( int _a, int _b, int n, int m, int k )
	{
		long long a = _a, b = _b;
		if( a > b ) a ^= b, b ^= a, a ^= b;
		long long c = b - a, d = n - 2 * b, e = m - 2 * b;
		if( k == 2 ) return 4 * a * a;
		if( k == 3 ) return 8 * a * c;
		if( k == 4 ) return 2 * a * ( d + e ) + 4 * c * c;
		if( k == 6 ) return 2 * c * ( d + e );
		if( k == 8 ) return d * e;
		return 0;
	}
};
