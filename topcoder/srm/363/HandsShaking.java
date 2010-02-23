/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class HandsShaking
{
	static int max = 50;
	static long[] dp = new long[max+1];
	static
	{
		dp[0] = 1;
		for( int i = 2; i <= max; i += 2 )
			for( int j = 0; j <= i-2; j += 2 )
				dp[i] += dp[j]*dp[i-2-j];
	}

	public long countPerfect( int n )
	{
		return dp[n];
	}
}
