import java.util.*;

public class HillWalker
{
	int D[][][] = new int[2][50][50], h[][] = new int[50][50], dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
	
	public int highestPoint( String[] H, int maxd, int time )
	{
		int n = H.length, m = H[0].length();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			if( H[i].charAt(j) >= 'A' && H[i].charAt(j) <= 'Z' ) h[i][j] = H[i].charAt(j) - 'A';
			else h[i][j] = H[i].charAt(j) - 'a' + 26;
		}
		for( int r = 0; r < 2; r++ )
		{
			int[][] d = D[r];
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) d[i][j] = 1234567;
			TreeSet<int[]> q = new TreeSet<int[]>( new Comp( d ) );
			d[0][0] = 0;
			q.add( new int[]{ 0, 0 } );
			while( !q.isEmpty() )
			{
				int x = q.first()[0], y = q.first()[1];
				q.remove( q.first() );
				for( int dir = 0; dir < 4; dir++ )
				{
					int tx = x + dx[dir], ty = y + dy[dir];
					if( tx < 0 || tx >= n || ty < 0 || ty >= m ) continue;
					int dd = h[x][y] - h[tx][ty];
					if( dd * dd > maxd * maxd ) continue;
					int td = d[x][y] + ( r == 0 ? ( dd >= 0 ? 1 : dd * dd ) : ( dd <= 0 ? 1 : dd * dd ) );
					if( td < d[tx][ty]  )
					{
						q.remove( new int[]{ tx, ty } );
						d[tx][ty] = td;
						q.add( new int[]{ tx, ty } );
					}
				}
			}
		}
		int ans = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) if( D[0][i][j] + D[1][i][j] <= time && h[i][j]>ans ) ans = h[i][j];
		return ans;
	}

	class Comp implements Comparator<int[]>
	{
		int[][] d;
		Comp( int[][] _d ) { d = _d; }
		public int compare( int[] a, int[] b )
		{
			if( d[a[0]][a[1]] != d[b[0]][b[1]] ) return d[a[0]][a[1]] - d[b[0]][b[1]];
			if( a[1] != b[1] ) return a[1] - b[1];
			if( a[0] != b[0] ) return a[0] - b[0];
			return 0;
		}
	}
}
