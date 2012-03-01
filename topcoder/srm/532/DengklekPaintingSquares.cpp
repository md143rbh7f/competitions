#define MOD 1000000007
#define W 105
#define H 8

int dp[W][1<<H][1<<H], p[1<<H];

struct DengklekPaintingSquares
{
	int numSolutions( int n, int m )
	{
		int M = 1<<m;
		for( int i = 0; i < M; i++ ) p[i] = ( ( i << 1 ) ^ ( i >> 1 ) ) & i;
		dp[n][0][0] = 1;
		for( int i = n-1; i >= 0; i-- )
		for( int x = 0; x < M; x++ )
		{
			int nx = ( M - 1 ) ^ x;
			for( int px = x; ; px = (px-1)&x )
			{
				for( int y = nx; ; y = (y-1)&nx )
				{
					int z = px ^ y, pz = p[z] ^ px;
					dp[i][z][pz] = ( dp[i][z][pz] + dp[i+1][x][px] ) % MOD;
					if( !y ) break;
				}
				if( !px ) break;
			}
		}
		int ans = 0;
		for( int i = 0; i < M; i++ ) ans = ( ans + dp[0][i][0] ) % MOD;
		return ans;
	}
};
