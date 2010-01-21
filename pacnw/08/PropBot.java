/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class PropBot
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		generate();
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new PropBot().solve( i );
	}

	void solve( int caseNum )
	{
		int t = in.nextInt();
		double xt = in.nextDouble()/10, yt = in.nextDouble()/10;
		double min = INF;
		for( int i = 0; i <= t; i++ )
		for( Point p : pts[i] )
		{
			double dist = d( xt, yt, p.x, p.y );
			if( dist<min ) min = dist;
		}
		System.out.printf( "%.6f\n", min*10 );
	}

	static int MAX = 24;
	static HashSet<Point>[] pts;
	static void generate()
	{
		pts = (HashSet<Point>[])(new HashSet[MAX+1]);
		for( int i = 0; i <= MAX; i++ ) pts[i] = new HashSet<Point>();
		pts[0].add( new Point(0,0) );

		for( int t = 0; t < MAX; t++ )
		PT: for( Point p : pts[t] )
		{
			SEARCH: for( int i = 1; i <= 8; i++ )
			{
				Point c = new Point( p.x+Math.cos(p.a), p.y+Math.sin(p.a), p.a );
				p.a -= Math.PI/4;
				if( t+i <= MAX )
				{
					for( int j = t+i; j >= 0; j-- )
						if( pts[j].contains(c) )
							continue SEARCH;
					pts[t+i].add(c);
					for( int j = 1; j<=8 && j+i+t<=MAX; j++ ) pts[j+i+t].remove(c);
				}
				else continue PT;
			}
		}
	}

	static double EPS = 0.000001;
	static class Point
	{
		double x, y, a;
		int hash;

		Point( double _x, double _y )
		{
			x = _x; y = _y;
			hash = (int)Math.round( 100000*x+y );
		}

		Point( double _x, double _y, double _a )
		{
			this( _x, _y );
			a = _a;
		}
		
		public int hashCode()
		{ return hash; }
		public boolean equals( Object other )
		{
			Point o = (Point)other;
			return d( x, y, o.x, o.y ) < EPS;
		}
	}

	static double d( double x1, double y1, double x2, double y2 )
	{
		double dx = x2-x1; double dy = y2-y1;
		return Math.sqrt( dx*dx+dy*dy );
	}
}
