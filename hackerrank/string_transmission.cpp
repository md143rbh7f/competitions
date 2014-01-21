#include <cstdio>

using namespace std;

#define N 1005
#define MOD 1000000007

int n, m, ways[N][N], choose[N][N], cnt[N];
char str[N];

int num_periodic( int t )
{
	for( int i = 0; i <= t; i++ ) for( int j = 0; j <= m; j++ ) ways[i][j] = 0;
	ways[0][0] = 1;

	for( int i = 0; i < t; i++ )
	{
		int c[2] = { 0, 0 };
		for( int j = 0; j < n/t; j++ ) c[str[j*t+i]]++;
		for( int j = 0; j <= m; j++ ) for( int k = 0; k < 2; k++ )
			ways[i+1][j+c[k]] = ( ways[i][j] + ways[i+1][j+c[k]] ) % MOD;
	}

	int ans = 0;
	for( int i = 0; i <= m; i++ ) ans = ( ans + ways[t][i] ) % MOD;
	return ans;
}

void run()
{
	scanf( "%d%d%s", &n, &m, str );

	for( int i = 0; i < n; i++ ) str[i] -= '0', cnt[i] = 0;

	long long ans = 0;
	for( int i = 0; i <= m; i++ ) ans = ( ans + choose[n][i] ) % MOD;

	for( int i = n/2; i >= 1; i-- ) if( n%i == 0 )
	{
		int coeff = 1 - cnt[i];
		for( int j = 1; j <= i; j++ ) if( i%j == 0 ) cnt[j] += coeff;
		long long bad = num_periodic( i );
		ans = ( ans + MOD - ( ( coeff * bad ) % MOD ) ) % MOD;
	}

	printf( "%lld\n", ans );
}

int main()
{
	choose[0][0] = 1;
	for( int i = 1; i < N; i++ )
	{
		choose[i][0] = 1;
		for( int j = 1; j <= i; j++ ) choose[i][j] = ( choose[i-1][j] + choose[i-1][j-1] ) % MOD;
	}

	int t;
	scanf( "%d", &t );
	while(t--) run();
	return 0;
}
