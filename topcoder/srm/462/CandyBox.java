/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class CandyBox
{
	public double[] expectedScore( int c, int[] s, int T )
	{
		int n = s.length;
		double res[][] = new double[2][n];
		double tot = choose2(c*n);
		double w1 = c/tot;
		double w2 = (choose2(c*(n-1))+choose2(c))/tot+w1*((n-1)*(c-1)-1);
		for( int i = 0; i < n; i++ ) res[0][i] = s[i];
		for( int t = 1; t <= T; t++ )
		{
			double sum = 0;
			for( int i = 0; i < n; i++ ) sum += res[(t-1)%2][i];
			sum *= w1;
			for( int i = 0; i < n; i++ ) res[t%2][i] = sum+w2*res[(t-1)%2][i];
		}
		return res[T%2];
	}

	static double choose2( int n )
	{
		return n*(n-1)/2.0;
	}
}
