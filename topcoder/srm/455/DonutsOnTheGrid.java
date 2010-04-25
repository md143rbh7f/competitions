import java.math.*;
import java.util.*;

public class DonutsOnTheGrid
{
	public long calc( int x, int y, int seed, int threshold )
	{
		boolean[][] d = new boolean[x][y];
		for( int i = 0; i < x; i++ ) for( int j = 0; j < y; j++ ) d[i][j] = (seed=(seed*25173+13849)%65536)<threshold;
		int[][] sy = new int[x][y];
		for( int i = 0; i < x; i++ )
		{
			sy[i][0] = d[i][0]?1:0;
			for( int j = 1; j < y; j++ ) sy[i][j] = (d[i][j]?1:0)+sy[i][j-1];
		}
		long ans = 0;
		for( int j1 = 0; j1 < y; j1++ ) for( int j2 = j1+2; j2 < y; j2++ )
		{
			int i1 = 0;
			while( i1 < x )
			{
				if( d[i1][j1] && d[i1][j2] )
				{
					int count = 0, adj = 0, i2 = i1, last = -2;
					while( i2<x && d[i2][j1] && d[i2][j2] )
					{
						if( sy[i2][j2]-sy[i2][j1] == j2-j1 )
						{
							count++;
							if( last==i2-1 ) adj++;
							last = i2;
						}
						i2++;
					}
					ans += count*(count-1)/2-adj;
					i1 = i2;
				}
				else i1++;
			}
		}
		return ans;
	}
}
