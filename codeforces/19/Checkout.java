import java.io.*;
import java.math.*;
import java.util.*;

public class Checkout
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	static int T = 2000, TT = 2*T;
	static long INF = 1l<<50, dp[][] = new long[2][TT+1];

	public static void main( String[] args )
	{
		int n = in.nextInt(), t[] = new int[n], c[] = new int[n];
		for( int i = 0; i < n; i++ )
		{
			t[i] = in.nextInt();
			c[i] = in.nextInt();
		}
		for( int i = 0; i < 2; i++ ) for( int j = 0; j <= TT; j++ ) dp[i][j] = INF;
		dp[0][T] = 0;
		for( int ii = 0; ii < n; ii++ )
		{
			int i = ii%2;
			for( int j = 0; j <= TT; j++ ) if( dp[i][j]<INF )
			{
				if( j>0 ) dp[1-i][j-1] = Math.min( dp[1-i][j-1], dp[i][j] );
				if( j+t[ii]<=TT ) dp[1-i][j+t[ii]] = Math.min( dp[1-i][j+t[ii]], dp[i][j]+c[ii] );
				dp[i][j] = INF;
			}
		}
		long ans = INF;
		for( int j = T; j <= TT; j++ ) ans = Math.min( ans, dp[n%2][j] );
		System.out.println( ans );
	}
}
