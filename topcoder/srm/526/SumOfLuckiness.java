public class SumOfLuckiness
{
	int L = 10;
	long dp[][][] = new long[L+1][L+1][L+1];

	long count( int n )
	{
		int l = 0, dig[] = new int[L];
		for( int m = n; m > 0; m /= 10 ) dig[l++] = m%10;

		long ways[][][] = new long[L+1][L+1][L+1];
		ways[0][0][0] = 1;
		for( int i = 0; i < L; i++ )
		{
			int coeff = dig[i] - ( dig[i] > 4 ? 1 : 0 ) - ( dig[i] > 7 ? 1 : 0 );
			for( int x = 0; x < L; x++ ) for( int y = 0; y < L; y++ )
			{
				ways[i+1][x][y] += coeff * dp[i][x][y];
				if( dig[i] > 4 ) ways[i+1][x+1][y] += dp[i][x][y];
				if( dig[i] > 7 ) ways[i+1][x][y+1] += dp[i][x][y];
				ways[i+1][ x + ( dig[i] == 4 ? 1 : 0 ) ][ y + ( dig[i] == 7 ? 1 : 0 ) ] += ways[i][x][y];
			}
		}

		long ans = 0;
		for( int x = 0; x <= L; x++ )
		for( int y = 0; y <= L; y++ )
			ans += Math.abs( x - y ) * ways[L][x][y];

		return ans;
	}

	public long theSum( int a, int b )
	{
		dp[0][0][0] = 1;
		for( int i = 0; i < L; i++ )
		for( int x = 0; x < L; x++ )
		for( int y = 0; y < L; y++ )
		{
			dp[i+1][x][y] += 8 * dp[i][x][y];
			dp[i+1][x+1][y] += dp[i][x][y];
			dp[i+1][x][y+1] += dp[i][x][y];
		}
		return count(b) - count(a-1);
	}
}
