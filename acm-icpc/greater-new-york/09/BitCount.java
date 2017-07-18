/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class BitCount
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		generate();
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new BitCount().solve( i );
	}

	void solve( int caseNum )
	{
		in.nextInt();
		int b = in.nextInt(), c = in.nextInt();
		System.out.printf( "%d %d\n", caseNum, x[b][c][0]+x[b][c][1] );
	}

	static long[][][] x;
	static void generate()
	{
		int B = 101, C = 101;
		x = new long[B][C][2];
		
		x[1][0][0] = x[1][0][1] = 1;
		for( int b = 2; b < B; b++ )
		{
			x[b][0][0] = x[b-1][0][0]+x[b-1][0][1];
			x[b][0][1] = x[b-1][0][0];
			for( int c = 1; c < C && c < b; c++ )
			{
				x[b][c][0] = x[b-1][c][0]+x[b-1][c][1];
				x[b][c][1] = x[b-1][c][0]+x[b-1][c-1][1];
			}
		}
	}
}
