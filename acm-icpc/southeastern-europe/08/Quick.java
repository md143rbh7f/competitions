/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Quick
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Quick().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		if( !in.hasNextInt() ) return false;
		int n = in.nextInt();
		if( n == 0 ) return false;

		UFNode[] graph = new UFNode[n+1];
		int[] yes = new int[2];
		for( int i = 0; i < graph.length; i++ ) graph[i] = new UFNode();

		PARSE: while( true )
		{
			switch( in.next().charAt(0) )
			{
				case 'c': graph[in.nextInt()].merge( graph[in.nextInt()] ); break;
				case 'd': graph[in.nextInt()].remove(); break;
				case 'q': yes[ graph[in.nextInt()].find() == graph[in.nextInt()].find() ? 0 : 1 ]++; break;
				case 'e': break PARSE;
			}
		}

		System.out.println( yes[0] + " , " + yes[1] );
		
		return true;
	}

	class UFNode
	{
		UFNode parent;
		HashSet<UFNode> children = new HashSet<UFNode>();
		int size = 1;

		UFNode find()
		{
			UFNode root = this;
			while( root.parent != null ) root = root.parent;

			UFNode ptr = this;
			while( ptr != root )
			{
				UFNode old = ptr;
				ptr = ptr.parent;
				ptr.children.remove( old );
				old.parent = root;
				root.children.add( old );
			}
			return root;
		}

		int merge( UFNode x )
		{
			x = x.find();
			UFNode y = this.find();

			if( x != y )
			{
				if( x.size < y.size )
				{
					UFNode temp = x;
					x = y;
					y = temp;
				}
				x.size += y.size;
				y.size = 0;
				y.parent = x;
				x.children.add( y );
			}

			return x.size;
		}

		void remove()
		{
			UFNode root = this.find();
			if( root != this ) for( UFNode child : children ) child.parent = root;
			else if( !children.isEmpty() )
			{
				Iterator<UFNode> it = children.iterator();
				root = it.next();
				root.parent = null;
				while( it.hasNext() ) it.next().parent = root;
				root.size = this.size;
			}
			root.size--;
			this.parent = null;
			this.size = 1;
		}
	}

}
