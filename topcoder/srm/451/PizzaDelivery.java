import java.util.*;

public class PizzaDelivery
{
	int d[][] = new int[50][50], bx[] = new int[20], by[] = new int[20], bd[] = new int[20], INF = 1234567, dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };

	public int deliverAll( String[] g )
	{
		int n = g.length, m = g[0].length(), b = 0, ans = INF;
		TreeSet<int[]> q = new TreeSet<int[]>( new Comp() );
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			d[i][j] = INF;
			switch( g[i].charAt(j) )
			{
				case '$':
					bx[b] = i;
					by[b] = j;
					b++;
					break;
				case 'X':
					d[i][j] = 0;
					q.add( new int[]{ i, j } );
					break;
			}
		}
		while( !q.isEmpty() )
		{
			int x = q.first()[0], y = q.first()[1];
			q.remove( q.first() );
			for( int dir = 0; dir < 4; dir++ )
			{
				int tx = x + dx[dir], ty = y + dy[dir];
				if( tx >= 0 && tx < n && ty >= 0 && ty < m )
				{
					int dt = 0;
					if( g[x].charAt(y)=='$' || g[x].charAt(y)=='X' || g[tx].charAt(ty)=='$' || g[tx].charAt(ty) == 'X' ) dt = 2;
					else if( Math.abs( g[x].charAt(y) - g[tx].charAt(ty) ) == 1 ) dt = 3;
					else if( g[x].charAt(y) == g[tx].charAt(ty) ) dt = 1;
					else continue;
					if( d[x][y] + dt < d[tx][ty] )
					{
						q.remove( new int[]{ tx, ty } );
						d[tx][ty] = d[x][y] + dt;
						q.add( new int[]{ tx, ty } );
					}
				}
			}
		}
		for( int i = 0; i < b; i++ )
		{
			bd[i] = d[bx[i]][by[i]];
			if( bd[i] == INF ) return -1;
		}
		if( b == 1 ) return bd[0];
		Arrays.sort( bd, 0, b );
		for( int mask = 0; mask < 1<<b; mask++ )
		{
			int ta = 0, tb = 0;
			boolean afirst = true, bfirst = true;
			for( int i = b-1; i >= 0; i-- )
			{
				if( ( ( mask >> i ) & 1 ) == 0 )
				{
					if( afirst )
					{
						ta += bd[i];
						afirst = false;
					}
					else ta += 2 * bd[i];
				}
				else
				{
					if( bfirst )
					{
						tb += bd[i];
						bfirst = false;
					}
					else tb += 2 * bd[i];
				}
			}
			ans = Math.min( ans, Math.max( ta, tb ) );
		}
		return ans;
	}

	class Comp implements Comparator<int[]>
	{
		public int compare( int[] a, int[] b )
		{
			if( d[a[0]][a[1]] != d[b[0]][b[1]] ) return d[a[0]][a[1]] - d[b[0]][b[1]];
			if( a[1] != b[1] ) return a[1] - b[1];
			if( a[0] != b[0] ) return a[0] - b[0];
			return 0;
		}
	}
};
