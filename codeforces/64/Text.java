import java.util.*;

public class Text
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		int n = in.nextInt(), inf = 1000000;
		in.nextLine();
		String l = in.nextLine();
		int N = l.length(), dp[] = new int[N];
		for( int i = 0; i < N; i++ ) if( l.charAt(i)=='.' || l.charAt(i)=='?' || l.charAt(i)=='!' )
		{
			int j = i;
			dp[i] = inf;
			while( true )
			{
				j--;
				if( j < 0 )
				{
					if( i < n ) dp[i] = 1;
					break;
				}
				if( i - j > n + 1 ) break;
				if( l.charAt(j)=='.' || l.charAt(j)=='?' || l.charAt(j)=='!' ) dp[i] = Math.min( dp[i], dp[j]+1 );
			}
			if( dp[i]==inf )
			{
				System.out.println( "Impossible" );
				return;
			}
		}
		System.out.println( dp[N-1] );
	}
}
