/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Dup
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Dup().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int c = in.nextInt(); if( c == 0 ) return false;
		int last = 0;
		for( int i = 0; i < c; i++ )
		{
			int next = in.nextInt();
			if( next != last )
			{
				last = next;
				System.out.print( last + " " );
			}
		}
		System.out.println( "$" );
		return true;
	}
}
