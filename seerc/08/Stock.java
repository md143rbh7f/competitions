/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Stock2
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX = 1 << 17;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Stock2().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == 0 ) return false;
		
		long[] pl = new long[n];
		for( int i = 0; i < n; i++ ) pl[i] = in.nextLong();

		// least[i] = smallest p[j], such that p[j] ends a sequence with i elements
		int[] p = compress( pl ), least = new int[n+1];
		for( int i = 0; i <= n; i++ ) least[i] = INF;
		for( int i = 0; i < n; i++ )
		{
			int step = MAX, search = 0;
			while( ( step >>= 1 ) != 0 )
			{
				if( search+step <= n && least[search+step] < p[i] )
				search += step;
			}
			least[search+1] = p[i];
		}

		int maxl = 1;
		while( maxl <= n && least[maxl] != INF ) maxl++;
		System.out.println( maxl-1 );

		return true;
	}

	int[] compress( long[] pl )
	{
		long[] copy = new long[pl.length];
		for( int i = 0; i < pl.length; i++ ) copy[i] = pl[i];
		Arrays.sort( copy );
		TreeMap<Long,Integer> lookup = new TreeMap<Long,Integer>();
		for( int i = 0; i < pl.length; i++ ) if( !lookup.containsKey( copy[i] ) ) lookup.put( copy[i], i );
		int[] p = new int[pl.length];
		for( int i = 0; i < p.length; i++ ) p[i] = lookup.get( pl[i] );
		return p;
	}

}
