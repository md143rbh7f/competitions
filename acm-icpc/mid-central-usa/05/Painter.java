/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Painter
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Painter().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int c = in.nextInt();
		if( c == 0 ) return false;
		int[] bottles = new int[c];
		for( int i = 0; i < c; i++ ) bottles[i] = in.nextInt();
		int g = in.nextInt();

		for( int i = 0; i < g; i++ )
		{
			Arrays.sort( bottles );
			bottles[0]++;
			bottles[1]++;
			bottles[2]++;
		}

		Arrays.sort( bottles );
		int k = bottles[c-1];
		k = (int) Math.ceil( k / 50.0 );

		System.out.println( k );

		return true;
	}
}
