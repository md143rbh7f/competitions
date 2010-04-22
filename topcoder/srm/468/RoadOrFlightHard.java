import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class RoadOrFlightHard
{
	long inf = 1l<<60;

	public long minTime( int n, int rf, int rp, int ra, int rm, int ff, int fp, int fa, int fm, int k )
	{
		long[] r = new long[n], f = new long[n];
		r[0] = rf%rm; f[0] = ff%fm;
		for( int i = 1; i < n; i++ )
		{
			r[i] = (r[i-1]*rp+ra)%rm;
			f[i] = (f[i-1]*fp+fa)%fm;
		}

		long[][][] dp = new long[2][k+1][2];
		for( int t = 0; t < n; t++ )
		{
			int cur = t&1, next = 1-cur;
			for( int i = 0; i <= k; i++ )
			{
				dp[next][i][0] = min( dp[cur][i][0], dp[cur][i][1] ) + r[t];
				dp[next][i][1] = i==0? inf : min( dp[cur][i][1], dp[cur][i-1][0] ) + f[t];
			}
		}

		long ans = inf;
		for( int i = 0; i <= k; i++ ) for( int j = 0; j < 2; j++ ) ans = min( ans, dp[n&1][i][j] );
		return ans;
	}
}
