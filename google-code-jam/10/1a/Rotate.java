import java.io.*;
import java.math.*;
import java.util.*;

public class Rotate
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Rotate().solve( i );
	}

	static int[] dx = { 0, 0, 1, 1, 1, -1, -1, -1 }, dy = { 1, -1, 1, 0, -1, 1, 0, -1 };
	void solve( int caseNum )
	{
		int n = in.nextInt(), k = in.nextInt();
		char[][] b = new char[n][n];
		for( int i = 0; i < n; i++ ) b[i] = in.next().toCharArray();
		for( int i = 0; i < n; i++ )
		{
			char[] q = new char[n];
			int l = 0;
			for( int j = n-1; j >= 0; j-- ) if( b[i][j]!='.' ) q[l++] = b[i][j];
			b[i] = q;
		}
		boolean R = false, B = false;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		if( b[i][j]=='B' || b[i][j]=='R' )
		for( int d = 0; d < 8; d++ )
		{
			int tx = i, ty = j, del = 0;
			while( del<k && tx>=0 && tx<n && ty>=0 && ty<n && b[tx][ty]==b[i][j] )
			{
				tx += dx[d];
				ty += dy[d];
				del++;
			}
			if( del==k )
			{
				if( b[i][j]=='B' ) B = true;
				else R = true;
			}
		}
		System.out.printf( "Case #%d: ", caseNum );
		if( R&&B ) System.out.println( "Both" );
		if( R&&!B ) System.out.println( "Red" );
		if( !R&&B ) System.out.println( "Blue" );
		if( !R&&!B ) System.out.println( "Neither" );
	}
}
