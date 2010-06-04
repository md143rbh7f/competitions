import java.io.*;
import java.math.*;
import java.util.*;

public class PureRank
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int max = 500, mod = 100003;

	public static void main( String[] args )
	{
		int c = in.nextInt(), choose[][] = new int[max+1][max+1], dp[][] = new int[max+1][max+1], ans[] = new int[max+1];
		choose[0][0] = 1;
		for( int i = 1; i <= max; i++ )
		{
			choose[i][0] = 1;
			for( int j = 1; j <= i; j++ ) choose[i][j] = (choose[i-1][j-1]+choose[i-1][j])%mod;
		}
		for( int i = 2; i <= max; i++ )
		{
			dp[i][1] = 1;
			ans[i] = 1;
			for( int j = 2; j < i; j++ )
			{
				for( int k = 1; k < j; k++ ) dp[i][j] += (((long)choose[i-j-1][j-k-1])*dp[j][k])%mod;
				ans[i] = (ans[i]+dp[i][j])%mod;
			}
		}
		for( int i = 1; i <= c; i++ ) System.out.printf( "Case #%d: %d\n", i, ans[in.nextInt()] );
	}
}
