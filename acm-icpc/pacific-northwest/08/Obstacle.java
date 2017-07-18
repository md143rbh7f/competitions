/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Obstacle
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Obstacle().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n==0 ) return false;

		int g[][] = new int[n][n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) g[i][j] = in.nextInt();

		int d[][] = new int[n][n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) d[i][j] = INF;
		d[0][0] = 0;
		PriorityQueue<int[]> q = new PriorityQueue<int[]>( 42, new Comp( d ) );
		q.add( new int[]{ 0, 0 } );
		while( !q.isEmpty() )
		{
			int i[] = q.poll(), dist = d[i[0]][i[1]] + g[i[0]][i[1]];
			for( int dir = 0; dir < 4; dir++ )
			{
				int tx = i[0]+dx[dir], ty = i[1]+dy[dir], j[] = { tx, ty };
				if( tx < 0 || ty < 0 || tx >= n || ty >= n ) continue;
				if( dist < d[tx][ty] )
				{
					q.remove(j);
					d[tx][ty] = dist;
					q.add(j);
				}
			}
		}

		System.out.printf( "Problem %d: %d\n", caseNum, d[n-1][n-1]+g[n-1][n-1] );

		return true;
	}

	class Comp implements Comparator<int[]>
	{
		int[][] dist;
		Comp( int[][] _dist )
		{
			dist = _dist;
		}

		public int compare( int[] a, int[] b )
		{
			if( dist[a[0]][a[1]]!=dist[b[0]][b[1]] ) return dist[a[0]][a[1]]-dist[b[0]][b[1]];
			if( a[1]!=b[1] ) return a[1]-b[1];
			return a[0]-b[0];
		}
	}
}
