import java.math.*;
import java.util.*;
import java.awt.Point;

public class MazeMaker
{
	int inf = 1234567;
	public int longestPath( String[] maze, int x0, int y0, int[] dx, int[] dy )
	{
		int n = maze.length, m = maze[0].length(), ans = 0;
		boolean[][] g = new boolean[n][m];
		dist = new int[n][m];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			g[i][j] = maze[i].charAt(j)=='.';
			dist[i][j] = inf;
		}

		dist[x0][y0] = 0;
		PriorityQueue<Point> q = new PriorityQueue<Point>( 11, new Comp() );
		q.add( new Point(x0,y0) );
		while( !q.isEmpty() )
		{
			Point p = q.poll();
			for( int d = 0; d < dx.length; d++ )
			{
				Point c = new Point( p.x+dx[d], p.y+dy[d] );
				if( c.x>=0 && c.x<n && c.y>=0 && c.y<m && g[c.x][c.y] && dist[c.x][c.y]>dist[p.x][p.y]+1 )
				{
					dist[c.x][c.y] = dist[p.x][p.y]+1;
					q.remove(c);
					q.add(c);
				}
			}
		}
		
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		if( g[i][j] )
		{
			if( dist[i][j]==inf ) return -1;
			ans = dist[i][j]>ans ? dist[i][j] : ans;
		}
		return ans;
	}

	int dist[][];
	class Comp implements Comparator<Point>
	{
		public int compare( Point a, Point b )
		{
			int d = dist[a.x][a.y]-dist[b.x][b.y];
			if( d==0 ) d = a.x-b.x;
			if( d==0 ) d = a.y-b.y;
			return d;
		}
	}
}
