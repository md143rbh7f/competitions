/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Polycube
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Polycube().solve( i );
	}

	static int[][] D = 
	{
		{ 0, 0, 1 },
		{ 0, 1, 0 },
		{ 1, 0, 0 },
		{ 0, 0, -1 },
		{ 0, -1, 0 },
		{ -1, 0, 0 }
	};

	void solve( int caseNum )
	{
		int n = in.nextInt();
		int[][] coords = new int[n][3];
		int[] max = new int[3], min = new int[3];
		String[] buffer;
		for( int i = 0; i < n; i++ )
		{
			buffer = in.next().split( "," );
			for( int j = 0; j < 3; j++ )
			{
				coords[i][j] = Integer.parseInt( buffer[j] );
				if( coords[i][j] < min[j] ) min[j] = coords[i][j];
				else if( coords[i][j] > max[j] ) max[j] = coords[i][j];
			}
		}

		boolean[][][] isCube = new boolean[3+max[0]-min[0]][3+max[1]-min[1]][3+max[2]-min[2]];
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < 3; j++ ) coords[i][j] += 1-min[j];
			int x = coords[i][0], y = coords[i][1], z = coords[i][2];
			if( i > 0 )
			{
				boolean isValid = false;
				for( int j = 0; j < D.length; j++ )
				{
					int tx = x + D[j][0], ty = y + D[j][1], tz = z + D[j][2];
					isValid |= isCube[tx][ty][tz];
				}
				if( isCube[x][y][z] || !isValid )
				{
					System.out.println( caseNum + " NO " + (i+1) );
					return;
				}
			}
			isCube[x][y][z] = true;
		}

		int area = 0;
		for( int i = 0; i < n; i++ )
		{
			int x = coords[i][0], y = coords[i][1], z = coords[i][2];
			for( int j = 0; j < D.length; j++ )
			{
				int tx = x + D[j][0], ty = y + D[j][1], tz = z + D[j][2];
				if( !isCube[tx][ty][tz] ) area++;
			}
		}

		System.out.println( caseNum + " " + area );
	}

}
