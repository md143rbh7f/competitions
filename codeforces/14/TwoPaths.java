import java.io.*;
import java.math.*;
import java.util.*;

public class TwoPaths
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int inf = 10001;

	public static void main( String[] args )
	{
		int n = in.nextInt(), m = n-1, e[][] = new int[m][2];
		HashSet<Integer>[] g = (HashSet<Integer>[])(new HashSet[n]);
		for( int i = 0; i < n; i++ ) g[i] = new HashSet<Integer>();
		for( int i = 0; i < m; i++ )
		{
			int a = in.nextInt()-1, b = in.nextInt()-1;
			g[a].add(b); g[b].add(a);
			e[i][0] = a; e[i][1] = b;
		}
		int ans = 0;
		for( int i = 0; i < m; i++ )
		{
			int a = e[i][0], b = e[i][1], maxa = 0, maxb = 0;
			g[a].remove(b); g[b].remove(a);
			for( int j = 0; j < n; j++ )
			{
				int[] d = new int[n];
				boolean[] seen = new boolean[n];
				LinkedList<Integer> q = new LinkedList<Integer>();
				q.add(j);
				seen[j] = true;
				while( !q.isEmpty() )
				{
					int ptr = q.poll();
					for( int c : g[ptr] )
					if( !seen[c] )
					{
						seen[c] = true;
						d[c] = d[ptr]+1;
						q.add(c);
					}
				}
				for( int k = 0; k < n; k++ )
				{
					if( seen[a] && d[k]>maxa ) maxa = d[k];
					if( seen[b] && d[k]>maxb ) maxb = d[k];
				}
			}
			g[a].add(b); g[b].add(a);
			if( maxa*maxb>ans ) ans = maxa*maxb;
		}
		System.out.println( ans );
	}
}
