/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class RPS
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new RPS().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		String p1 = in.next(), p2 = in.next();
		if( p1.charAt(0) == 'E' ) return false;

		int p1c = 0, p2c = 0;
		for( int i = 0; i < p1.length(); i++ )
		{
			char m1 = p1.charAt(i), m2 = p2.charAt(i);
			if( m1 != m2 )
			{
				if(
					( m1=='R' && m2=='S' ) ||
					( m1=='S' && m2=='P' ) ||
					( m1=='P' && m2=='R' )
				) p1c++;
				else p2c++;
			}
		}
		System.out.println( "P1: " + p1c );
		System.out.println( "P2: " + p2c );
		return true;
	}
}
