/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Digits
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Digits().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt(), d = in.nextInt(), b = in.nextInt(), e = in.nextInt();
		int n2 = n % d;

		int[] digs = new int[e+1];
		for( int i = 0; i <= e; i++ )
		{
			n2 *= 7;
			digs[i] = n2 / d;
			n2 -= digs[i] * d;
		}
		char[] digsArray = new char[e+1-b];
		for( int i = 0; i <= e-b; i++ ) digsArray[i] = (char)( '0' + digs[i+b] );
		String digsString = new String( digsArray );

		System.out.println( "Problem set " + caseNum + ": " + n + " / " + d + ", base 7 digits " + b + " through " + e + ": " + digsString );
	}
}
