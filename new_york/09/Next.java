/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Next
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Next().solve( i );
	}

	void solve( int caseNum )
	{
		System.out.print( in.nextInt() + " " );
		String s = in.next();
		int n = s.length();
		int[] perm = new int[n];
		for( int i = 0; i < n; i++ ) perm[i] = s.charAt(i);
		if( next_permutation( perm ) ) for( int i = 0; i < n; i++ ) System.out.print( (char)perm[i] );
		else System.out.print( "BIGGEST" );
		System.out.println();
	}

	static boolean next_permutation( int[] perm )
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
