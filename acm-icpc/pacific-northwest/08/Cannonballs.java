/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Cannonballs
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Cannonballs().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt();
		int sum = 0;
		for( int i = 1; i <= n; i++ )
			sum += (i*(i+1))/2;
		System.out.printf( "%d: %d %d\n", caseNum, n, sum );
	}
}
