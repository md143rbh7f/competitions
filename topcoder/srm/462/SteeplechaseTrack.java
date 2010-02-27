 /*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class SteeplechaseTrack
{
	public int maxComplexity( String[] v, String[] e, int T )
	{
		int n = v.length+2, g[][] = new int[n][n], c[] = new int[n], best[][] = new int[2][n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < 2; j++ ) best[j][i] = -1; best[0][0] = best[1][0] = 0;
		for( int i = 1; i <= v.length; i++ )
		{
			c[i] = v[i-1].charAt(0)-'0';
			g[0][i] = v[i-1].charAt(1)-'0';
			g[i][n-1] = v[i-1].charAt(2)-'0';
		}
		for( int i = 1; i <= v.length; i++ ) for( int j = 1; j <= v.length; j++ ) g[i][j] = e[i-1].charAt(j-1)-'0';
		T++;
		for( int t = 0; t < T; t++ ) for( int i = 0; i < n; i++ ) if( best[t%2][i] != -1 ) for( int j = 0; j < n; j++ ) if( g[i][j] != 0 )
		{
			int C = best[t%2][i]+g[i][j]+c[j];
			if( C > best[(t+1)%2][j] ) best[(t+1)%2][j] = C;
		}
		if( best[T%2][n-1] == -1 ) return -1;
		return best[T%2][n-1];
	}
}
