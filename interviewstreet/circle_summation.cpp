#include <cstdio>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

#define P 32
#define L 55
#define MOD 1000000007
typedef long long matrix[L][L];

matrix pow[P], m, tmp;
long long x[L];
int T, N, M;

// a = b * c
void mult( matrix & a, matrix & b, matrix & c )
{
	rep(i,N) rep(j,N) a[i][j] = 0;
	rep(i,N) rep(j,N) rep(k,N) a[i][j] = ( a[i][j] + ( b[i][k] * c[k][j] ) % MOD ) % MOD;
}

// a = b
void copy( matrix & a, matrix & b )
{
	rep(i,N) rep(j,N) a[i][j] = b[i][j];
}

void generate_matrix()
{
	rep(i,N) rep(j,N) pow[0][i][j] = 0;
	rep(i,N-1) pow[0][i][i+1] = 1;
	pow[0][N-1][0] = pow[0][N-1][1] = pow[0][N-1][N-1] = 1;
	rep(p,P-1) mult( pow[p+1], pow[p], pow[p] );

	rep(i,N) rep(j,N) m[i][j] = 0;
	rep(i,N) m[i][i] = 1;
	rep(p,P) if((M>>p)&1)
	{
		mult( tmp, pow[p], m );
		copy( m, tmp );
	}

	copy( tmp, m );
	rep(i,N) rep(j,N) m[(i+M)%N][j] = tmp[i][j];
}

void output()
{
	rep(i,N) rep(j,N)
	{
		int sum = 0;
		rep(k,N) sum = ( sum + ( m[(j-i+N)%N][k] * x[(k+i)%N] ) % MOD ) % MOD;
		printf( "%d", sum );
		printf( j + 1 < N ? " " : "\n" );
	}
	if( T ) printf( "\n" );
}

int main()
{
	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d%d", &N, &M );
		rep(i,N) scanf( "%lld", &x[i] );
		generate_matrix();
		output();
	}
	return 0;
}
