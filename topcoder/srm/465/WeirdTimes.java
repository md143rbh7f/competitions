/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class WeirdTimes
{
	public int[] hourValues( int[] mins, int x )
	{
		int n = mins.length;
		int[] inc = new int[n];
		for( int i = 0; i < n-1; i++ ) if( mins[i]>=mins[i+1] ) inc[i] = 1;
		// dp[i][j] = combos with position i as value j, ignoring everything before it
		long[][] dp = new long[n][25];
		for( int j = 0; j < 24; j++ ) dp[n-1][j] = 1;
		for( int i = n-2; i >= 0; i-- )
			for( int j = 23-inc[i]; j >= 0; j-- )
				dp[i][j] = dp[i][j+1]+dp[i+1][j+inc[i]];
		int ret[] = new int[n], min = 0;
		outer:
		for( int i = 0; i < n; i++ )
		{
			for( int j = min; j < 24; j++ )
			{
				if( dp[i][j] >= x )
				{
					ret[i] = j;
					min = j+inc[i];
					continue outer;
				}
				x -= dp[i][j];
			}
			return new int[] {-1};
		}
		return ret;
	}
}
