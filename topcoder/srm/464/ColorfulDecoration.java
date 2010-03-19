/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class ColorfulDecoration
{
	static int max = 1<<30;

	public int getMaximum( int[] xa, int[] ya, int[] xb, int[] yb )
	{
		int n = xa.length, N = n<<1;
		int[] x = new int[N], y = new int[N], dist[] = new int[N][N];
		for( int i = 0; i < n; i++ )
		{
			x[i] = xa[i];
			y[i] = ya[i];
			x[i+n] = xb[i];
			y[i+n] = yb[i];
		}
		for( int i = 0; i < N; i++ ) for( int j = i+1; j < N; j++ )
			dist[i][j] = dist[j][i] = Math.max( Math.abs(x[i]-x[j]), Math.abs(y[i]-y[j]) );

		int d = max, best = 0;
		binsearch: while( (d>>=1) != 0 )
		{
			int test = best+d;
			boolean[][] edge = new boolean[N][N];
			for( int i = 0; i < N; i++ ) for( int j = i; j < N; j++ )
				if( i!=j && dist[i][j]<test )
					edge[i][(j+n)%N] = edge[j][(i+n)%N] = true;
			for( int k = 0; k < N; k++ ) for( int i = 0; i < N; i++ ) for( int j = 0; j < N; j++ )
				edge[i][j] |= edge[i][k] & edge[k][j];
			for( int i = 0; i < n; i++ )
				if( edge[i][i+n] && edge[i+n][i] )
					continue binsearch;
			best = test;
		}
		return best;
	}
}
