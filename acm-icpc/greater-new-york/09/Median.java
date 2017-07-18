/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Median
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Median().solve( i );
	}

	void solve( int caseNum )
	{
		in.nextInt();
		int n = in.nextInt(), m = (n+1)/2;
		PriorityQueue<Integer> l = new PriorityQueue<Integer>( m, new ReverseSorter() ), r = new PriorityQueue<Integer>();
		int med = in.nextInt();
		System.out.print( caseNum + " " + m + "\n" + med );
		for( int i = 1; i < m; i++ )
		{
			int a = in.nextInt(), b = in.nextInt();
			if( a < med && b < med )
			{
				r.add(med);
				l.add(a); l.add(b);
				med = l.poll();
			}
			else if( a > med && b > med )
			{
				l.add(med);
				r.add(a); r.add(b);
				med = r.poll();
			}
			else
			{
				if( a < b )
				{
					l.add(a);
					r.add(b);
				}
				else
				{
					r.add(a);
					l.add(b);
				}
			}
			System.out.print( ( i%10 == 0 ? "\n" : " " ) + med );
		}
		System.out.println();
	}

	class ReverseSorter implements Comparator<Integer>
	{
		public int compare( Integer a, Integer b )
		{
			return b-a;
		}
	}

}
