/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Bookshelf
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Bookshelf().solve( caseNum++ ) );
	}


	boolean solve( int caseNum )
	{
		int w = in.nextInt();
		if( w == -1 ) return false;

		String cmd;
		int[] shelf = new int[101], pos = new int[101], width = new int[101];
		int totw = 0, first = 1, last = 1, id;
		while( ( cmd = in.next() ).charAt(0) != 'E' )
		{
			id = in.nextInt();
			switch( cmd.charAt(0) )
			{
				case 'R':
					totw -= width[id];
					shelf[pos[id]] = width[id] = 0;
					break;
				case 'A':
					shelf[ ( pos[id] = last++ ) ] = id;
					totw += ( width[id] = in.nextInt() );
					while( totw > w )
					{
						totw -= width[shelf[first]];
						width[shelf[first++]] = 0;
					}
					break;
			}
		}

		System.out.printf( "PROBLEM %d:", caseNum );
		for( int i = last-1; i >= first; i-- )
			if( shelf[i] != 0 )
				System.out.printf( " %d", shelf[i] );
		System.out.println();

		return true;
	}

}
