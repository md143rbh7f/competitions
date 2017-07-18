/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Nth
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Nth().solve( i );
	}

	static int[] val = new int[10];
	void solve( int caseNum )
	{
		System.out.print( in.nextInt() + " " );
		for( int i = 0; i < 10; i++ ) val[i] = in.nextInt();
		Arrays.sort( val );
		System.out.println( val[7] );
	}
}
