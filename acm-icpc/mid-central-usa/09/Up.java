/*
	Siyang Chen

	Note: THIS PROBLEM SUCKS!!!!
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Up
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static long INF = 11111111111l;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Up().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int end = in.nextInt(); if( end == 0 ) return false;
		int jump = in.nextInt(), n = in.nextInt(), nn = 2*n+2;
		
		long[] pts = new long[nn], g[] = new long[nn][nn];
		for( int i = 0; i < n; i++ )
		{
			pts[i] = in.nextLong();
			pts[i+n] = in.nextLong();
		}
		pts[nn-1] = end;

		for( int i = 0; i < n; i++ ) for( int j = 0; j < nn; j++ ) if( i+n!=j ) g[i][j] = INF;
		for( int i = n; i < nn; i++ )
		{
			int min = 42;
			long max = INF;
			END: for( int j = 0; j < nn; j++ )
			{
				if( pts[i] <= pts[j] && pts[j] < max )
				{
					if( j < min ) min = j;
					long d = 0, last = pts[i];
					for( int k = min; k < j && k < n && pts[k] < pts[j]; k++ ) if( (pts[k]-last)%jump == 0 )
					{
						d += (pts[k]-last)/jump;
						last = pts[k];
						for( int l = k; last==pts[l]; l--, last-- )
							if( k-l==jump-1 )
							{
								max = pts[j];
								g[i][j] = INF;
								continue END;
							}
							else if( l==0 )
							{
								last--;
								break;
							}
					}
					d += (pts[j]-last+jump-1)/jump;
					g[i][j] = d;
				}
				else g[i][j] = INF;
			}
		}

		long[] d = dijkstra( g, nn-2 );
		System.out.println( d[nn-1] );

		return true;
	}

	static long[] dijkstra( long[][] g, int start )
	{
		long[] d = new long[g.length];
		for( int i = 0; i < g.length; i++ ) d[i] = INF;
		d[start] = 0;
		PriorityQueue<Integer> q = new PriorityQueue<Integer>( g.length, new DistanceComparator( d ) );
		q.add( start );
		while( !q.isEmpty() )
		{
			int v = q.poll();
			for( int c = 0; c < g.length; c++ ) if( d[c] > d[v]+g[v][c] )
			{
				d[c] = d[v]+g[v][c];
				q.remove( c );
				q.add( c );
			}
		}
		return d;
	}

	static class DistanceComparator implements Comparator<Integer>
	{
		long[] d;
		DistanceComparator( long[] _d ) { d = _d; }
		public int compare( Integer a, Integer b )
		{
			if( d[a] > d[b] ) return 1;
			if( d[a] < d[b] ) return -1;
			return 0;
		}
	}

}
