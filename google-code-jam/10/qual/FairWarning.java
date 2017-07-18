import java.io.*;
import java.math.*;
import java.util.*;

public class FairWarning
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new FairWarning().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt();
		BigInteger[] past = new BigInteger[n], d = new BigInteger[n];
		for( int i = 0; i < n; i++ ) past[i] = new BigInteger( in.next() );
		Arrays.sort( past );
		for( int i = 0; i < n; i++ ) d[i] = past[i].subtract(past[0]);
		for( int i = 2; i < n; i++ ) d[i] = d[i].gcd(d[i-1]);
		BigInteger gcd = d[n-1], mod = past[0].mod(gcd);
		System.out.printf( "Case #%d: ", caseNum );
		if( mod.equals(BigInteger.ZERO) ) System.out.println(0);
		else System.out.println(gcd.subtract(mod));
	}
}
