/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class IndexGen
{
	static BufferedReader in = new BufferedReader( new InputStreamReader( System.in ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args ) throws IOException
	{
		int next;
		int page = 1, doc = 1;
		boolean enddoc = false;
		TreeMap<String,TreeMap<String,TreeSet<Integer>>> index = new TreeMap<String,TreeMap<String,TreeSet<Integer>>>( String.CASE_INSENSITIVE_ORDER );
		char[][] buf = { new char[80], new char[80] };
		int[] len = new int[2];
		String[] entries = new String[2];
		while( in.ready() )
		{
			next = in.read();

			if( enddoc && next != '*'  )
			{
				System.out.println( "DOCUMENT "+doc++ );
				for( String prim : index.keySet() )
				{
					System.out.print( prim );
					TreeMap<String,TreeSet<Integer>> entry = index.get( prim );
					if( !entry.containsKey( "$" ) ) System.out.println();
					for( String sec : entry.keySet() )
					{
						if( !sec.equals( "$" ) )
							System.out.printf( "+ %s", sec );
						for( int pg : entry.get( sec ) )
							System.out.printf( ", %d", pg );
						System.out.println();
					}
				}
				page = 1;
				enddoc = false;
				index.clear();
			}

			switch( next )
			{
				case '{':
					int i = 0;
					SEARCH: while( true )
						switch( next = in.read() )
						{
							case '$': i++; len[i] = 0; break;
							case '%': len[i] = 0; break;
							case '}': break SEARCH;
							case '\n': buf[i][len[i]++] = ' '; break;
							case '\r': buf[i][len[i]++] = ' '; break; // stupid carriage returns
							default: buf[i][len[i]++] = (char)next; break;
						}
					for( i = 0; i < 2; i++ )
						if( len[i] != 0 )
						{
							int start = -1, ct = len[i];
							while( buf[i][++start] == ' ' );
							while( buf[i][--ct] == ' ' );
							entries[i] = new String( buf[i], start, ct-start+1 );
							len[i] = 0;
						}
						else entries[i] = "$";
					if( !index.containsKey( entries[0] ) )
						index.put( entries[0], new TreeMap<String,TreeSet<Integer>>() );
					TreeMap<String,TreeSet<Integer>> entry = index.get( entries[0] );
					if( !entry.containsKey( entries[1] ) )
						entry.put( entries[1], new TreeSet<Integer>() );
					TreeSet<Integer> pgs = entry.get( entries[1] );
					pgs.add( page );
					for( i = 0; i < 2; i++ ) entries[i] = null;
					break;
				case '&': page++; break;
				case '*':
					if( enddoc ) return;
					enddoc = true;
				break;
			}
		}
	}
}
