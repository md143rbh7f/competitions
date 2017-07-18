/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TexasTrip
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new TexasTrip().solve( i );
	}

	double eps = 1e-11;
	int scale = 1024;

	void solve( int caseNum )
	{
		int n = in.nextInt();
		int[] x = new int[n], y = new int[n];
		for( int i = 0; i < n; i++ )
		{
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		double minq = -Math.PI/4, maxq = Math.PI/4, dq = (maxq-minq)/scale;
		double min = 1000;
		while( dq > eps )
		{
			double old = min, bestq = -1;
			for( double q = minq; q <= maxq; q += dq )
			{
				double cos = Math.cos(q), sin = Math.sin(q);
				double minx = 500, miny = 500, maxx = -500, maxy = -500;
				for( int i = 0; i < n; i++ )
				{
					double rx = x[i]*cos+y[i]*sin, ry = -x[i]*sin+y[i]*cos;
					if( rx < minx ) minx = rx;
					if( ry < miny ) miny = ry;
					if( rx > maxx ) maxx = rx;
					if( ry > maxy ) maxy = ry;
				}
				double d = Math.max( maxx-minx, maxy-miny );
				if( d<min )
				{
					min = d;
					bestq = q;
				}
			}
			minq = bestq-dq;
			maxq = bestq+dq;
			dq /= scale;
		}
		System.out.printf( "%.2f\n", min*min );
	}
}
