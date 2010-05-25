import java.io.*;
import java.math.*;
import java.util.*;

public class Camels
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	static int n, t, memo[][][][][];
	static boolean seen[][][][][];
	public static void main( String[] args )
	{
		n = in.nextInt(); t = in.nextInt();
		memo = new int[n][t+1][t][4][4];
		seen = new boolean[n][t+1][t][4][4];
		int ans = 0;
		for( int i = 0; i < 4; i++ ) for( int j = 0; j < i; j++ ) ans += rec( 1, 0, 0, i, j );
		System.out.println( ans );
	}

	static int rec( int x, int h, int v, int y, int yprev )
	{
		if( seen[x][h][v][y][yprev] ) return memo[x][h][v][y][yprev];
		int ans = 0;
		if( x==n-2 )
		{
			if( v==t-1 )
			{
				for( int ynext = 0; ynext < y; ynext++ )
				{
					if( ynext<y && yprev<y )
					{
						if( h<t ) ans++;
					}
					else
					{
						if( h==t ) ans++;
					}
				}
			}
		}
		else
		{
			for( int ynext = 0; ynext < 4; ynext++ ) if( ynext != y )
			{
				if( ynext<y && yprev<y )
				{
					if( h<t ) ans += rec( x+1, h+1, v, ynext, y );
				}
				else if( ynext>y && yprev>y )
				{
					if( v<t-1 ) ans += rec( x+1, h, v+1, ynext, y );
				}
				else ans += rec( x+1, h, v, ynext, y );
			}
		}
		seen[x][h][v][y][yprev] = true;
		return memo[x][h][v][y][yprev] = ans;
	}
}
