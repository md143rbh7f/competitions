/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TourDeFrance
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new TourDeFrance().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int f = in.nextInt(); if( f==0 ) return false;
		int r = in.nextInt(), fr = f*r;
		int[] F = new int[f], R = new int[r];
		for( int i = 0; i < f; i++ ) F[i] = in.nextInt();
		for( int i = 0; i < r; i++ ) R[i] = in.nextInt();
		double[] d = new double[fr];
		for( int i = 0; i < f; i++ ) for( int j = 0; j < r; j++ ) d[i*r+j] = 1.0*F[i]/R[j];
		Arrays.sort(d);
		double max = 0;
		for( int i = 0; i < fr-1; i++ ) if( d[i+1]/d[i] > max ) max = d[i+1]/d[i];
		System.out.printf( "%.2f\n", max );
		return true;
	}
}
