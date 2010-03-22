/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TheFansAndMeetingsDivOne
{
	static int max = 42, max2 = max*max;
	static double eps = 1e-11;

	public double find( int[] minJ, int[] maxJ, int[] minB, int[] maxB, int k )
	{
		int[][] lo = { minJ, minB }, hi = { maxJ, maxB };
		int n = minJ.length;
		double[][][][] DP = new double[2][n+1][n+1][max2+1];
		for( int z = 0; z < 2; z++ )
		{
			double[][][] dp = DP[z];
			dp[0][0][0] = 1;
			for( int i = 0; i < n; i++ )
			for( int j = 0; j <= i; j++ )
			for( int l = 0; l <= max2; l++ )
			if( dp[i][j][l] > eps )
			{
				double p = 1.0/(hi[z][i]-lo[z][i]+1);
				for( int m = lo[z][i]; m <= hi[z][i]; m++ )
					dp[i+1][j+1][l+m] += dp[i][j][l]*p*(j+1)/(i+1);
				dp[i+1][j][l] += dp[i][j][l]*(i+1-j)/(i+1);
			}
		}
		double ans = 0;
		for( int i = 1; i <= max2; i++ )
			ans += DP[0][n][k][i]*DP[1][n][k][i];
		return ans;
	}
}
