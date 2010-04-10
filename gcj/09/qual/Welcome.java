import java.io.*;
import java.math.*;
import java.util.*;

public class Welcome
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		in.nextLine();
		for( int i = 1; i <= c; i++ ) new Welcome().solve( i );
	}

	static char[] s = "welcome to code jam".toCharArray();
	static int n = s.length, mod = 10000;

	void solve( int caseNum )
	{
		char[] d = in.nextLine().toCharArray();
		int m = d.length, dp[][] = new int[m][n];
		for( int i = 0; i < m; i++ ) for( int j = 0; j < n; j++ )
		if( d[i]==s[j] )
		{
			if( j==0 ) dp[i][j] = 1;
			else for( int k = 0; k < i; k++ ) if( d[k]==s[j-1] ) dp[i][j] = (dp[i][j]+dp[k][j-1])%mod;
		}
		int ans = 0;
		for( int i = 0; i < m; i++ ) ans = (ans+dp[i][n-1])%mod;
		System.out.printf( "Case #%d: %04d\n", caseNum, ans );
	}
}
