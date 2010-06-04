import java.io.*;
import java.math.*;
import java.util.*;
import java.awt.Point;

public class Chess
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static BigInteger TWO = new BigInteger( "2" );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Chess().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt(), m = in.nextInt(), s1[][] = new int[n][m];
		s2 = new int[n][m];
		boolean[][] b = new boolean[n][m], done = new boolean[n][m];
		for( int i = 0; i < n; i++ )
		{
			BigInteger v = new BigInteger( in.next(), 16 );
			for( int j = 0; j < m; j++ )
			{
				b[i][m-j-1] = v.mod(TWO).equals( BigInteger.ONE );
				v = v.shiftRight(1);
			}
		}
		for( int i = n-1; i >= 0; i-- ) for( int j = m-2; j >= 0; j-- ) if( b[i][j]!=b[i][j+1] ) s1[i][j] = s1[i][j+1]+1;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			int k = i, min = s1[i][j];
			while( true )
			{
				k++;
				if( k==n || b[k][j]==b[k-1][j] ) break;
				min = Math.min( min, s1[k][j] );
				if( min<k-i ) break;
				s2[i][j]++;
			}
		}
		HashSet<Point>[][] x = (HashSet<Point>[][])(new HashSet[n][m]), y = (HashSet<Point>[][])(new HashSet[n][m]), xy = (HashSet<Point>[][])(new HashSet[n][m]);
		TreeSet<Point> pq = new TreeSet<Point>( new Comp() );
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			x[i][j] = new HashSet<Point>();
			y[i][j] = new HashSet<Point>();
			xy[i][j] = new HashSet<Point>();
		}
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			Point pt = new Point(i,j);
			int d = s2[i][j];
			x[i+d][j].add(pt);
			y[i][j+d].add(pt);
			xy[i+d][j+d].add(pt);
			pq.add(pt);
		}
		TreeMap<Integer,Integer> sizes = new TreeMap<Integer,Integer>();
		while( !pq.isEmpty() )
		{
			Point v = pq.pollFirst();
			if( done[v.x][v.y] ) continue;
			int d = s2[v.x][v.y];
			if( !sizes.containsKey(d) ) sizes.put( d, 0 );
			sizes.put( d, sizes.get(d)+1 );
			for( int i = v.x; i <= v.x+d; i++ ) for( int j = v.y; j <= v.y+d; j++ ) done[i][j] = true;
			for( int i = v.x; i <= v.x+d; i++ ) for( int j = v.y; j <= v.y+d; j++ ) for( Point p : x[i][j] ) if( !done[p.x][p.y] )
			{
				int old = s2[p.x][p.y], dd = v.x-1-p.x;
				y[p.x][p.y+old].remove(p); xy[p.x+old][p.y+old].remove(p);
				pq.remove(p); s2[p.x][p.y] = dd; pq.add(p);
				x[p.x+dd][p.y].add(p); y[p.x][p.y+dd].add(p); xy[p.x+dd][p.y+dd].add(p);
			}
			for( int i = v.x; i <= v.x+d; i++ ) for( int j = v.y; j <= v.y+d; j++ ) for( Point p : y[i][j] ) if( !done[p.x][p.y] )
			{
				int old = s2[p.x][p.y], dd = v.y-1-p.y;
				x[p.x+old][p.y].remove(p); xy[p.x+old][p.y+old].remove(p);
				pq.remove(p); s2[p.x][p.y] = dd; pq.add(p);
				x[p.x+dd][p.y].add(p); y[p.x][p.y+dd].add(p); xy[p.x+dd][p.y+dd].add(p);
			}
			for( int i = v.x; i <= v.x+d; i++ ) for( int j = v.y; j <= v.y+d; j++ ) for( Point p : xy[i][j] ) if( !done[p.x][p.y] )
			{
				int old = s2[p.x][p.y], dd = Math.max( v.x-1-p.x, v.y-1-p.y );
				x[p.x+old][p.y].remove(p); y[p.x][p.y+old].remove(p);
				pq.remove(p); s2[p.x][p.y] = dd; pq.add(p);
				x[p.x+dd][p.y].add(p); y[p.x][p.y+dd].add(p); xy[p.x+dd][p.y+dd].add(p);
			}
		}
		System.out.printf( "Case #%d: %d\n", caseNum, sizes.size() );
		for( int a : sizes.descendingKeySet() ) System.out.printf( "%d %d\n", a+1, sizes.get(a) );
	}

	int[][] s2;
	class Comp implements Comparator<Point>
	{
		public int compare( Point a, Point b )
		{
			int d = s2[b.x][b.y]-s2[a.x][a.y];
			if( d==0 ) d = a.x-b.x;
			if( d==0 ) d = a.y-b.y;
			return d;
		}
	}
}
