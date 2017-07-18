import java.util.*;

public class Balls
{
	public static void main( String[] args )
	{
		int B = 51, F = 1001, dp[][] = new int[B][F];
		for( int f = 1; f < F; f++ ) dp[1][f] = f;
		for( int b = 2; b < B; b++ ) for( int f = 1; f < F; f++ )
		{
			int del = 1 << 10, best = 0;
			while( del != 0 )
			{
				int n = best + del;
				if( n < f && dp[b-1][n-1] < dp[b][f-n] ) best += del;
				del >>= 1;
			}
			dp[b][f] = 1 + Math.min( dp[b-1][best], dp[b][f-best] );
		}

		Scanner in = new Scanner( System.in );
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) System.out.println( in.nextInt() + " " + dp[in.nextInt()][in.nextInt()] );
	}
}
