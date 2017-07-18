/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Graduate
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Graduate().solve( caseNum++ ) );
	}

	int ctot, cps, prereqs[];
	boolean[] fall, spring; 
	boolean solve( int caseNum )
	{
		ctot = in.nextInt(); cps = in.nextInt();
		if( ctot == -1 ) return false;

		HashMap<String,Integer> courses = new HashMap<String,Integer>(ctot);
		for( int i = 0; i < ctot; i++ ) courses.put( in.next(), i );
		int c, p, graph[][] = new int[ctot][];
		prereqs = new int[ctot]; fall = new boolean[ctot]; spring = new boolean[ctot];
		for( int i = 0; i < ctot; i++ )
		{
			c = courses.get( in.next() );
			switch( in.next().charAt(0) )
			{
				case 'F': fall[c] = true; break;
				case 'S': spring[c] = true; break;
				case 'B': fall[c] = true; spring[c] = true; break;
			}
			graph[c] = new int[in.nextInt()];
			for( int j = 0; j < graph[c].length; j++ )
			{
				graph[c][j] = courses.get( in.next() );
				prereqs[c] |= 1 << graph[c][j];
			}
		}

		// search through all possible combinations of courses that you can take one semester
		System.out.println( "The minimum number of semesters required to graduate is " + minSemesters( 0, true ) + "." );

		return true;
	}

	int minSemesters( int taken, boolean isFall )
	{
		if( taken == ( 1 << ctot ) - 1 ) return 0;
		int canTake[] = new int[ctot], numCanTake = 0;
		for( int i = 0; i < ctot; i++ )
			if( ( ( taken >> i ) & 1 ) == 0 && ( prereqs[i] & taken ) == prereqs[i] && ( ( isFall && fall[i] ) || ( !isFall && spring[i] ) ) )
				canTake[numCanTake++] = i;
		int[] perm = new int[numCanTake];
		for( int i = 1; i <= numCanTake && i <= cps; i++ ) perm[numCanTake-i] = 1;
		int toTake, min = INF;
		do
		{
			toTake = 0;
			for( int i = 0; i < perm.length; i++ ) if( perm[i] == 1 ) toTake |= 1 << canTake[i];
			min = Math.min( minSemesters( taken | toTake, !isFall ), min );
		}
		while( next_permutation( perm ) );

		return min + 1;
	}

	boolean next_permutation( int[] perm )
	{
		int n = perm.length;
		int inc = -1;
		for( int i = 0; i < n-1; i++ ) if( perm[i] < perm[i+1] ) inc = i;
		if( inc != -1 )
		{
			int inc_val = perm[inc];
			perm[inc] = Integer.MAX_VALUE;
			int min_ptr = inc;
			for( int i = inc + 1; i < n; i++ ) if( perm[i] < perm[min_ptr] && perm[i] > inc_val ) min_ptr = i;
			if( min_ptr == -1 ) min_ptr = inc;
			perm[inc] = perm[min_ptr];
			perm[min_ptr] = inc_val;
		}
		Arrays.sort( perm, inc + 1, n );
		return inc == -1 ? false : true;
	}

}
