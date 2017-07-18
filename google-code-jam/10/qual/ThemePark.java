import java.io.*;
import java.math.*;
import java.util.*;

public class ThemePark
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new ThemePark().solve( i );
	}

	void solve( int caseNum )
	{
		int r = in.nextInt(), max = in.nextInt(), n = in.nextInt(), g[] = new int[n], size[] = new int[n], next[] = new int[n];
		for( int i = 0; i < n; i++ ) g[i] = in.nextInt();
		for( int i = 0; i < n; i++ )
		{
			size[i] = i==0 ? 0 : size[i-1]-g[i-1];
			int temp = i==0 ? 0 : next[i-1];
			do
			{
				if( size[i]+g[temp%n] <= max ) size[i] += g[temp%n];
				else break;
				temp++;
			}
			while( (temp%n)!=i );
			next[i] = temp%n;
		}
		long ans = 0;
		int cur = 0;
		for( int i = 0; i < r; i++ )
		{
			ans += size[cur];
			cur = next[cur];
		}
		System.out.printf( "Case #%d: %d\n", caseNum, ans );
	}
}
