/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Image
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Image().solve( caseNum++ ) );
	}

	static int[]
		DX = { 1, 0, -1, 0, 1, 1, -1, -1 },
		DY = { 0, 1, 0, -1, 1, -1, 1, -1 };
	char[][] map;
	boolean[][] seen;
	int X, Y;
	boolean solve( int caseNum )
	{
		X = in.nextInt(); Y = in.nextInt();
		int x = in.nextInt(), y = in.nextInt();
		if( X == 0 ) return false;

		map = new char[X][Y];
		seen = new boolean[X][Y];
		for( int i = 0; i < X; i++ )
			map[i] = in.next().toCharArray();

		int count = dfs( x-1, y-1 );
		System.out.println( count );

		return true;
	}

	int dfs( int x, int y )
	{
		if( seen[x][y] ) return 0;
		seen[x][y] = true;
		int count = 0;
		for( int i = 0; i < 8; i++ )
		{
			int tx = x+DX[i], ty = y+DY[i];
			if( tx < 0 || ty < 0 || tx == X || ty == Y || map[tx][ty] != 'X' )
				count += i < 4 ? 1 : 0;
			else count += dfs( tx, ty );
		}
		return count;
	}
}
