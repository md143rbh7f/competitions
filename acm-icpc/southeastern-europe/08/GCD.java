/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class GCD
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new GCD().solve( caseNum++ ) );
	}

	final static long BASE = 1000000007l;
	boolean solve( int caseNum )
	{
		int N = in.nextInt(); if( N == 0 ) return false;

		long s[] = new long[N], p, d = 1;
		for( int i = 0; i < N; i++ ) s[i] = in.nextLong();
		Arrays.sort( s );
		for( int i = 0; i < N; i++ ) if( ( p = s[i] ) != 1 )
			for( int j = i; j < N; j++ ) if( s[j] % p == 0 )
			{
				s[j] /= p;
				d *= p-1; if( d > BASE ) d %= BASE;
				while( s[j] % p == 0 )
				{
					s[j] /= p;
					d *= p; if( d > BASE ) d %= BASE;
				}
			}
		System.out.println( d );

		return true;
	}
}
