public class TheMoviesLevelTwoDivOne
{
	public int[] find( int[] len, int[] s )
	{
		int n = len.length, N = 1<<n, max[] = new int[N], next[] = new int[N];
		for( int m = N-2; m >= 0; m-- )
		{
			max[m] = -1;
			int scary = 74;
			for( int i = 0; i < n; i++ ) if( (m>>i)%2 == 1 ) scary += 47-len[i];
			for( int i = 0; i < n; i++ ) if( (m>>i)%2 == 0 )
			{
				int nextm = m+(1<<i);
				if( scary>=s[i] && scary+47>=len[i] )
				{
					if( max[m]<1+max[nextm] )
					{
						max[m] = 1+max[nextm];
						next[m] = i;
					}
				}
				else if( max[m]<0 )
				{
					max[m] = 0;
					next[m] = i;
				}
			}
		}
		int res[] = new int[n], set = 0;
		for( int i = 0; i < n; i++ )
		{
			res[i] = next[set];
			set = set+(1<<next[set]);
		}
		return res;
	}
}
