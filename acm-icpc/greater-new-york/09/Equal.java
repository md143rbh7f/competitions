/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Equal
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Equal().solve( i );
	}

	void solve( int caseNum )
	{
		System.out.print( in.nextInt() + " " );
		int n = in.nextInt();
		int[] vals = new int[n];
		for( int i = 0; i < n; i++ ) vals[i] = in.nextInt();
		SEARCH: for( int i = 0; i <= n; i++ )
		{
			int start = 0;
			for( int j = 0; j < i; j++ ) start += vals[j];
			int cur = 0;
			for( int j = i; j < n; j++ )
			{
				cur += vals[j];
				if( cur == start ) cur = 0;
			}
			if( cur == 0 )
			{
				System.out.println( start );
				break SEARCH;
			}
		}
	}
}
