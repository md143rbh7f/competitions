/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class ConvexHull
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static double EPS = 0.001;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new ConvexHull().solve( i );
	}

	void solve( int caseNum )
	{
		in.nextInt();
		int n = in.nextInt();
		double[][] pts = new double[n][2];
		for( int i = 0; i < n; i++ )
		{
			pts[i][0] = in.nextInt();
			pts[i][1] = in.nextInt();
		}
		
		ArrayList<double[]> h = convex_hull( pts );
		int N = h.size();
		System.out.printf( "%d %d\n", caseNum, N );
		int start = 0;
		for( int i = 0; i < N; i++ )
		{
			if( (h.get(i)[1]>h.get(start)[1]) ||
				(h.get(i)[1]==h.get(start)[1]&&h.get(i)[0]< h.get(start)[0]) )
				start = i;
		}
		int i = start;
		do
		{
			System.out.printf( "%.0f %.0f\n", h.get(i)[0], h.get(i)[1] );
			i--;
			if( i == -1 ) i += N;
		}
		while( i != start );
	}

	static ArrayList<double[]> convex_hull( double[][] pts )
	{
		int n = pts.length;
		double[] start = pts[0];
		for( int i = 0; i < n; i++ )
			if( (pts[i][1]<start[1]) || (pts[i][1]==start[1]&&pts[i][0]<start[0]) )
				start = pts[i];
		Integer[] ptr = new Integer[n+1];
		for( int i = 0; i < n; i++ ) ptr[i] = i;
		double[] a = new double[n], d = new double[n];
		for( int i = 0; i < n; i++ )
		{
			a[i] = Math.atan2( pts[i][1]-start[1], pts[i][0]-start[0] );
			d[i] = dist( start, pts[i] );
		}
		Arrays.sort( ptr, 0, n, new AngleComparator( a, d ) );
		ptr[n] = ptr[0];
		ArrayList<double[]> h = new ArrayList<double[]>();
		h.add(pts[ptr[0]]);
		h.add(pts[ptr[1]]);
		int last = 1;
		for( int i = 2; i <= n; i++ )
		{
			while( true )
			{
				double t = turn( h.get(last-1), h.get(last), pts[ptr[i]] );
				if( t < 0 || t*t < EPS )
				{
					h.remove(last);
					last--;
				}
				else break;
				if( last==0 ) break;
			}
			last++;
			h.add(pts[ptr[i]]);
		}
		h.remove(last);
		if( h.size()==1 ) h.add(pts[ptr[n-1]]);
		return h;
	}

	static class AngleComparator implements Comparator<Integer>
	{
		double[] a, d;
		AngleComparator( double[] _a, double[] _d )
		{
			a = _a;
			d = _d;
		}
		public int compare( Integer x, Integer y )
		{
			if( a[x] > a[y] ) return 1;
			if( a[x] < a[y] ) return -1;
			if( d[x] > d[y] ) return 1;
			if( d[x] < d[y] ) return -1;
			return 0;
		}
	}

	static double turn( double[] a, double[] b, double[] c )
	{
		return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]);
	}

	static double dist( double[] x1, double[] x2 )
	{
		double d1 = x1[0]-x2[0];
		double d2 = x1[1]-x2[1];
		return Math.sqrt( d1*d1 + d2*d2 );
	}
}
