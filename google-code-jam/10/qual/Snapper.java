import java.io.*;
import java.math.*;
import java.util.*;

public class Snapper
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Snapper().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt(), N = 1<<n, k = in.nextInt();
		System.out.printf( "Case #%d: ", caseNum );
		if( k%N == N-1 ) System.out.println( "ON" );
		else System.out.println( "OFF" );
	}
}
