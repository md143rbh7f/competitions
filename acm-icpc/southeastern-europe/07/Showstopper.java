import java.io.*;
import java.util.*;

public class Showstopper
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int n = 0, a[][] = new int[100000][3];

	static void work()
	{
		if( n==0 ) return;
		int best = Integer.MAX_VALUE;
		for( int d = 1<<30; d > 0; d >>= 1 )
		{
			int cnt = 0, x = best-d;
			for( int i = 0; i < n; i++ ) if( x>=a[i][0] ) cnt += ( ( x < a[i][1] ? x : a[i][1] ) - a[i][0] ) / a[i][2] + 1;
			if( cnt%2==1 ) best = x;
		}
		int cnt = 0;
		for( int i = 0; i < n; i++ ) if( best>=a[i][0] && best<=a[i][1] && (best-a[i][0])%a[i][2]==0 ) cnt++;
		if( cnt%2==1 ) System.out.printf( "%d %d\n", best, cnt );
		else System.out.println( "no corruption" );
		n = 0;
	}

	public static void main( String[] args )
	{
		while( in.hasNextLine() )
		{
			String[] s = in.nextLine().split(" ");
			if( s[0].length()==0 )
			{
				work();
				continue;
			}
			for( int i = 0; i < 3; i++ ) a[n][i] = Integer.parseInt(s[i]);
			n++;
		}
		work();
	}
}
