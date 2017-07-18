/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class SqrtLogSin
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new SqrtLogSin().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == -1 ) return false;

		System.out.println( x[n] );

		return true;
	}

	static int max = 1000000;
	static int[] x = new int[max+1];
	static
	{
		x[0] = 1;
		for( int i = 1; i <= max; i++ )
		{
			double sin = Math.sin(i);
			x[i] = ( x[(int)Math.floor(i-Math.sqrt(i))] + x[(int)Math.floor(Math.log(i))] + x[(int)Math.floor(i*sin*sin)] ) % max;
		}
	}
}
