import java.math.*;
import java.util.*;

public class Gifts
{
	int dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };
	long inf = 1000000001;
	char[] chars = { 'G', 'Q', 'K' };

	public int maxGifts( String[] map, int t )
	{
		int x = map.length, y = map[0].length();
		ArrayList<int[]> pos = new ArrayList<int[]>();
		for( int c = 0; c < chars.length; c++ )
		for( int i = 0; i < x; i++ ) for( int j = 0; j < y; j++ )
		if( map[i].charAt(j)==chars[c] )
			pos.add( new int[]{i,j} );
		int n = pos.size(), g = n-2;
		long d[][] = new long[n][n];
		for( int i = 0; i < n; i++ )
		{
			LinkedList<int[]> q = new LinkedList<int[]>();
			int[] ptr = pos.get(i), dist[] = new int[x][y];
			boolean[][] seen = new boolean[x][y];
			q.add(ptr);
			seen[ptr[0]][ptr[1]] = true;
			while( !q.isEmpty() )
			{
				ptr = q.poll();
				int cx = ptr[0], cy = ptr[1];
				for( int dir = 0; dir < dx.length; dir++ )
				{
					int tx = cx+dx[dir], ty = cy+dy[dir];
					if( tx<0 || ty<0 || tx>=x || ty>=y || map[tx].charAt(ty)=='#' || seen[tx][ty] ) continue;
					seen[tx][ty] = true;
					dist[tx][ty] = dist[cx][cy]+1;
					q.add( new int[]{tx,ty} );
				}
			}
			for( int j = 0; j < n; j++ )
				if( seen[pos.get(j)[0]][pos.get(j)[1]] ) d[i][j] = dist[pos.get(j)[0]][pos.get(j)[1]];
				else d[i][j] = inf;
		}
		long[][] dp = new long[1<<g][g+1];
		for( int i = 0; i <= g; i++ ) for( int m = 0; m < 1<<g; m++ ) dp[m][i] = inf;
		for( int i = 0; i <= g; i++ ) dp[0][i] = d[n-1][i];
		for( int m = 1; m < 1<<g; m++ )
		{
			int w = Integer.bitCount(m)+1;
			for( int i = 0; i <= g; i++ ) if( (m&(1<<i))==0 )
			for( int j = 0; j < g; j++ ) if( (m&(1<<j))!=0 )
			{
				long test = w*d[i][j]+dp[m-(1<<j)][j];
				if( dp[m][i] > test ) dp[m][i] = test;
			}
		}
		int max = 0;
		for( int m = 0; m < 1<<g; m++ )
			if( dp[m][g]<=t && Integer.bitCount(m)>max )
				max = Integer.bitCount(m);
		return max;
	}
}
