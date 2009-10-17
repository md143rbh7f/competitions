/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class OrderedNim
{
	static int INF = 0x3fffffff;

	int h[], n;
	int dp[][];
	public String winner( int[] _h )
	{
		h = _h; n = h.length;
		dp = new int[n+1][3];
		for( int i = 0; i < n; i++ ) if( h[i] > 1 ) h[i] = 2;
		if( wins( 0, h[0] ) == 1 ) return "Alice";
		return "Bob";
	}
	
	int wins( int i, int t )
	{
		if( i == n-1 ) return 1;
		if( i == n ) return -1;
		if( dp[i][t] == 0 )
		{
			int one = -wins( i+1, h[i+1] );
			int two = ( t == 2 ? -wins( i, 1 ) : -1 );
			if( t == 1 ) dp[i][t] = one;
			else if( one == 1 || two == 1 ) dp[i][t] = 1;
			else dp[i][t] = -1;
		}
		return dp[i][t];
	}
}
