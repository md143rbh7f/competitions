import java.math.*;
import java.util.*;

public class TheAirTripDivOne
{
	long d[], INF = 1l<<42;

	public int find( int n, String[] flights, int maxt )
	{
		LinkedList<int[]>[] g = (LinkedList<int[]>[])(new LinkedList[n]);
		for( int i = 0; i < n; i++ ) g[i] = new LinkedList<int[]>();
		String buf = "";
		for( int i = 0; i < flights.length; i++ ) buf += flights[i];
		flights = buf.split(" ");
		for( String s : flights )
		{
			String[] tmp = s.split(",");
			int a = Integer.parseInt(tmp[0])-1, b[] = new int[4];
			for( int i = 0; i < 4; i++ ) b[i] = Integer.parseInt(tmp[i+1]);
			b[0]--;
			g[a].add(b);
		}
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>( n, new Comp() );
		d = new long[n];
		int best = 0, d2 = 1<<30;
		while( (d2>>=1)!=0 )
		{
			int safe = best + d2;
			d[0] = 0;
			pq.add(0);
			for( int i = 1; i < n; i++ ) d[i] = INF;
			while(!pq.isEmpty())
			{
				int a = pq.poll();
				long t0 = d[a];
				if( t0>maxt ) break;
				for( int[] e : g[a] )
				{
					int b = e[0], f = e[1], dt = e[2], p = e[3];
					long depart = t0+safe;
					if(a==0) depart = 0;
					if(depart<f) depart = f;
					else depart = (t0+safe-f+p-1)/p*p+f;
					long t1 = depart + dt;
					if( t1<d[b] )
					{
						pq.remove(b);
						d[b] = t1;
						pq.add(b);
					}
				}
			}
			if( d[n-1]<=maxt ) best = safe;
		}
		return best==0 ? -1 : best;
	}

	public class Comp implements Comparator<Integer>
	{
		public int compare( Integer a, Integer b )
		{
			if( d[a]<d[b] ) return -1;
			if( d[a]>d[b] ) return 1;
			return a-b;
		}
	}
}
