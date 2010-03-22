/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TheFansAndMeetingsDivTwo
{
	int max = 50;
	public double find( int[] lo1, int[] hi1, int[] lo2, int[] hi2 )
	{
		int n = lo1.length;
		int[][] lo = { lo1, lo2 }, hi = { hi1, hi2 };
		double[][] p = new double[2][max+1];
		for( int i = 0; i < 2; i++ )
		for( int j = 0; j < n; j++ )
		for( int k = lo[i][j]; k <= hi[i][j]; k++ )
			p[i][k] += 1.0/(n*(hi[i][j]-lo[i][j]+1));
		double ans = 0;
		for( int i = 1; i <= max; i++ )
			ans += p[0][i]*p[1][i];
		return ans;
	}
}
