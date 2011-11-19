#define L 10
int stack[L+1], W, H, MOD = 1000000007;
long long dp[L+2][1<<L], coeff[1<<L][1<<L];

void rec( int l, int w )
{
	if( w == W )
	{
		int mask = 0, need = 0, j = 0;
		for( int i = 0; i < l; i++ )
		{
			if( !stack[i] ) j++;
			else
			{
				mask |= ( (1<<stack[i]) - 1 ) << j;
				need |= ( (1<<(stack[i]-1)) | 1 ) << j;
				j += stack[i];
			}
		}
		for( int prev = 0; prev < 1<<W; prev++ ) if( ( prev & need ) == need ) coeff[prev][mask]++;
	}
	else if( w < W )
	{
		stack[l] = 0;
		rec( l + 1, w + 1 );
		stack[l] = 1;
		rec( l + 1, w + 1 );
		stack[l] = 2;
		rec( l + 1, w + 2 );
		stack[l] = 3;
		rec( l + 1, w + 3 );
	}
}

struct SmallBricks31
{
	int countWays( int _W, int _H )
	{
		W = _W, H = _H;
		rec( 0, 0 );
		dp[0][(1<<W)-1] = 1;
		for( int h = 0; h <= H; h++ )
		for( int mask = 0; mask < 1<<W; mask++ )
		for( int prev = 0; prev < 1<<W; prev++ )
			dp[h+1][mask] = ( dp[h+1][mask] + ( dp[h][prev] * coeff[prev][mask] ) % MOD ) % MOD;
		return (int) dp[H+1][0];
	}
};
