/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Internet
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Internet().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt(), c = in.nextInt();
		if( n == -1 ) return false;
		
		if( n == 0 ) System.out.println( 0 );
		else
		{
			int t1 = c/(2*n);
			int t2 = (int)Math.round(c/(2.0*n));
			int f1 = f( t1, n, c );
			int f2 = f( t2, n, c );
			System.out.println( f1 < f2 ? t2 : t1 );
		}

		return true;
	}

	int f( int t, int n, int c )
	{
		return t*(c-t*n);
	}
}
