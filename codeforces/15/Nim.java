import java.io.*;
import java.math.*;
import java.util.*;

public class Nim
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int n = in.nextInt();
		long b[][] = new long[n][2], c = 0;
		for( int i = 0; i < n; i++ )
		{
			b[i][0] = in.nextLong()-1;
			b[i][1] = b[i][0]+in.nextLong();
		}
		for( int i = 0; i < n; i++ ) for( int j = 0; j < 2; j++ ) c ^= nimCount( b[i][j] );
		System.out.println( c!=0 ? "tolik" : "bolik" );
	}

	static int max = 60;
	static long nimCount( long k )
	{
		long t = 0, b = 1l<<max, bb = 1l<<(max+1);
		if( k%2==0 ) for( int i = max; i > 0; i-- )
		{
			k %= bb;
			if( k>=b ) t |= b;
			bb >>= 1; b >>= 1;
		}
		if( k%4==1 || k%4==2 ) t |= 1;
		return t;
	}
}
