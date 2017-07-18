/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Clock
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Clock().solve( i );
	}

	void solve( int caseNum )
	{
		String[] split = in.next().split( ":" );
		for( int i = 0; i < 3; i++ )
		{
			split[i] = Integer.toBinaryString( Integer.parseInt( split[i] ) );
			while( split[i].length() < 6 ) split[i] = "0" + split[i];
		}
		
		String vert = "";
		for( int i = 0; i < 3; i++ ) for( int j = 0; j < 6; j++ ) vert += split[i].charAt( j );
		String horiz = "";
		for( int i = 0; i < 6; i++ ) for( int j = 0; j < 3; j++ ) horiz += split[j].charAt( i );

		System.out.printf( "%d %s %s\n", caseNum, horiz, vert );
	}
}
