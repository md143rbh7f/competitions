/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Journey2
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Journey2().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		if( in.hasNextInt() ) return false;

		int t1 = toNumber( in.next() ), t2 = toNumber( in.next() ), t3 = toNumber( in.next() ), t4 = toNumber( in.next() ), t5 = toNumber( in.next() );
		// solve for: va, a0, vc, c0, vm, m0, vd, d0
		// assume: va = a0 = 0, vc = 1
		double[] b = { 0, 0, 1, 0, 0, 0, 0, 0 };
		double[][] a = 
		{
			{ 1, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 0, t1, 1, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, t2, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, t3, 1 },
			{ 0, 0, -t4, -1, 0, 0, t4, 1 },
			{ 0, 0, 0, 0, -t5, -1, t5, 1 }
		};
		double[] x = gaussian_elim( a, b ); 
		double time = Math.round( ( x[3] - x[5] ) / ( x[4] - x[2] ) );
		System.out.println( toString( (int)time ) );
		return true;
	}
	
	static int toNumber( String time )
	{
		String[] split = time.split( ":" );
		return Integer.parseInt( split[0] ) * 3600 + Integer.parseInt( split[1] ) * 60 + Integer.parseInt( split[2] );
	}
	
	static String toString( int time )
	{
		int seconds = time % 60;
		time /= 60;
		int minutes = time % 60;
		time /= 60;
		int hours = time;
		return ( hours < 10 ? "0" : "" ) + hours + ":" + ( minutes < 10 ? "0" : "" ) + minutes + ":" + ( seconds < 10 ? "0" : "" ) + seconds;
	}

	static double[] gaussian_elim( double[][] A, double[] b )
	{
		int n = A.length;
		double[][] a = new double[n][n+1];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) a[i][j] = A[i][j];
		for( int i = 0; i < n; i++ ) a[i][n] = b[i];
		for( int i = 0; i < n; i++ )
		{
			for( int j = i+1; j < n && a[i][i] == 0; j++ ) if( a[j][i] != 0 ) swap_rows( a, j, i );
			scale_row( a, i, 1/a[i][i] );
			for( int j = 0; j < n; j++ )
				if( i != j )
					add_rows( a, j, i, -a[j][i] );
		}
		double[] x = new double[n];
		for( int i = 0; i < n; i++ ) x[i] = a[i][n];
		return x;
	}

	static void scale_row( double[][] a, int x, double c  )
	{
		int n = a[0].length;
		for( int i = 0; i < n; i++ ) a[x][i] *= c;
	}

	static void swap_rows( double[][] a, int x, int y )
	{
		double[] temp = a[x];
		a[x] = a[y];
		a[y] = temp;
	}

	static void add_rows( double[][] a, int x, int y, double c  )
	{
		int n = a[0].length;
		for( int i = 0; i < n; i++ ) a[x][i] += c*a[y][i];
	}

}
