import java.io.*;
import java.math.*;
import java.util.*;

public class NumberGame
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new NumberGame().solve( i );
	}
	
	static double phi = (Math.sqrt(5)+1)/2;

	void solve( int caseNum )
	{
		int a1 = in.nextInt(), a2 = in.nextInt(), b1 = in.nextInt(), b2 = in.nextInt();
		long ans = 0;
		for( int b = b1; b <= b2; b++ )
		{
			int phoebe = (int)Math.ceil(phi*b), helen = (int)Math.floor((phi-1)*b);
			if( a2 >= phoebe ) ans += a2-phoebe+1;
			if( a1 >= phoebe ) ans -= a1-phoebe;
			if( a1 <= helen ) ans += helen-a1+1;
			if( a2 <= helen ) ans -= helen-a2;
		}
		System.out.printf( "Case #%d: %d\n", caseNum, ans );
	}
}
