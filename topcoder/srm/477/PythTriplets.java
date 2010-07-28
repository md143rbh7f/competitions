import java.math.*;
import java.util.*;

public class PythTriplets
{
	public int findMax( String[] stick )
	{
		String tmp = "";
		for( int i = 0; i < stick.length; i++ ) tmp += stick[i];
		String[] tmp2 = tmp.split(" ");
		int n = tmp2.length, N = 2*n+2, cap[][] = new int[N][N];
		long nums[] = new long[n];
		for( int i = 0; i < n; i++ ) nums[i] = Integer.parseInt(tmp2[i]);
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) if( gcd(nums[i],nums[j])==1 )
		{
			long d2 = nums[i]*nums[i]+nums[j]*nums[j], d = (long)Math.sqrt(d2);
			if( d*d==d2 )
			{
				cap[i][j+n] = 1;
				cap[j][i+n] = 1;
			}
		}
		for( int i = 0; i < n; i++ ) cap[N-2][i] = 1;
		for( int i = 0; i < n; i++ ) cap[i+n][N-1] = 1;
		return maxflow( cap, N-2, N-1 )/2;
	}
	
	static long gcd( long a, long b )
	{
		while( b != 0 )
		{
			long t = a%b;
			a = b;
			b = t;
		}
		return a;
	}

	int maxflow( int[][] cap, int s, int t )
	{
		int[][] flow = new int[cap.length][cap.length];
		boolean[] seen;
		do seen = new boolean[cap.length];
		while( maxflow_search( cap, flow, seen, s, t, 1<<20 ) != -1 );
		int max = 0;
		for( int i = 0; i < flow.length; i++ ) max += flow[i][t];
		return max;
	}

	int maxflow_search( int[][] cap, int[][] flow, boolean[] seen, int s, int t, int minflow )
	{
		if( s == t ) return minflow;
		if( seen[s] ) return -1;
		seen[s] = true;
		for( int i = 0; i < flow.length; i++ )
		{
			int residual = cap[s][i] - flow[s][i];
			if( residual <= 0 ) continue;
			int minflow2 = Math.min( minflow, residual );
			minflow2 = Math.min( minflow2, maxflow_search( cap, flow, seen, i, t, minflow2 ) );
			if( minflow2 != -1 )
			{
				flow[s][i] += minflow2;
				flow[i][s] -= minflow2;
				return minflow2;
			}
		}
		return -1;
	}
}
