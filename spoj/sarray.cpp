#include <cstdio>

using namespace std;

// Note: O( N ) implementation -- optimised to get full credit on SPOJ.

#define N 100005

char buf[N];

inline bool lt( int a0, int a1, int b0, int b1 ) { return a0 < b0 || ( a0 == b0 && a1 < b1 ); }
inline bool lt( int a0, int a1, int a2, int b0, int b1, int b2 ) { return a0 < b0 || ( a0 == b0 && lt( a1, a2, b1, b2 ) ); }

void radix_sort( int * suf, int * ans, int * s, int n, int rad )
{
	int * c = new int[rad+1], i;
	for( i = 0; i <= rad; i++ ) c[i] = 0;
	for( i = 0; i < n; i++ ) c[s[suf[i]]]++;
	for( i = 0; i < rad; i++ ) c[i+1] += c[i];
	for( i = n - 1; i >= 0; i-- ) ans[--c[s[suf[i]]]] = suf[i];
	delete[] c;
}

// Computes suffix array for s[0,...,n-1] as ans.
// Note: It is required that s[n] = s[n+1] = s[n+2] = 0, and 1 <= s[i] <= rad otherwise.
void suffix_array( int * s, int * ans, int n, int rad )
{
	int n0 = ( n + 2 ) / 3, n2 = n / 3, nx = n0 + n2, i, j, k;
	int * a = new int[n0+nx+3], * b = new int[n0+nx], * ax = a + n0, * bx = b + n0;
	a[n] = a[n+1] = a[n+2] = 0;
 
	// sort suffixes that are 1 or 2 mod 3
	for( i = 0; i < n0; i++ ) ax[i] = 3 * i + 1;
	for( i = 0; i < n2; i++ ) ax[i+n0] = 3 * i + 2;
	radix_sort( ax, bx, s+2, nx, rad );
	radix_sort( bx, ax, s+1, nx, rad );
	radix_sort( ax, bx, s, nx, rad );

	// compute ord numbers for suffixes
	int ord = 0, c0 = -1, c1 = -1, c2 = -1;
	for( i = 0; i < nx; i++ )
	{
		j = bx[i];
		if( s[j] != c0 || s[j+1] != c1 || s[j+2] != c2 ) ord++, c0 = s[j], c1 = s[j+1], c2 = s[j+2];
		ax[ j / 3 + ( j % 3 == 2 ) * n0 ] = ord;
	}

	// if ords aren't unique, recurse and recompute a/b
	if( ord < nx )
	{
		suffix_array( ax, bx, nx, ord );
		for( i = 0; i < nx; i++ ) ax[bx[i]] = i + 1, bx[i] = bx[i] < n0 ? 3 * bx[i] + 1 : 3 * ( bx[i] - n0 ) + 2;
	}

	// sort mod 0 suffixes based on first character and mod 1 suffixes
	for( i = 0, j = 0; i < nx; i++ ) if( bx[i] % 3 == 1 ) a[j++] = bx[i] - 1;
	radix_sort( a, b, s, n0, rad );

	// merge sorted suffixes from b and bx
	i = 0, j = n % 3 == 1, k = 0;
	while( i < n0 && j < nx )
	{
		int u = b[i], v = bx[j];
		if( v % 3 == 1 ?
			lt( s[u], ax[u/3], s[v], ax[v/3+n0] ) :
			lt( s[u], s[u+1], ax[u/3+n0], s[v], s[v+1], ax[v/3+1] )
		)
			ans[k++] = u, i++;
		else ans[k++] = v, j++;
	}
	while( i < n0 ) ans[k++] = b[i++];
	while( j < nx ) ans[k++] = bx[j++];

	delete[] a, delete[] b; 
}

int main()
{
	scanf( "%s", buf );
	int n;
	for( n = 0; buf[n]; n++ );
	int * s = new int[n+3], * ans = new int[n];
	for( int i = 0; i < n; i++ ) s[i] = buf[i];
	for( int i = 0; i < 3; i++ ) s[n+i] = 0;
	suffix_array( s, ans, n, 128 );
	for( int i = 0; i < n; i++ ) printf( "%d\n", ans[i] );
	return 0;
}
