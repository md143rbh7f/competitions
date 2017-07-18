/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Cell
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static double EPS = 0.0001;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Cell().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int t = in.nextInt(); if( t==0 ) return false;
		int r = in.nextInt()+1;

		int[][] tx = new int[t][3];
		for( int i = 0; i < t; i++ ) for( int j = 0; j < 3; j++ ) tx[i][j] = in.nextInt();

		double[][] rx = new double[r][2];
		double dtot = 0;
		for( int i = 0; i < r; i++ ) for( int j = 0; j < 2; j++ ) rx[i][j] = in.nextInt();
		for( int i = 1; i < r; i++ ) dtot += dist( rx[i-1], rx[i] );

		int rr = (int)Math.round( dtot )+1, count = 0;
		double rd[][] = new double[rr][2], leftover = 0, d[] = null, len;
		for( int i = 1; i < r; i++ )
		{
			d = diff( rx[i], rx[i-1] );
			len = size(d);
			scale( d, 1/len );
			add( rx[i-1], rd[count] );
			if( leftover > EPS )
			{
				scale( d, leftover );
				add( d, rd[count] );
				scale( d, 1/leftover );
				len -= leftover;
			}
			count++;
			int pts = (int)len;
			leftover = len-pts;
			if( leftover > EPS )
			{
				leftover = 1-leftover;
				pts++;
			}
			for( int j = 1; j < pts && count < rr; j++ )
			{
				add( rd[count-1], rd[count] );
				add( d, rd[count] );
				count++;
			}
		}
		if( EPS+rr > dtot+1 ) add( rx[r-1], rd[count] );

		int sig = -1, newsig = -1;
		int last = -1, newlast = -1;
		for( int i = 0; i < rr; i++ )
		{
			sig = newsig = -1;
			for( int j = 0; j < t; j++ )
			{
				newsig = sigstr( tx[j], rd[i] );
				if( newsig > sig )
				{
					sig = newsig;
					newlast = j;
				}
			}
			if( newlast != last )
			{
				last = newlast;
				System.out.printf( "(%d,%c) ", i, last+'A' );
			}
		}
		System.out.println();

		return true;
	}

	static int sigstr( int[] tow, double[] x )
	{
		double d1 = x[0]-tow[0];
		double d2 = x[1]-tow[1];
		return (int)Math.round(tow[2]/(d1*d1+d2*d2));
	}
	
	static double dist( double[] x1, double[] x2 )
	{
		double d1 = x1[0]-x2[0];
		double d2 = x1[1]-x2[1];
		return Math.sqrt( d1*d1 + d2*d2 );
	}

	static double size( double[] x )
	{
		return Math.sqrt( x[0]*x[0] + x[1]*x[1] );
	}

	static void scale( double[] x, double c )
	{
		for( int i = 0; i < x.length; i++ ) x[i] *= c;
	}

	static void add( double[] x, double[] y )
	{
		for( int i = 0; i < x.length; i++ ) y[i] += x[i];
	}

	static double[] diff( double[] x, double[] y )
	{
		double[] ans = { x[0]-y[0], x[1]-y[1] };
		return ans;
	}
}
