/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class ColorfulMazeTwo
{
	public double getProbability( String[] maze, int[] itsATrap )
	{
		int n = 7, N = 1<<n;
		int sx=0, sy=0;
		for( int i = 0; i < maze.length; i++ ) for( int j = 0; j < maze[0].length(); j++ )
			if( maze[i].charAt(j) == '$' )
			{
				sx = i;
				sy = j;
			}
		double[] itsNotATrap = new double[n];
		for( int i = 0; i < n; i++ ) itsNotATrap[i] = 1-itsATrap[i]/100.0;
		double res = 0;
		for( int mask = 0; mask < N; mask++ )
		{
			double prob = 1;
			for( int j = 0; j < n; j++ ) if( ((mask>>j)&1) == 1 ) prob *= itsNotATrap[j];
			seen = new boolean[maze.length][maze[0].length()];
			if( dfs(maze,mask,sx,sy) ) res = res<prob ? prob : res;
		}
		for( int mask = 0; mask < N; mask++ ) ;
		return res;
	}

	static int[] dx = { 0, 1, 0, -1 };
	static int[] dy = { 1, 0, -1, 0 };

	boolean[][] seen;

	boolean dfs( String[] maze, int mask, int x, int y )
	{
		if(
			x<0 || y<0 || x>=maze.length || y>=maze[0].length() ||
			seen[x][y] ||
			maze[x].charAt(y)=='#' ||
			( maze[x].charAt(y)>='A' && maze[x].charAt(y)<='G' && ((mask>>(maze[x].charAt(y)-'A'))&1)==0 )
			)
			return false;
		if( maze[x].charAt(y) == '!' ) return true;
		seen[x][y] = true;
		for( int i = 0; i < 4; i++ )
		{
			int tx = x+dx[i], ty = y+dy[i];
			if( dfs( maze, mask, tx, ty ) ) return true;
		}
		return false;
	}
}
