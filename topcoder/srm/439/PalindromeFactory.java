/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class PalindromeFactory
{
	public int getEditDistance( String S )
	{
		char[] s = S.toCharArray();
		int best = palinDist(s);
		for( int i = 0; i < s.length; i++ ) for( int j = 0; j < s.length; j++ )
		{
			char c = s[i]; s[i] = s[j]; s[j] = c;
			best = Math.min( best, 1+palinDist(s) );
			s[j] = s[i]; s[i] = c;
		}
		return best;
	}

	static int palinDist( char[] str )
	{
		int n = str.length;
		int[][] d = new int[n+1][n];
		for( int l = 2; l <= n; l++ )
		for( int s = 0; s <= n-l; s++ )
		{
			if( str[s] == str[s+l-1] ) d[l][s] = d[l-2][s+1];
			else d[l][s] = 1+Math.min( d[l-2][s+1], Math.min( d[l-1][s+1], d[l-1][s] ) );
		}
		return d[n][0];
	}
}
