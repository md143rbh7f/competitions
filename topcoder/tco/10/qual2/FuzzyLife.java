import java.math.*;
import java.util.*;

public class FuzzyLife
{
	int N, M, dx[] = { 0, 0, 1, 1, 1, -1, -1, -1 }, dy[] = { 1, -1, 0, 1, -1, 0, 1, -1 };
	char[] test = { '0', '1' };
	public int survivingCells( String[] grid )
	{
		int n = grid.length, m = grid[0].length();
		N = n+2; M = m+2;
		char[][] g = new char[N][M];
		Arrays.fill( g[0], '0' );
		Arrays.fill( g[N-1], '0' );
		for( int i = 0; i < n; i++ )
		{
			char[] t = grid[i].toCharArray();
			g[i+1][0] = g[i+1][M-1] = '0';
			for( int j = 0; j < m; j++ ) g[i+1][j+1] = t[j];
		}
		for( int i = 0; i < N; i++ ) for( int j = 0; j < M; j++ )
		if( g[i][j]=='?' )
		{
			int count[] = new int[2];
			for( int z = 0; z < 2; z++ )
			{
				g[i][j] = test[z];
				count[z] = sim(g);
			}
			if( count[0] > count[1] ) g[i][j] = '0';
		}
		return sim(g);
	}

	int sim( char[][] g )
	{
		int count[][] = new int[N][M], ans = 0;
		for( int i = 0; i < N; i++ ) for( int j = 0; j < M; j++ )
		if( g[i][j] == '1' )
		for( int d = 0; d < dx.length; d++ )
		{
			int tx = i+dx[d], ty = j+dy[d];
			if( tx>=0 && tx<N && ty>=0 && ty<M ) count[tx][ty]++;
		}
		for( int i = 0; i < N; i++ ) for( int j = 0; j < M; j++ )
		{
			if( g[i][j]=='1' && (count[i][j]<2||count[i][j]>3) );
			else if( g[i][j]=='0' && count[i][j]==3 ) ans++;
			else if( g[i][j]=='1' ) ans++;
		}
		return ans;
	}
}
