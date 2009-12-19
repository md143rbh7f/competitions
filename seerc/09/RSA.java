/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class RSA
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new RSA().solve( caseNum++ ) );
	}

	final static BigInteger RANGE = new BigInteger( "100000" );
	final static BigInteger TWO = new BigInteger( "2" );
	boolean solve( int caseNum )
	{
		if( !in.hasNext() ) return false;
		BigInteger n = new BigInteger( in.next() ), k = new BigInteger( in.next() );

		BigInteger root = sqrt( n.divide( k ) );
		BigInteger min = root.subtract( RANGE );
		if( min.compareTo( TWO ) < 0 ) min = TWO;
		BigInteger max = root.add( RANGE );
		if( max.compareTo( n ) >= 0 ) max = n.subtract( BigInteger.ONE );

		BigInteger i = min.add( BigInteger.ZERO );
		while( i.compareTo( max ) <= 0 )
		{
			if( !n.gcd( i ).equals( BigInteger.ONE ) )
			{
				System.out.print( i + " * " + n.divide( i ) + "\n" );
				return true;
			}
			i = i.add( BigInteger.ONE );
		}

		return true;
	}

	// implements Heron's method
	static BigInteger sqrt( BigInteger n )
	{
		int d = n.bitLength();
		BigInteger x = BigInteger.ONE.shiftLeft( d >> 1 );
		BigInteger y = n.divide( x );
		BigInteger diff = x.subtract( y ).abs();
		while( !( diff.equals( BigInteger.ZERO ) || diff.equals( BigInteger.ONE ) ) )
		{
			x = x.add( y ).shiftRight( 1 );
			y = n.divide( x );
			diff = x.subtract( y ).abs();
		}
		return x;
	}
}
