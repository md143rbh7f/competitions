import java.io.*;
import java.math.*;
import java.util.*;

public class Investment
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Investment().solve( i );
	}

	void solve( int caseNum )
	{
		int cash = in.nextInt(), T = in.nextInt(), n = in.nextInt(), c[] = new int[n], g[] = new int[n], max = 46*cash/1000;
		for( int i = 0; i < n; i++ )
		{
			c[i] = in.nextInt()/1000;
			g[i] = in.nextInt();
		}
		if( max==0 )
		{
			System.out.println(cash);
			return;
		}
		int dp[] = new int[max];
		for( int i = 1; i < max; i++ ) dp[i] = -1;
		for( int b = 0; b < n; b++ )
			for( int i = c[b]; i < max; i++ )
				if( dp[i-c[b]]>-1 && dp[i-c[b]]+g[b]>dp[i] )
					dp[i] = dp[i-c[b]]+g[b];
		for( int t = 0; t < T; t++ )
		{
			int best = 0;
			for( int i = cash/1000; i >= 0; i-- )
				if( dp[i]>best )
					best = dp[i];
			cash += best;
		}
		System.out.println( cash );
	}
}
