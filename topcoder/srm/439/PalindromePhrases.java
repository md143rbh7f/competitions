/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class PalindromePhrases
{
	long[][][][] memo;
	boolean[][][][] done;
	String[][] words = new String[2][];
	int n;

	public long getAmount( String[] _words )
	{
		n = _words.length+1;
		int maxLen = 0;
		words[0] = new String[n];
		words[1] = new String[n];
		words[0][0] = words[1][0] = "";
		for( int i = 1; i < n; i++ ) 
		{
			words[0][i] = _words[i-1];
			words[1][i] = "";
			for( int j = words[0][i].length()-1; j >= 0; j-- )
				words[1][i] += words[0][i].charAt(j);
			if( words[0][i].length() > maxLen ) maxLen = words[0][i].length();
		}
		maxLen++;
		memo = new long[1<<n][n][2][maxLen];
		done = new boolean[1<<n][n][2][maxLen];
		return calculate(1,0,0,0)-1;
	}

	long calculate( int used, int extra, int side, int len )
	{
		if( done[used][extra][side][len] ) return memo[used][extra][side][len];
		long ret = 0;
		String x = words[1-side][extra].substring(0,len);
		if( isPalindrome(x) ) ret++;
		for( int i = 0; i < n; i++ ) if( ((used>>i)&1)==0 )
		{
			String w = words[side][i];
			int match = 0;
			while( match<len && match<w.length() && w.charAt(w.length()-match-1)==x.charAt(len-match-1) )
				match++;
			if( match==len || match==w.length() )
			{
				if( match==len ) ret += calculate( used|(1<<i), i, 1-side, w.length()-match );
				else ret += calculate( used|(1<<i), extra, side, len-match );
			}
		}
		done[used][extra][side][len] = true;
		memo[used][extra][side][len] = ret;
		return ret;
	}

	boolean isPalindrome( String s )
	{
		for( int i = 0; i < s.length(); i++ )
			if( s.charAt(i) != s.charAt(s.length()-i-1) )
				return false;
		return true;
	}

}
