/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Cantor
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Cantor().solve( caseNum++ ) );
	}

	static BigDecimal one = new BigDecimal( "1" );
	static BigDecimal two = new BigDecimal( "2" );
	static BigDecimal three = new BigDecimal( "3" );
	static int cycles = 42;
	boolean solve( int caseNum )
	{
		if( !in.hasNextDouble() ) return false;

		BigDecimal n = new BigDecimal( in.next() );
		for( int i = 0; i < cycles; i++ )
		{
			n = n.multiply(three);
			if( n.compareTo(two) >= 0 ) n = n.subtract(two);
			else if( n.compareTo(one) > 0 )
			{
				System.out.println( "NON-MEMBER" );
				return true;
			}
		}

		System.out.println( "MEMBER" );

		return true;
	}
}
