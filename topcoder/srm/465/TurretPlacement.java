/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TurretPlacement
{
	public long count( int[] x, int[] y )
	{
		int n = x.length;
		long ways = 0;
		for( int i = 0; i < n; i++ ) for( int j = i+1; j < n; j++ )
		{
			long dx=x[i]-x[j], dy=y[i]-y[j];
			long d = (long)(Math.sqrt(dx*dx+dy*dy)*2);
			ways += (d*(d-1))/2;
		}
		return ways;
	}
}
