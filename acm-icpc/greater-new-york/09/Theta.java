/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Theta
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		generate();
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Theta().solve( i );
	}

	void solve( int caseNum )
	{
		System.out.print( in.nextInt() + " " );
		String start = "*"+in.next();
		if( !statespace.containsKey( start ) ) System.out.println( "NO SOLUTION" );
		else
		{
			Pair ptr = statespace.get( start );
			String path = "";
			while( ptr.move != ' ' )
			{
				path += ptr.move;
				ptr = statespace.get( ptr.prev );
			}
			System.out.println( path.length() + " " + path );
		}
	}

	static HashMap<String,Pair> statespace;
	static int[][] swappos = { {2,5}, {2,6}, {0,1,3}, {2,4}, {3,5}, {0,4,6}, {1,5} };
	static void generate()
	{
		statespace = new HashMap<String,Pair>();
		String start = "*ABCDEF";
		statespace.put( start, new Pair( ' ', "" ) );
		LinkedList<String> q = new LinkedList<String>();
		q.add( start );
		while( !q.isEmpty() )
		{
			String s = q.poll();
			int blank = s.indexOf( "*" );
			for( int i : swappos[blank] )
			{
				char[] copy = s.toCharArray();
				copy[blank] = copy[i];
				copy[i] = '*';
				String next = new String( copy );
				if( !statespace.containsKey( next ) )
				{
					statespace.put( next, new Pair( copy[blank], s ) );
					q.add( next );
				}
			}
		}
	}

	static class Pair
	{
		char move; String prev;
		public Pair( char _move, String _prev )
		{
			move = _move;
			prev = _prev;
		}
	}
}
