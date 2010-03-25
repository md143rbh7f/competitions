/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class PowerPlants
{
	static int inf = 0x00ffffff;
	public int minCost( String[] connectionCost, String plantList, int need )
	{
		int n = connectionCost.length, c[][] = new int[n][n], N = 1<<n;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		{
			c[i][j] = connectionCost[i].charAt(j);
			if( c[i][j]>='0' && c[i][j]<='9' ) c[i][j] -= '0';
			else c[i][j] = c[i][j]-'A'+10;
		}
		int start = 0, d[] = new int[N], min = inf;
		for( int i = 0; i < n; i++ ) if( plantList.charAt(i)=='Y' ) start += 1<<i;
		Arrays.fill( d, inf );
		d[start] = 0;
		for( int mask = start; mask < N; mask++ ) if( d[mask] != inf )
		{
			if( Integer.bitCount(mask)>=need && d[mask]<min ) min = d[mask];
			for( int i = 0; i < n; i++ )
			if( ((mask>>i)&1) == 0 )
			{
				int cost = inf, next = mask|(1<<i);
				for( int j = 0; j < n; j++ )
					if( ((mask>>j)&1)==1 && c[j][i]<cost )
						cost = c[j][i];
				if( d[next]>d[mask]+cost ) d[next]=d[mask]+cost;
			}
		}
		return min;
	}
}
