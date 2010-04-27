import java.math.*;
import java.util.*;

public class ErdosNumber
{
	public String[] calculateNumbers( String[] pubs )
	{
		HashMap<String,HashSet<String>> g = new HashMap<String,HashSet<String>>();
		for( int i = 0; i < pubs.length; i++ )
		{
			String[] clique = pubs[i].split(" ");
			for( String a : clique ) for( String b : clique )
			{
				if( !g.containsKey( a ) )
					g.put( a, new HashSet<String>() );
				g.get( a ).add( b );
			}
		}
		HashMap<String,Integer> d = new HashMap<String,Integer>();
		LinkedList<String> q = new LinkedList<String>();
		d.put( "ERDOS", 0 );
		q.add( "ERDOS" );
		while( !q.isEmpty() )
		{
			String v = q.poll();
			for( String c : g.get(v) )
			if( !d.containsKey(c) )
			{
				d.put( c, d.get(v)+1 );
				q.add( c );
			}
		}
		String[] ans = new String[g.keySet().size()];
		int temp = 0;
		for( String v : g.keySet() )
			ans[temp++] = v + ( d.containsKey(v) ? " " + d.get(v) : "" );
		Arrays.sort(ans);
		return ans;
	}
}
