/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class SkyCode
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX = 10001;

	static LinkedList<Integer>[] f;
	static int[] s;

	public static void main( String[] args )
	{
		int caseNum = 1;
		generate();
		while( new SkyCode().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == 0 ) return false;

		long maxcomb = combos( n );

		int[] count = new int[MAX];
		for( int i = 0; i < n; i++ )
			for( int k : f[in.nextInt()] )
				count[k]++;
		long ans = 0;
		for( int i = 0; i < MAX; i++ )
			if( s[i] != -1 )
				ans += ( s[i] == 0 ? -1 : 1 ) * combos( count[i] );
		
		System.out.println( maxcomb - ans );

		return true;
	}

	static long combos( long i )
	{
		if( i < 4 ) return 0;
		return i*(i-1)*(i-2)*(i-3)/24;
	}

	static void generate()
	{
		// result: s[i] = { 0 if i unseen, >=1 if i product of distinct primes, -1 otherwise }
		s = new int[MAX]; int sqr;
		for( int i = 2; i < MAX; i++ ) if( s[i] == 0 )
		{
			s[i] = 1;
			sqr = i*i;
			for( int j = sqr; j < MAX; j += sqr ) s[j] = -1;
			for( int j = (MAX-1)/i; j > 1; j-- ) if( j != i )
			{
				if( s[j] > 0 ) s[j*i] = s[j]+1;
				else if( s[j] < 0 ) s[j*i] = -1;
			}
		}
		// at this point, everything is either -1, 0, or 1
		for( int i = 0; i < MAX; i++ ) if( s[i] > -1 ) s[i] %= 2;

		// f[i] := list of all factors of i that are contain only distinct primes
		f = (LinkedList<Integer>[])(new LinkedList[MAX]);
		for( int i = 1; i < MAX; i++ ) f[i] = new LinkedList<Integer>();
		for( int i = 2; i < MAX; i++ ) if( s[i] > -1 ) for( int j = i; j < MAX; j += i ) f[j].add( i );
	}
}
