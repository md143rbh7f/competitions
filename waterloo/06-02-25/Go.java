/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Go
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int NINF = -1024;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Go().solve( caseNum++ ) );
	}

	final static int DX[] = { 1, 0, -1, 0 }, DY[] = { 0, 1, 0, -1 }, B = 0, W = 1;
	int map[][], n, m; boolean[][] seen;
	boolean solve( int caseNum )
	{
		n = in.nextInt(); m = in.nextInt();
		if( n == 0 ) return false;
		int d = (n-1)/2;
		map = new int[n][n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) map[i][j] = -1;

		int score[] = {0,0}, x, y, c, tx, ty;
		String[] line;
		for( int i = 0; i < m; i++ )
		{
			line = in.next().split( "[(,)]" );
			c = line[0].charAt(0) == 'B' ? B : W;
			x = Integer.parseInt( line[1] ) + d;
			y = Integer.parseInt( line[2] ) + d;
			map[x][y] = c;
			for( int j = 0; j < 4; j++ )
			{
				seen = new boolean[n][n];
				if( !dead( x + DX[j], y + DY[j], 1-c ) ) continue;
				for( int k = 0; k < n; k++ )
					for( int l = 0; l < n; l++ )
						if( seen[k][l] )
						{
							map[k][l] = -1;
							score[c]++;
						}
			}
		}

		seen = new boolean[n][n];
		int[] temp;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
			{
				temp = owned( i, j );
				if( temp != null && temp[0] != -1 ) score[temp[0]] += temp[1];
			}

		System.out.printf( "%d %d\n", score[0], score[1] );

		return true;
	}

	// true if area is dead, false otherwise
	boolean dead( int x, int y, int c )
	{
		if( x < 0 || x == n || y < 0 || y == n || map[x][y] == 1-c || seen[x][y] )
			return true;
		if( map[x][y] == -1 )
			return false;
		seen[x][y] = true;
		boolean isDead = true;
		for( int i = 0; i < 4; i++ )
			isDead &= dead( x + DX[i], y + DY[i], c );
		return isDead;
	}

	// invalid area = null, [0] = owner (-1 if ambiguous), [1] = num owned
	int[] owned( int x, int y )
	{
		int[] ret = { -1, 0 };
		if( x < 0 || x == n || y < 0 || y == n || seen[x][y] )
			return ret;
		ret[0] = map[x][y];
		if( map[x][y] != -1 )
			return ret;
		seen[x][y] = true;
		ret[1] = 1;
		int[] temp;
		boolean invalid = false;
		for( int i = 0; i < 4; i++ )
		{
			temp = owned( x + DX[i], y + DY[i] );
			if( temp == null )
			{
				invalid = true;
				continue;
			}
			if( ret[0] == -1 ) ret[0] = temp[0];
			else if( temp[0] != -1 && ret[0] != temp[0] ) invalid = true;
			ret[1] += temp[1];
		}
		if( invalid ) return null;
		return ret;
	}

}
