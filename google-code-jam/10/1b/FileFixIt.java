import java.io.*;
import java.math.*;
import java.util.*;

public class FileFixIt
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new FileFixIt().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt(), m = in.nextInt(), N, M;
		Node r = new Node();
		for( int i = 0; i < n; i++ ) r.add( in.next().split("/"), 1 );
		N = r.size();
		for( int i = 0; i < m; i++ ) r.add( in.next().split("/"), 1 );
		M = r.size();
		System.out.printf( "Case #%d: %d\n", caseNum, M-N );
	}

	class Node
	{
		HashMap<String,Node> children = new HashMap<String,Node>();

		void add( String[] s, int i )
		{
			if( i<s.length )
			{
				if( !children.containsKey(s[i]) ) children.put( s[i], new Node() );
				children.get(s[i]).add(s,i+1);
			}
		}

		int size()
		{
			int ans = 1;
			for( String c : children.keySet() ) ans += children.get(c).size();
			return ans;
		}
	}
}
