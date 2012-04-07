import java.util.*;

public class FoxAndDoraemon
{
	public int minTime( int[] workTime, int splitTime )
	{
		Arrays.sort( workTime );
		int n = workTime.length, dp[][] = new int[n][n];
		for( int i = 0; i < n; i++ ) dp[i][i] = workTime[i];
		for( int l = 1; l < n; l++ ) for( int i = 0; i + l < n; i++ )
		{
			int j = i+l;
			dp[i][j] = 1234567890;
			for( int k = i; k < j; k++ ) dp[i][j] = Math.min( dp[i][j], Math.max( dp[i][k], dp[k+1][j] ) );
			dp[i][j] += splitTime;
		}
		return dp[0][n-1];
	}
}
