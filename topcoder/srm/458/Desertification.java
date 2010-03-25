/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Desertification
{
	static int dx[] = { 0, 1, 0, -1 };
	static int dy[] = { 1, 0, -1, 0 };
	public int desertArea( String[] island, int T )
	{
		int n = island.length, m = island[0].length();
		boolean[][][] map = new boolean[2][n][m];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
			map[0][i][j] = island[i].charAt(j)=='D';
		int count = 0, max = m*n;
		for( int t = 0; t<T && t<max; t++ )
		{
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
			if( map[t%2][i][j] )
			{
				for( int k = 0; k < 4; k++ )
				{
					int ti = i+dx[k], tj=j+dy[k];
					if( ti>=0 && ti<n && tj>=0 && tj<m )
						map[(t+1)%2][ti][tj] = true;
				}
				map[(t+1)%2][i][j] = true;
				map[t%2][i][j] = false;
			}
			count = 0;
			for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
				if( map[(t+1)%2][i][j] )
					count++;
		}
		return count;
	}
}
