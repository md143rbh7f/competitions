/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Split
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Split().solve( i );
	}

	void solve( int caseNum )
	{
		chars = in.next().toCharArray();
		Node tree = new Node();
		tree.stretch();
		System.out.println( caseNum );
		System.out.print( tree );
	}

	char chars[], stringBuf[][];
	int max = 0, x[];
	static char[] walls = { '|', '-' };

	class Node
	{
		int dim[] = new int[2];
		char v;
		LinkedList<Node> c;
		
		Node()
		{
			v = chars[max];
			max++;
			if( v >= 'A' && v <= 'Z' ) dim[0] = dim[1] = 2;
			else
			{
				c = new LinkedList<Node>();
				v = (char)( v == '|' ? 1 : 0 );
				for( int j = 0; j < 2; j++ )
				{
					Node child = new Node();
					dim[v] += child.dim[v];
					dim[1-v] = dim[1-v] > child.dim[1-v] ? dim[1-v] : child.dim[1-v];
					if( child.v == v )
						for( Node cc : child.c )
							c.add( cc );
					else c.add( child );
				}
			}
		}

		void stretch()
		{
			if( c == null ) return;
			for( Node child : c )
			{
				if( dim[1-v] > child.dim[1-v] )
				{
					int len = dim[1-v];
					child.dim[1-v] = len;
					if( child.c != null ) 
					{
						int ea = len/child.c.size();
						for( Node cc : child.c )
						{
							cc.dim[1-v] = ea;
							if( len > ea*child.c.size() )
							{
								cc.dim[1-v]++;
								len--;
							}
							cc.stretch();
						}
					}
				}
				child.stretch();
			}
		}

		public String toString()
		{
			stringBuf = new char[dim[0]+1][dim[1]+1];
			for( int i = 0; i <= dim[0]; i++ ) for( int j = 0; j <= dim[1]; j++ ) stringBuf[i][j] = ' ';
			x = new int[2];
			generate();
			String res = "";
			for( int i = 0; i < 2; i++ )
			{
				x[i] = 0; x[1-i] = dim[1-i];
				for( int j = 0; j <= dim[i]; j++ )
				{
					char current = stringBuf[x[0]][x[1]];
					if( current == '-' || current == '|' ) stringBuf[x[0]][x[1]] = '*';
					else stringBuf[x[0]][x[1]] = walls[i];
					x[i]++;
				}
			}
			for( int i = 0; i <= dim[0]; i++ )
				res += new String( stringBuf[i] ) + "\n";
			return res;
		}
		void generate()
		{
			if( c == null )
			{
				stringBuf[x[0]][x[1]] = v;
				for( int i = 0; i < 2; i++ )
				{
					for( int j = 0; j < dim[i]; j++ )
					{
						x[i]++;
						char current = stringBuf[x[0]][x[1]];
						if( current == '-' || current == '|' ) stringBuf[x[0]][x[1]] = '*';
						else stringBuf[x[0]][x[1]] = walls[i];
					}
					x[i] -= dim[i];
				}
			}
			else
			{
				for( Node child : c )
				{
					child.generate();
					for( int i = 0; i < 2; i++ )
						x[i] += ( v == i ? child.dim[i] : 0 );
				}
				for( Node child : c )
					for( int i = 0; i < 2; i++ )
						x[i] -= ( v == i ? child.dim[i] : 0 );
			}
		}
	}
}
