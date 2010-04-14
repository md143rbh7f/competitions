import java.io.*;
import java.math.*;
import java.util.*;

public class Watchdog
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Watchdog().solve( i );
	}

	void solve( int caseNum )
	{
		int s = in.nextInt(), h = in.nextInt(), c[][] = new int[h][2];
		boolean[][] hatch = new boolean[s][s];
		for( int i = 0; i < h; i++ )
		{
			c[i][0] = in.nextInt();
			c[i][1] = in.nextInt();
			hatch[c[i][0]][c[i][1]] = true;
		}
		for( int x = 1; x < s; x++ ) for( int y = 1; y < s; y++ )
		if( !hatch[x][y] )
		{
			double d = 0;
			for( int i = 0; i < h; i++ )
			{
				int dx = x-c[i][0], dy = y-c[i][1];
				d = Math.max( d, Math.sqrt( dx*dx+dy*dy ) );
			}
			int death = Math.min( x, Math.min( y, Math.min( s-x, s-y ) ) );
			if( d <= death )
			{
				System.out.printf( "%d %d\n", x, y );
				return;
			}
		}
		System.out.println( "poodle" );
	}
}
