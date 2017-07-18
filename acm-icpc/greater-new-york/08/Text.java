/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Text
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int OVER_NINETHOUSAAAAAAND = 9001;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Text().solve( i );
	}

	void solve( int caseNum )
	{
		int k = in.nextInt();
		double[] freq = new double[26];
		for( int i = 0; i < 26; i++ ) freq[i] = in.nextDouble() / 100;

		double[][] tot = new double[26][26];
		for( int i = 0; i < 26; i++ )
		{
			for( int j = 0; j < i; j++ ) tot[i][j] = OVER_NINETHOUSAAAAAAND;
			for( int j = i; j-i < 8 && j < 26; j++ ) for( int l = j; l-i < 8 && l < 26; l++ ) tot[i][l] += (j-i+1)*freq[j];
			for( int j = i+8; j < 26; j++ ) tot[i][j] = OVER_NINETHOUSAAAAAAND;
		}

		double[] best = new double[26];
		int[][] prev = new int[k][26];
		for( int i = 0; i < 8; i++ ) best[i] = tot[0][i];
		for( int i = 8; i < 26; i++ ) best[i] = OVER_NINETHOUSAAAAAAND;
		for( int i = 1; i < k; i++ )
		{
			double[] better = new double[26];
			for( int j = 0; j < 26; j++ ) better[j] = OVER_NINETHOUSAAAAAAND;
			for( int j = 0; j < 26; j++ )
			{
				for( int l = j < 8 ? 0 : j-8; l < j; l++ )
				{
					double guess = best[l] + tot[l+1][j];
					if( guess < better[j] )
					{
						better[j] = guess;
						prev[i][j] = l;
					}
				}
			}
			best = better;
		}

		System.out.printf( "%d %.3f ", caseNum, best[25] );
		boolean[] spaced = new boolean[26];
		int path = 25;
		for( int i = k-1; i > 0; i-- )
		{
			path = prev[i][path];
			spaced[path] = true;
		}
		for( int i = 0; i < 26; i++ ) System.out.print( (char)( 'A' + i ) + ( spaced[i] ? " " : "" ) );
		System.out.println();
	}

}
