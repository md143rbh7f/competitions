import java.io.*;
import java.math.*;
import java.util.*;

public class Zoned
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Zoned().solve( caseNum++ ) );
	}

	HashSet<Integer>[] mark, unmark, pass, seen;
	boolean[] seencopy;

	void rec( int c, HashSet<Integer> f )
	{
		int oldsize = seen[c].size();
		seen[c].addAll(f);
		seen[c].addAll(mark[c]);
		seen[c].removeAll(unmark[c]);
		if( seencopy[c] && oldsize==seen[c].size() ) return;
		seencopy[c] = true;
		for( int i : pass[c] ) rec(i,seen[c]);
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt(), m = in.nextInt();
		if(n==0&&m==0) return false;
		seencopy = new boolean[m];
		mark = (HashSet<Integer>[])(new HashSet[m]);
		unmark = (HashSet<Integer>[])(new HashSet[m]);
		pass = (HashSet<Integer>[])(new HashSet[m]);
		seen = (HashSet<Integer>[])(new HashSet[m]);
		in.nextLine();
		for( int i = 0; i < m; i++ )
		{
			mark[i] = new HashSet<Integer>();
			unmark[i] = new HashSet<Integer>();
			pass[i] = new HashSet<Integer>();
			seen[i] = new HashSet<Integer>();
			String[] l;
			l = in.nextLine().trim().split("\\s+");
			for( int j = 0; j < l.length; j++ ) if(l[j].length()>0) mark[i].add(Integer.parseInt(l[j]));
			l = in.nextLine().trim().split("\\s+");
			for( int j = 0; j < l.length; j++ ) if(l[j].length()>0) unmark[i].add(Integer.parseInt(l[j]));
			l = in.nextLine().trim().split("\\s+");
			for( int j = 0; j < l.length; j++ ) if(l[j].length()>0) pass[i].add(Integer.parseInt(l[j]));
		}
		rec(0,new HashSet<Integer>());
		ArrayList<Integer> res = new ArrayList<Integer>();
		for( int i : seen[0] ) res.add(i);
		Collections.sort(res);
		for( int i : res ) System.out.printf( "%d ", i );
		System.out.println();
		return true;
	}
}
