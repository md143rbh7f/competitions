/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class NewCoins
{
	final static int INF = 0x3fffffff;

	public int minCoins( int[] p )
	{
		int max = 0, n = p.length;
		for( int i = 0; i < n; i++ ) if( p[i] > max ) max = p[i];
		int[] dp = new int[max+1];
		for( int i = 2; i <= max; i++ ) dp[i] = INF;
		for( int i = 1; i <= max; i++ )
		for( int j = 2; (i*j) <= max; j++ )
		{
			int sum = dp[i], next = i*j;
			for( int k = 0; k < n; k++ ) sum += (p[k]%next)/i;
			if( sum < dp[next] ) dp[next] = sum;
		}

		int min = INF;
		for( int i = 1; i <= max; i++ )
		{
			int sum = dp[i];
			for( int k = 0; k < n; k++ ) sum += p[k]/i;
			if( sum < min ) min = sum;
		}
		return min;
	}
}
