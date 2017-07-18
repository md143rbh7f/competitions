/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Home
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Home().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == 0 ) return false;
		double[] x = new double[n], y = new double[n];
		for( int i = 0; i < n; i++ )
		{
			x[i] = in.nextDouble();
			y[i] = in.nextDouble();
		}
		System.out.println( Math.round( polygon_area( x, y ) ) );
		return true;
	}

	static double polygon_area( double[] x, double[] y )
	{
		double a = 0;
		for( int i = 1; i < x.length; i++ ) a += x[i-1]*y[i] - x[i]*y[i-1];
		a += x[x.length-1]*y[0] - x[0]*y[x.length-1];
		a /= 2;
		if( a < 0 ) a = -a;
		return a;
	}
}
