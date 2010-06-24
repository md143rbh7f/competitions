import java.io.*;
import java.math.*;
import java.util.*;

public class Football
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	static int n, pts[], scored[], missed[];
	static HashMap<String,Integer> dict;
	public static void main( String[] args )
	{
		n = in.nextInt();
		String[] perm = new String[n];
		dict = new HashMap<String,Integer>();
		for( int i = 0; i < n; i++ )
		{
			perm[i] = in.next();
			dict.put( perm[i], i );
		}
		pts = new int[n]; scored = new int[n]; missed = new int[n];
		for( int i = 0; i < n*(n-1)/2; i++ )
		{
			String[] t = in.next().split("-");
			int a = dict.get(t[0]), b = dict.get(t[1]);
			String[] s = in.next().split(":");
			int as = Integer.parseInt(s[0]), bs = Integer.parseInt(s[1]);
			if( as>bs ) pts[a] += 3;
			else if( as<bs ) pts[b] += 3;
			else { pts[a]++; pts[b]++; }
			scored[a] += as;
			scored[b] += bs;
			missed[a] += bs;
			missed[b] += as;
		}
		Arrays.sort( perm, new Comp() );
		String[] top = new String[n/2];
		for( int i = 0; i < n/2; i++ ) top[i] = perm[i];
		Arrays.sort( top );
		for( int i = 0; i < n/2; i++ ) System.out.println( top[i] );
	}

	static class Comp implements Comparator<String>
	{
		public int compare( String A, String B )
		{
			int a = dict.get(A), b = dict.get(B);
			if( pts[a]!=pts[b] ) return pts[b]-pts[a];
			int da = scored[a]-missed[a], db = scored[b]-missed[b];
			if( da!=db ) return db-da;
			if( scored[a]!=scored[b] ) return scored[b]-scored[a];
			return A.compareTo(B);
		}
	}
}
