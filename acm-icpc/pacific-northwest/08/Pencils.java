/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Pencils
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Pencils().solve( caseNum++ ) );
	}

	int costs[] = { 16, 2, 1 };
	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == 0 ) return false;
		System.out.printf( "Case %d:\n%d pencils for %d cents\n", caseNum, n, n );
		
		boolean solutionFound = false;
		int tot = 4*n;
		for( int i = 1; costs[0]*i < tot; i++ )
		{
			int x = tot-costs[0]*i;
			for( int j = 1; costs[1]*j < x; j++ )
			{
				int k = x-costs[1]*j;
				if( i + j + k == n )
				{
					solutionFound = true;
					System.out.printf( "%d at four cents each\n%d at two for a penny\n%d at four for a penny\n\n", i, j, k );
				}
			}
		}

		if( !solutionFound ) System.out.printf( "No solution found.\n\n" );
		return true;
	}
}
