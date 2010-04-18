import java.math.*;
import java.util.*;

public class MazeOnFire
{
	int[] dx = { -1, 0, 1, 0 }, dy = { 0, 1, 0, -1 };

	public int maximumTurns( String[] maze )
	{
		int n = maze.length, m = maze[0].length();
		char[][][] g = new char[2][n][];
		for( int i = 0; i < n; i++ )
		{
			g[0][i] = maze[i].toCharArray();
			g[1][i] = maze[i].toCharArray();
		}
		for( int t = 0; t <= 2500; t++ )
		{
			boolean alive = false;
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
			if( g[t%2][i][j] == '$' )
			{
				alive = true;
				g[(t+1)%2][i][j] = '$';
				for( int d = 0; d < 4; d++ )
				{
					int tx = i+dx[d], ty = j+dy[d];
					if( tx<0 || ty<0 || tx>=n || ty>= m || g[t%2][tx][ty]!='.' ) continue;
					g[(t+1)%2][tx][ty] = '$';
				}
			}
			if( !alive ) return t;
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
			if( g[t%2][i][j] == 'F' )
			{
				g[(t+1)%2][i][j] = 'F';
				for( int d = 0; d < 4; d++ )
				{
					int tx = i+dx[d], ty = j+dy[d];
					if( tx<0 || ty<0 || tx>=n || ty>= m || g[t%2][tx][ty]=='#' ) continue;
					g[(t+1)%2][tx][ty] = 'F';
				}
			}
		}
		return -1;
	}
}
