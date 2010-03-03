/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class NameInput
{
	public int countUpDownKeyPresses( String[] sequence, String[] name )
	{
		String buf = "";
		for( int i = 0; i < sequence.length; i++ ) buf += sequence[i];
		char[] s = buf.toCharArray();
		int S = s.length;
		buf = "";
		for( int i = 0; i < name.length; i++ ) buf += name[i];
		char[] n = buf.toCharArray();
		int N = n.length;
		
		int[] first = new int[128];
		for( int i = 0; i < 128; i++ ) first[i] = -1;
		for( int i = 0; i < S; i++ ) if( first[s[i]] == -1 ) first[s[i]] = i;
		for( char c : n ) if( first[c] == -1 ) return -1;

		int[][][] closest = new int[128][2][S];
		for( int c = 0; c < 128; c++ ) if( first[c] != -1 )
		{
			int pos = first[c], last = pos;
			do
			{
				if( s[pos] == c ) last = pos;
				closest[c][0][pos] = last;
				pos++;
				if( pos == S ) pos = 0;
			}
			while( pos != first[c] );
			pos = first[c]; last = pos;
			do
			{
				if( s[pos] == c ) last = pos;
				closest[c][1][pos] = last;
				pos--;
				if( pos == -1 ) pos = S-1;
			}
			while( pos != first[c] );
		}

		int[][] dp = new int[S][2];
		for( int i = N-1; i >= 0; i-- )
		for( int j = 0; j < S; j++ )
		{
			int forward = closest[n[i]][0][j];
			int backward = closest[n[i]][1][j];
			dp[j][i%2] = Math.min(
				dp[forward][(i+1)%2]+dist(forward,j,S),
				dp[backward][(i+1)%2]+dist(backward,j,S)
				);
		}
		
		return dp[0][0];
	}

	static int dist( int a, int b, int mod )
	{
		if( b > a )
		{
			int temp = a;
			a = b;
			b = temp;
		}
		return Math.min( a-b, b+mod-a );
	}

}
