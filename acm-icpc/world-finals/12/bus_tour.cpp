#include <algorithm>
#include <iostream>

using namespace std;

#define N 18
#define INF 123456789

int n, m, d[N+2][N+2], f[1<<N][N], g[1<<N][N];

int fix( int i )
{
	if( i == 0 ) return n - 2;
	if( i == n - 1 ) return i;
	return i - 1;
}

void half( int start, int dp[1<<N][N] )
{
	for( int s = 0; s < 1<<n; s++ )
	for( int i = 0; i < n; i++ )
		dp[s][i] = INF;

	for( int i = 0; i < n; i++ )
		dp[1<<i][i] = d[start][i];

	for( int s = 0; s < 1<<n; s++ )
	{
		int sz = __builtin_popcount( s );
		if( sz < 2 || sz > ( n + 1 ) / 2 ) continue;
		for( int i = 0; i < n; i++ )
		if( ( s >> i ) & 1 )
		for( int j = 0; j < n; j++ )
		if( j != i && ( ( s >> j ) & 1 ) )
			dp[s][i] = min( dp[s][i], d[i][j] + dp[s^(1<<i)][j] );
	}
}

int path( int s, int a[1<<N][N], int b[1<<N][N] )
{
	int ans = INF, t = ((1<<n)-1)^s;
	for( int i = 0; i < n; i++ )
	if( ( s >> i ) & 1 )
	for( int j = 0; j < n; j++ )
	if( ( t >> j ) & 1 )
		ans = min( ans, a[s][i] + b[t][j] + d[i][j] );
	return ans;
}

void print_ans( int t, int ans )
{
	cout << "Case " << t << ": " << ans << endl;
}

bool run( int t )
{
	cin >> n >> m;
	if( cin.fail() ) return false;

	for( int i = 0; i < n; i++ )
	for( int j = 0; j < n; j++ )
		d[i][j] = INF;

	while( m-- )
	{
		int a, b, c;
		cin >> a >> b >> c;
		a = fix( a ), b = fix( b );
		d[a][b] = d[b][a] = c;
	}

	for( int k = 0; k < n; k++ )
	for( int i = 0; i < n; i++ )
	for( int j = 0; j < n; j++ )
		d[i][j] = min( d[i][j], d[i][k] + d[k][j] );

	if( n == 3 )
	{
		print_ans( t, 2 * ( d[1][0] + d[0][2] ) );
		return true;
	}
	
	n -= 2, half( n, f ), half( n + 1, g );

	int ans = INF;
	for( int s = 0; s < 1<<n; s++ )
	if( __builtin_popcount( s ) == n / 2 )
		ans = min( ans, path( s, f, g ) + path( s, g, f ) );

	print_ans( t, ans );
	return true;
}

int main()
{
	for( int i = 1; run( i ); i++ );
	return 0;
}
