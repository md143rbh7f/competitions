import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;

public class Smooth
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Smooth().solve( i );
	}

	static int inf = 100000, max = 256;
	void solve( int caseNum )
	{
		int D = in.nextInt(), I = in.nextInt(), M = in.nextInt(), N = in.nextInt(), p[] = new int[N+1], c[][] = new int[N+1][max+1], ans = inf;
		for( int i = 0; i < N; i++ ) p[i+1] = in.nextInt()+1;
		for( int i = 0; i <= N; i++ ) c[i][0] = D*i;
		for( int j = 1; j <= max; j++ ) c[0][j] = inf;
		for( int i = 1; i <= N; i++ )
		{
			for( int j = 1; j <= max; j++ )
			{
				c[i][j] = min( inf, c[i-1][j]+D );
				for( int k = 0; k <= max; k++ )
					if( k==0 || abs(k-j)<=M )
						c[i][j] = min( c[i][j], c[i-1][k]+abs(p[i]-j) );
			}
			if( M!=0 )
				for( int j = 1; j <= max; j++ )
					for( int k = 1; k <= max; k++ )
						c[i][j] = min( c[i][j], c[i][k]+I*((abs(j-k)+M-1)/M) );
		}
		for( int j = 0; j <= max; j++ ) ans = min( ans, c[N][j] );
		System.out.printf( "Case #%d: %d\n", caseNum, ans );
	}
}
