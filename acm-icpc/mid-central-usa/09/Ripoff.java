/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Ripoff
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int NINF = -1000000000;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Ripoff().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt(); if( n == 0 ) return false;
		int s = in.nextInt(), t = in.nextInt();

		int[] nums = new int[n+2];
		for( int i = 0; i < n; i++ ) nums[i+1] = in.nextInt();

		int[][] max = new int[t+1][n+2];
		for( int i = 0; i <= t; i++ ) for( int j = 1; j < n+2; j++ ) max[i][j] = NINF;
		for( int i = 1; i <= t; i++ )
			for( int j = 0; j < n+2; j++ )
				for( int k = j+1; k <= j+s && k < n+2; k++ )
					max[i][k] = Math.max( max[i][k], max[i-1][j]+nums[k] );
		System.out.println( max[t][n+1] );

		return true;
	}
}
