/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Rooks
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Rooks().solve( caseNum++ ) );
	}

	static int n = 15;
	static int nn = 1<<n;
	boolean solve( int caseNum )
	{
		String line = in.next();
		if( line.length() == 3 ) return false;

		boolean[][] g = new boolean[n][n];
		for( int i = 0; i < n; i++ )
		{
			if( i != 0 ) line = in.next();
			for( int j = 0; j < n; j++ ) if( line.charAt(j)=='#' ) g[i][j] = true;
		}

		int min = 15, test, bits;
		boolean[] hit = new boolean[n];
		for( int i = 0; i < nn; i++ )
		{
			test = 0;
			for( int j = 0; j < n; j++ ) hit[j] = false;
			for( int j = 0; j < n; j++ ) if( ((i>>j)&1) == 0 ) for( int k = 0; k < n; k++ ) if( g[j][k] ) hit[k] = true;
			for( int j = 0; j < n; j++ ) if( hit[j] ) test++;
			bits = Integer.bitCount(i); 
			test = ( test>bits ? test : bits );
			min = ( test<min ? test : min );
		}

		System.out.println( min );
		
		return true;
	}
}
