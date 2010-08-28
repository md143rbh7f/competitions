import java.util.*;

public class InternetSecurity
{
	public String[] determineWebsite( String[] addr, String[] key, String[] dang, int t )
	{
		int n = addr.length;
		HashSet<String> d = new HashSet<String>();
		for( String s : dang ) d.add(s);
		HashSet<String>[] w = (HashSet<String>[])(new HashSet[n]);
		for( int i = 0; i < n; i++ )
		{
			String[] tmp = key[i].split(" ");
			w[i] = new HashSet<String>();
			for( String s : tmp ) w[i].add(s);
		}
		LinkedList<Integer> q = new LinkedList<Integer>();
		boolean[] bad = new boolean[n];
		for( int i = 0; i < n; i++ )
		{
			int cnt = 0;
			for( String s : w[i] ) if( d.contains(s) ) cnt++;
			if( cnt>=t )
			{
				q.add(i);
				bad[i] = true;
			}
		}
		while(!q.isEmpty())
		{
			int v = q.poll();
			for( String word : w[v] ) d.add(word);
			for( int i = 0; i < n; i++ ) if( !bad[i] )
			{
				int cnt = 0;
				for( String s : w[i] ) if( d.contains(s) ) cnt++;
				if( cnt>=t )
				{
					q.add(i);
					bad[i] = true;
				}
			}
		}
		int numbad = 0;
		for( int i = 0; i < n; i++ ) if( bad[i] ) numbad++;
		String[] ans = new String[numbad];
		int qptr = 0;
		for( int i = 0; i < n; i++ ) if( bad[i] ) ans[qptr++] = addr[i];
		return ans;
	}
}
