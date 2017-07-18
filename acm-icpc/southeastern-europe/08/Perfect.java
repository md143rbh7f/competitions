/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Perfect
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Perfect().solve( caseNum++ ) );
	}

	int o, z;
	boolean solve( int caseNum )
	{
		int n = in.nextInt(), m = in.nextInt();
		if( n == 0 ) return false;

		o = 2*n+1; z = o-1;
		LinkedList<Integer>[] g = (LinkedList<Integer>[])(new LinkedList[o]);
		for( int i = 0; i < o; i++ )
		{
			g[i] = new LinkedList<Integer>();
			g[i].add(n);
		}
		for( int i = 0; i < m; i++ )
		{
			int a = parse( in.next() ), b = parse( in.next() );
			if( a != b )
			{
				g[z-a].add(b);
				g[z-b].add(a);
			}
			else g[n].add(a);
		}

		int[] comp = tarjan( g );
		for( int i = 0; i < n; i++ )
		if( comp[i] == comp[z-i] )
			{
				System.out.println(0);
				return true;
			}

		System.out.println(1);
		return true;
	}

	int parse( String a )
	{
		if( a.charAt(0) == '-' ) return o+Integer.parseInt(a);
		int ans = 0;
		for( int i = 1; i < a.length(); i++ )
		{
			ans *= 10;
			ans += (a.charAt(i)-'0');
		}
		return ans-1;
	}


	int[] tarjan( LinkedList<Integer>[] g )
	{
		int n = g.length, t = 0, in[] = new int[n], min[] = new int[n], comp[] = new int[n], dfs[] = new int[n], sp, stack[] = new int[n], sp2 = 0, v, c;
		boolean[] onstack = new boolean[n];
		ListIterator<Integer>[] step = (ListIterator<Integer>[])(new ListIterator[n]);
		for( int i = 0; i < n; i++ ) comp[i] = i;
		for( int i = 0; i < n; i++ )
			if( min[i] == 0 )
			{
				dfs[sp=0] = i;
				DFS: while( sp != -1 )
				{
					v = dfs[sp];
					if( in[v] == 0 )
					{
						in[v] = min[v] = ++t;
						stack[sp2++] = v;
						onstack[v] = true;
						step[v] = (ListIterator<Integer>)g[v].listIterator();
					}
					while( step[v].hasNext() )
					{
						c = step[v].next();
						if( in[c] == 0 )
						{
							step[v].previous();
							dfs[++sp] = c;
							continue DFS;
						}
						if( onstack[c] && min[c] < min[v] ) min[v] = min[c];
					}
					if( min[v] == in[v] ) do
					{
						comp[c=stack[--sp2]] = comp[v];
						onstack[c] = false;
					}
					while( c != v );
					sp--;
				}
			}
		return comp;
	}

}
