/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Connect
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Connect().solve( caseNum++ ) );
	}

	final static int[] DX = { 1, 2, 2, 1, -1, -2, -2, -1 };
	final static int[] DY = { 2, 1, -1, -2, -2, -1, 1, 2 };

	int n;
	LinkedList<int[]> segments;
	boolean solve( int caseNum )
	{
		n = in.nextInt() + 1;
		if( n == 1 ) return false;
		int m = in.nextInt();

		int[][] parents = new int[2][n*n], seen = new int[n][n];
		for( int i = 0; i < n*n; i++ ) parents[0][i] = parents[1][i] = -1;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) seen[i][j] = -1;
		segments = new LinkedList<int[]>();

		int x, y, tx, ty, pl = 0;
		for( int i = 0; i < m; i++ )
		{
			pl = i%2;
			x = in.nextInt(); y = in.nextInt();
			seen[x][y] = pl;
			for( int j = 0; j < DX.length; j++ )
			{
				tx = x + DX[j]; ty = y + DY[j];
				int[] segment = { x, y, tx, ty };
				if( tx >= 0 && tx < n && ty >= 0 && ty < n && seen[tx][ty] == pl && nonintersecting( segment ) )
				{
					merge( parents[pl], convert( tx, ty ), convert( x, y ) );
					segments.add( segment );
				}
			}
		}

		int[] c1 = new int[2], c2 = new int[2];
		int cc1, cc2;
		for( int i = 0; i < n; i++ )
		{
			c1[1-pl] = i;
			c1[pl] = 0;
			cc1 = convert( c1[0], c1[1] );
			for( int j = 0; j < n; j++ )
			{
				c2[1-pl] = j;
				c2[pl] = n - 1;
				cc2 = convert( c2[0], c2[1] );
				if( find( parents[pl], cc1 ) == find( parents[pl], cc2 ) )
				{
					System.out.println( "yes" );
					return true;
				}
			}
		}
		System.out.println( "no" );
		return true;
	}

	boolean nonintersecting( int[] s )
	{
		for( int[] t : segments )
		{
			double m1 = m( s ), b1 = s[1] - m1*s[0];
			double m2 = m( t ), b2 = t[1] - m2*t[0];
			if( (m1-m2)*(m1-m2) > 0.01 )
			{
				double intersect = (b1-b2)/(m2-m1);
				double value = intersect * m1 + b1;
				int minx1 = Math.min( s[0], s[2] ), maxx1 = Math.max( s[0], s[2] );
				int minx2 = Math.min( t[0], t[2] ), maxx2 = Math.max( t[0], t[2] );
				int miny1 = Math.min( s[1], s[3] ), maxy1 = Math.max( s[1], s[3] );
				int miny2 = Math.min( t[1], t[3] ), maxy2 = Math.max( t[1], t[3] );
				if(
					intersect > minx1 && intersect < maxx1
					&&
					intersect > minx2 && intersect < maxx2
					&&
					value > miny1 && value < maxy1
					&&
					value > miny2 && value < maxy2
					)
					return false;
					//System.out.println(intersect+" "+Arrays.toString(s)+" "+m1+" "+Arrays.toString(t)+" "+m2);
			}
		}
		return true;
	}

	double m( int[] s )
	{
		return (s[3]-s[1])/(1.0*s[2]-s[0]);
	}

	int convert( int x, int y )
	{
		return n*x + y;
	}

	int find( int[] parent, int x )
	{
		int ptr = x;
		while( parent[ptr] > -1 ) ptr = parent[ptr];
		while( x != ptr )
		{
			int old = x;
			x = parent[x];
			parent[old] = ptr;
		}
		return ptr;
	}

	int merge( int[] parent, int x, int y )
	{
		x = find( parent, x ); y = find( parent, y );

		if( x != y )
		{
			if( parent[x] > parent[y] )
			{
				int temp = x;
				x = y;
				y = temp;
			}
			parent[x] += parent[y];
			parent[y] = x;
		}

		return -parent[x];
	}
}
