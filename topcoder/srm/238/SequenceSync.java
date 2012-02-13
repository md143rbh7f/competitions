import java.util.*;

public class SequenceSync
{
	public int getLength( String[] G )
	{
		int n = G.length, N = 1<<n, g[][] = new int[n][4], dist[] = new int[N];
		Arrays.fill( dist, -1 );
		for( int i = 0; i < n; i++ )
		{
			String[] js = G[i].split(" ");
			for( int j = 0; j < 4; j++ ) g[i][j] = Integer.parseInt(js[j]);
		}
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(N-1);
		dist[N-1] = 0;
		while( !q.isEmpty() )
		{
			int state = q.poll();
			if( Integer.bitCount( state ) == 1 ) return dist[state];
			for( int move = 0; move < 4; move++ )
			{
				int next = 0;
				for( int i = 0; i < n; i++ ) if( ( ( state >> i ) & 1 ) == 1 )
					next |= 1 << g[i][move];
				if( dist[next] == -1 )
				{
					dist[next] = dist[state] + 1;
					q.add(next);
				}
			}
		}
		return -1;
	}
}
