/*
	Generates next permutations (in C++, use std::next_permutation).
*/

	// permutes entries of an int array; returns false on end
	static boolean next_permutation( int[] p )
	{
		int n = p.length;
		if( n < 2 ) return false;
		int i = n-2;
		while( i >= 0 && p[i] >= p[i+1] ) i--;
		if( i >= 0 )
		{
			int j = n-1;
			while( p[j] <= p[i] ) j--;
			p[i] ^= p[j]; p[j] ^= p[i]; p[i] ^= p[j];
		}
		for( int d = 1; i + d < n - d; d++ )
		{
			p[i+d] ^= p[n-d]; p[n-d] ^= p[i+d]; p[i+d] ^= p[n-d];
		}
		return i == -1 ? false : true;
	}

	// permutes bits of an int; returns -1 on end
	static int next_permutation( int x, int n )
	{
		if( n < 2 ) return -1;
		int i = 0;
		while( i < n-1 && ( (x>>i)&3 ) != 1 ) i++;
		i++;
		if( i == n ) return -1;
		int cnt = 0;
		for( int j = 0; j < i; j++ ) cnt += (x>>j)&1;
		return x ^ ( x & ((1<<i)-1) ) ^ (1<<i) ^ ( (1<<(cnt-1)) - 1 );
	}
