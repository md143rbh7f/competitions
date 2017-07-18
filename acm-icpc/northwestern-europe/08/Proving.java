import java.util.*;

public class Proving
{
	static Scanner in = new Scanner( System.in );

	public static void main( String[] args )
	{
		int N = in.nextInt();
		while( N-- > 0 ) new Proving().solve();
	}

	boolean seen[], ok1[], ok2[];
	LinkedList<Integer> g[], h[];
	int q[], nq, c[], nc;

	void dfs1( int x )
	{
		if( seen[x] ) return;
		seen[x] = true;
		for( int y : g[x] ) dfs1(y);
		q[nq++] = x;
	}

	void dfs2( int x )
	{
		if( c[x] > -1 ) return;
		c[x] = nc;
		for( int y : h[x] ) dfs2(y);
	}

	void solve()
	{
		int n = in.nextInt(), m = in.nextInt();
		g = (LinkedList<Integer>[])(new LinkedList[n]);
		h = (LinkedList<Integer>[])(new LinkedList[n]);
		for( int i = 0; i < n; i++ )
		{
			g[i] = new LinkedList<Integer>();
			h[i] = new LinkedList<Integer>();
		}
		for( int i = 0; i < m; i++ )
		{
			int a = in.nextInt(), b = in.nextInt();
			g[a-1].add(b-1);
			h[b-1].add(a-1);
		}

		nq = 0;
		q = new int[n];
		seen = new boolean[n];
		for( int i = 0; i < n; i++ ) dfs1(i);

		nc = 0;
		c = new int[n];
		Arrays.fill( c, -1 );
		for( int i = n-1; i >= 0; i-- ) if( c[q[i]] == -1 )
		{
			dfs2(q[i]);
			nc++;
		}

		if( nc == 1 )
		{
			System.out.println( 0 );
			return;
		}

		ok1 = new boolean[n];
		ok2 = new boolean[n];
		for( int i = 0; i < n; i++ ) for( int j : g[i] ) if( c[i] != c[j] )
			ok1[c[j]] = ok2[c[i]] = true;

		int cnt1 = 0, cnt2 = 0;
		for( int i = 0; i < nc; i++ )
		{
			if( !ok1[i] ) cnt1++;
			if( !ok2[i] ) cnt2++;
		}
		System.out.println( Math.max( cnt1, cnt2 ) );
	}
}
