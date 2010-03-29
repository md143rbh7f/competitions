/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class BouncingBalls
{
	public double expectedBounces( int[] x, int T )
	{
		int n = x.length;
		double ans = 0;
		Arrays.sort(x);
		for( int i = 0; i < x.length; i++ )
			for( int j = i+1; j < x.length; j++ )
				if( x[i]+T >= x[j]-T )
					ans += 0.25;
		return ans;
	}
}
