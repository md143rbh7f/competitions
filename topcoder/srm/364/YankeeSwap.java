/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class YankeeSwap
{
	public String sequenceOfSwaps( String[] prefs )
	{
		n = prefs.length; p = new int[n][n]; end = new int[n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) p[i][j] = prefs[i].charAt(j)-'A';
		boolean[] used = new boolean[n];
		for( int i = n-1; i >= 0; i-- ) for( int j = 0; j < n; j++ )
		if( !used[p[i][j]] )
		{
			used[p[i][j]] = true;
			end[i] = p[i][j];
			break;
		}
		ops = new char[n];
		for( int i = 0; i < n; i++ )
		{
			ops[i] = '-';
			if( !works(i) )
			for( int j = 0; j < n; j++ )
			{
				ops[i] = (char)('a'+j);
				if( works(i) ) break;
			}
		}
		return new String(ops);
	}

	char[] ops;
	int p[][], n, end[];

	boolean works( int last )
	{
		int[] cur = new int[n];
		for( int i = 0; i < n; i++ ) cur[i] = i;
		for( int i = 0; i <= last; i++ ) if( ops[i] != '-' )
		{
			int temp = cur[i];
			cur[i] = cur[ops[i]-'a'];
			cur[ops[i]-'a'] = temp;
		}
		for( int i = last+1; i < n; i++ ) for( int j = 0; j < n; j++ )
		if( cur[j]==end[i] )
		{
			int temp = cur[i];
			cur[i] = cur[j];
			cur[j] = temp;
		}
		for( int i = 0; i < n; i++ ) if( cur[i] != end[i] ) return false;
		return true;
	}
}
