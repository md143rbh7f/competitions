/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Sort
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Sort().solve( i );
	}

	void solve( int caseNum )
	{
		char[][] a = { in.next().toCharArray(), in.next().toCharArray() };
		for( int i = 0; i < a.length; i++ )
			for( int j = 0; j < a[i].length; j++ )
				if( a[i][j] <= 'z' && a[i][j] >= 'a' )
					a[i][j] += 'A' -'a';

		BigInteger[] score = new BigInteger[2];
		for( int i = 0; i < a.length; i++ )
		{
			int j = 0;
			score[i] = BigInteger.ZERO;
			while( j < a[i].length )
			{
				if(
					( !isDig( a[i][j] ) ) &&
						(
							( a[i][j] != '+' && a[i][j] != '-' ) ||
							(
								( j > 0 && isDig( a[i][j-1] ) ) ||
								( j == a[i].length-1 ) ||
								( !isDig( a[i][j+1] ) )
							)
						)
				)
				{
					score[i] = score[i].add( new BigInteger( "" + (int)a[i][j] ) );
					j++;
				}
				else
				{
					BigInteger curval = BigInteger.ZERO;
					String coeff = a[i][j] == '-' ? "-" : "";
					if( a[i][j] == '-' || a[i][j] == '+' ) j++;
					while( j < a[i].length && isDig( a[i][j] ) )
					{
						curval = curval.multiply( BigInteger.TEN );
						curval = curval.add( new BigInteger( coeff + a[i][j] ) );
						j++;
					}
					score[i] = score[i].add( curval );
				}
			}
		}

		System.out.println( caseNum + " " + score[0].compareTo( score[1] ) );
	}

	boolean isDig( char a )
	{
		return a >= '0' && a <= '9';
	}
}
