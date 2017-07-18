import java.io.*;
import java.math.*;
import java.util.*;

public class Watersheds
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Watersheds().solve( i );
	}

	static int[] dy = { -1, 0, 0, 1 }, dx = { 0, -1, 1, 0 }, sink = { -1, -1 };
	int y, x, map[][], parent[][][], res[][];
	char[] dict;

	void solve( int caseNum )
	{
		y = in.nextInt(); x = in.nextInt();
		map = new int[y][x];
		parent = new int[y][x][];
		res = new int[y][x];
		for( int i = 0; i < y; i++ ) for( int j = 0; j < x; j++ ) map[i][j] = in.nextInt();
		for( int i = 0; i < y; i++ ) for( int j = 0; j < x; j++ )
		{
			int low = Integer.MAX_VALUE, lowd = -1;
			for( int d = 0; d < 4; d++ )
			{
				int ty = i+dy[d], tx = j+dx[d];
				if( ty>=0 && ty<y && tx>=0 && tx<x && map[ty][tx]<low )
				{
					low = map[ty][tx];
					parent[i][j] = new int[]{ ty, tx };
				}
			}
			if( map[i][j]<=low ) parent[i][j] = sink;
		}
		int cur = 0;
		for( int i = 0; i < y; i++ ) for( int j = 0; j < x; j++ ) if( parent[i][j]==sink ) fill( i, j, cur++ );
		char out = 'a';
		dict = new char[cur];
		for( int i = 0; i < y; i++ ) for( int j = 0; j < x; j++ ) if( dict[res[i][j]]==0 ) dict[res[i][j]] = out++;
		System.out.printf( "Case #%d:\n", caseNum );
		for( int i = 0; i < y; i++ )
		{
			for( int j = 0; j < x; j++ ) System.out.print( dict[res[i][j]]+" " );
			System.out.println();
		}
	}

	void fill( int i, int j, int v )
	{
		res[i][j] = v;
		for( int d = 0; d < 4; d++ )
		{
			int ty = i+dy[d], tx = j+dx[d];
			if( ty>=0 && ty<y && tx>=0 && tx<x && parent[ty][tx][0]==i && parent[ty][tx][1]==j )
				fill( ty, tx, v );
		}
	}
}
