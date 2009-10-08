/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Pascal
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Pascal().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == -1 ) return false;

		char[][] map = new char[n][];
		for( int i = 0; i < n; i++ )
		{
			map[i] = in.next().toCharArray();
			for( int j = 0; j < n; j++ )
				map[i][j] -= '0';
		}

		long[][] ways = new long[n][n];
		ways[0][0] = 1;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < n; j++ )
			{
				int len = map[i][j];
				if( len != 0 )
				{
					if( i + len < n )
						ways[i+len][j] += ways[i][j];
					if( j + len < n )
						ways[i][j+len] += ways[i][j];
				}
			}
		System.out.println( ways[n-1][n-1] );
		return true;
	}
}
