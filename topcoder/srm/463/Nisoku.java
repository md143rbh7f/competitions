/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Nisoku
{
	public double theMax( double[] c )
	{
		Arrays.sort(c);
		int n = c.length;
		double res = 1;
		for( int i = 0; i <= n; i++ )
		{
			double t = 1;
			for( int j = i; j < n; j++ ) t *= c[j];
			for( int j = 0; j < i/2; j++ ) t *= c[j]+c[i-1-j];
			if( i%2 == 1 ) t *= c[i/2];
			if( t > res ) res = t;
		}
		return res;
	}
}
