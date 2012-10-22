#define N 2500
#define MOD(x) ((x)%555555555)

long long choose[N][N];

struct XorBoard
{
	int count( int H, int W, int R, int C, int S )
	{
		for( int i = 0; i < N; i++ ) choose[i][0] = 1;
		for( int i = 1; i < N; i++ ) for( int j = 1; j <= i; j++ ) choose[i][j] = MOD( choose[i-1][j] + choose[i-1][j-1] );

		int ans = 0;
		for( int r = R % 2; r <= R && r <= H; r += 2 )
		for( int c = C % 2; c <= C && c <= W; c += 2 )
		if( ( H - r ) * c + r * ( W - c ) == S )
		{
			long long row = MOD( choose[H][r] * choose[ ( R - r ) / 2 + H - 1 ][ H - 1 ] );
			long long col = MOD( choose[W][c] * choose[ ( C - c ) / 2 + W - 1 ][ W - 1 ] );
			ans = MOD( ans + MOD( row * col ) );
		}
		return ans;
	}
};
