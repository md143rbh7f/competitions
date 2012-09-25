#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define H 50
#define C 4
#define D C*C*C*C
#define K 7
#define MOD 1234567891

int e[D][D], f[D], pow[5];
long long count[H][D][K+1];

inline int get( int i, int j ) { return ( i % pow[j+1] ) / pow[j]; }

struct TheBrickTowerHardDivTwo
{
	int find( int c, int k, int h )
	{
		pow[0] = 1;
		rep(i,4) pow[i+1] = pow[i] * c;

		int d = pow[4];
		rep(i,d) rep(m,4)
		{
			f[i] += get( i, m ) == get( i, ( m + 1 ) % 4 );
			rep(j,d) e[i][j] += get( i, m ) == get( j, m );
		}

		rep(i,d) if( f[i] <= k ) count[1][i][f[i]] = 1;
		REP(m,1,h) rep(i,d) rep(n,k+1) rep(j,d) 
		{
			int nn = n + f[j] + e[i][j];
			if( nn > k ) continue;
			count[m+1][j][nn] = ( count[m+1][j][nn] + count[m][i][n] ) % MOD;
		}

		long long ans = 0;
		REP(m,1,h+1) rep(i,d) rep(n,k+1) ans = ( ans + count[m][i][n] ) % MOD;

		return ans;
	}
};
