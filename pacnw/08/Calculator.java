/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Calculator
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		generate();
		while( new Calculator().solve( caseNum++ ) );
	}

	static int[] cost = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	static HashSet<Integer>[] cn = (HashSet<Integer>[])(new HashSet[23]);
	static
	{
		for( int i = 0; i < cn.length; i++ ) cn[i] = new HashSet<Integer>();
	}

	boolean solve( int caseNum )
	{
		int x = in.nextInt()/5; if( x==0 ) return false;
		int y = in.nextInt()/5, z = in.nextInt()/5;

		int s = 0;
		for( int a : cn[x] )
		for( int b : cn[y] )
		{
			if( cn[z].contains(a+b) ) s++;
			if( cn[z].contains(a-b) ) s++;
			if( cn[z].contains(a*b) ) s++;
			if( b != 0 && cn[z].contains(a/b) ) s++;
		}

		System.out.printf( "%d solutions for %d %d %d\n", s, x*5, y*5, z*5 );

		return true;
	}

	static void generate()
	{
		int count = 0;
		for( int i = 0; i < 10; i++ )
		for( int j = 0; j < 10; j++ )
		for( int k = 0; k < 10; k++ )
		{
			int c = cost[k];
			if( count > 9 ) c += cost[j];
			if( count > 99 ) c += cost[i];
			cn[c].add( count );
			cn[c+1].add( -count );
			count++;
		}
		cn[1].remove( 0 );
	}

}
