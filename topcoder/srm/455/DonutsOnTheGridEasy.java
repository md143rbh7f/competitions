import java.math.*;
import java.util.*;
import static java.lang.Math.*;

public class DonutsOnTheGridEasy
{
	public int calc( String[] grid )
	{
		int n = grid.length, m = grid[0].length(), sx[][] = new int[n][m], sy[][] = new int[n][m];
		boolean[][] g = new boolean[n][m];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ ) g[i][j] = grid[i].charAt(j)=='0';
		for( int i = 0; i < n; i++ )
		{
			sy[i][0] = g[i][0]?1:0;
			for( int j = 1; j < m; j++ ) sy[i][j] = sy[i][j-1]+(g[i][j]?1:0);
		}
		for( int j = 0; j < m; j++ )
		{
			sx[0][j] = g[0][j]?1:0;
			for( int i = 1; i < n; i++ ) sx[i][j] = sx[i-1][j]+(g[i][j]?1:0);
		}
		boolean[][][][] donut = new boolean[n][m][n][m];
		for( int i1 = 0; i1 < n; i1++ ) for( int i2 = i1+2; i2 < n; i2++ )
		for( int j1 = 0; j1 < m; j1++ ) for( int j2 = j1+2; j2 < m; j2++ )
			if( g[i1][j1]&&g[i1][j2]&&g[i2][j1]&&g[i2][j2] )
			if((sx[i2][j1]-sx[i1][j1]==i2-i1)&&(sx[i2][j2]-sx[i1][j2]==i2-i1)&&(sy[i1][j2]-sy[i1][j1]==j2-j1)&&(sy[i2][j2]-sy[i2][j1]==j2-j1))
				donut[i1][j1][i2][j2] = true;
		int[][][][] dp = new int[n][m][n][m];
		for( int dx = 2; dx < n; dx++ ) for( int i1 = 0; i1+dx < n; i1++ )
		for( int dy = 2; dy < m; dy++ ) for( int j1 = 0; j1+dy < m; j1++ )
		{
			int i2 = i1+dx, j2 = j1+dy, val = 0;
			val = max( val, dp[i1+1][j1][i2][j2] );
			val = max( val, dp[i1][j1+1][i2][j2] );
			val = max( val, dp[i1][j1][i2-1][j2] );
			val = max( val, dp[i1][j1][i2][j2-1] );
			if( donut[i1][j1][i2][j2] ) val = max( val, 1+dp[i1+1][j1+1][i2-1][j2-1] );
			dp[i1][j1][i2][j2] = val;
		}
		return dp[0][0][n-1][m-1];
	}
}
