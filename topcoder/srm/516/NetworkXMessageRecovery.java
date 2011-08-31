import java.util.*;

public class NetworkXMessageRecovery
{
	public String recover( String[] msgs )
	{
		HashMap<Character,HashSet<Character>> g = new HashMap<Character,HashSet<Character>>();
		HashMap<Character,Integer> p = new HashMap<Character,Integer>();
		TreeSet<Character> q = new TreeSet<Character>();
		for( String msg : msgs ) for( int i = 0; i < msg.length(); i++ )
		{
			p.put( msg.charAt(i), 0 );
			g.put( msg.charAt(i), new HashSet<Character>() );
		}
		for( String msg : msgs ) for( int i = 1; i < msg.length(); i++ ) g.get(msg.charAt(i-1) ).add( msg.charAt(i) );
		for( char a : g.keySet() ) for( char b : g.get(a) ) p.put( b, p.get(b) + 1 );
		for( char a : g.keySet() ) if( p.get(a) == 0 ) q.add(a);
		String ans = "";
		while( !q.isEmpty() )
		{
			char a = q.first();
			q.remove(a);
			ans += a;
			for( char b : g.get(a) )
			{
				p.put( b, p.get(b) - 1 );
				if( p.get(b) == 0 ) q.add(b);
			}
		}
		return ans;
	}
};
