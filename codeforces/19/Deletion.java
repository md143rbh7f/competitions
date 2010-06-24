import java.io.*;
import java.math.*;
import java.util.*;
import java.awt.Point;

public class Deletion
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int n = in.nextInt(), s[] = new int[n];
		for( int i = 0; i < n; i++ ) s[i] = in.nextInt();
		HashMap<Integer,LinkedList<Integer>> pos = new HashMap<Integer,LinkedList<Integer>>();
		for( int i = 0; i < n; i++ )
		{
			if( !pos.containsKey(s[i]) ) pos.put( s[i], new LinkedList<Integer>() );
			pos.get(s[i]).add(i);
		}
		int min = 0;
		TreeSet<Point> rep = new TreeSet<Point>( new Comp() );
		for( int a : pos.keySet() ) for( int b : pos.get(a) ) for( int c : pos.get(a) ) if( c>b ) rep.add( new Point(b,c) );
		while( !rep.isEmpty() )
		{
			Point p = rep.pollFirst();
			if( p.x<min || 2*p.y-p.x>n ) continue;
			boolean works = true;
			for( int i = 0; p.x+i<p.y && p.y+i<n; i++ )
			if( s[p.x+i]!=s[p.y+i] )
			{
				works = false;
				break;
			}
			if( !works ) continue;
			min = p.y;
		}
		System.out.println( n-min );
		for( int i = min; i < n; i++ ) System.out.print( s[i]+" " );
	}

	static class Comp implements Comparator<Point>
	{
		public int compare( Point a, Point b )
		{
			int da = a.y-a.x, db = b.y-b.x;
			if( da!=db ) return da-db;
			return a.x-b.x;
		}
	}
}
