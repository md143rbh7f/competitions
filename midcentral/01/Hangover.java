/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Hangover
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		generate();
		int caseNum = 1;
		while( new Hangover().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		double c = in.nextDouble();
		if( c == 0 ) return false;
		int d = MAX, ans = MAX-1;
		while( (d>>=1) != 0 ) if( h[ans-d] > c ) ans -= d;
		System.out.printf( "%d card(s)\n", ans );
		return true;
	}

	static final int MAX = 1<<9;
	static double[] h;
	static void generate()
	{
		h = new double[MAX];
		for( int i = 1; i < h.length; i++ )
			h[i] = h[i-1] + 1.0/(i+1);
	}
}
