/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Robots
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Robots().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt();
		String[] roll = new String[n];
		for( int i = 0; i < n; i++ ) roll[i] = in.next();

		int lines = in.nextInt();
		in.nextLine();
		HashSet<String> dataSet = new HashSet<String>();
		for( int i = 0; i < lines; i++ )
		{
			String[] stream = in.nextLine().split( " " );
			for( String data : stream ) dataSet.add( data );
		}

		System.out.printf( "Test set %d:\n", caseNum );
		for( int i = 0; i < n; i++ )
		{
			if( dataSet.contains( roll[i] ) ) System.out.printf( "%s is present\n", roll[i] );
			else System.out.printf( "%s is absent\n", roll[i] );
		}
		System.out.println();
	}
}
