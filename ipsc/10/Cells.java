import java.io.*;
import java.math.*;
import java.util.*;

public class C
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new C().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt();
		in.nextLine();
		HashSet<Integer>[] g = (HashSet<Integer>[])(new HashSet[n]);
		HashSet<Integer>[] p = (HashSet<Integer>[])(new HashSet[n]);
		for( int i = 0; i < n; i++ )
		{
			g[i] = new HashSet<Integer>();
			p[i] = new HashSet<Integer>();
		}
		String[][] eq = new String[n][];
		HashMap<String,Integer> d = new HashMap<String,Integer>();
		for( int i = 0; i < n; i++ )
		{
			eq[i] = in.nextLine().split(" ");
			d.put( eq[i][0], i );
		}
		for( int i = 0; i < n; i++ )
		for( int j = 2; j < eq[i].length; j++ )
		{
			char c = eq[i][j].charAt(0);
			if( eq[i][j].length()>1 && !(c>='0'&&c<='9') )
			{
				int v = d.get(eq[i][j]);
				g[v].add(i);
				p[i].add(v);
			}
		}
		TreeMap<String,Integer> val = new TreeMap<String,Integer>();
		int q[] = new int[n], qptr = 0;
		for( int i = 0; i < n; i++ ) if( p[i].size() == 0 ) q[qptr++] = i;
		for( int i = 0; i < n; i++ )
		{
			int v = q[i];
			String str = eq[v][0];
			val.put( str, eval(eq[v]) );
			for( int c : g[v] )
			{
				for( int j = 0; j < eq[c].length; j++ ) if( eq[c][j].equals(str) ) eq[c][j] = ""+val.get(str);
				p[c].remove(v);
				if( p[c].size()==0 ) q[qptr++] = c;
			}
		}
		for( String s : val.keySet() ) System.out.println( s+" = "+val.get(s) );
		System.out.println();
	}

	static int eval( String[] eq )
	{
		int n = eq.length-2;
		String[] tmp = new String[n];
		for( int i = 0; i < n; i++ ) tmp[i] = eq[i+2];
		int j = 0;
		//System.out.println( Arrays.toString(tmp));
		for( int i = 0; i < n; i++ )
		{
			if( tmp[i].equals("*") )
			{
				tmp[j-1] = ""+(Integer.parseInt(tmp[j-1])*Integer.parseInt(tmp[i+1]));
				i++;
			}
			else if( tmp[i].equals("/") )
			{
				tmp[j-1] = ""+(Integer.parseInt(tmp[j-1])/Integer.parseInt(tmp[i+1]));
				i++;
			}
			else tmp[j++] = tmp[i];
		}
		n = j;
		j = 0;
		for( int i = 0; i < n; i++ )
		{
			if( tmp[i].equals("+") )
			{
				tmp[j-1] = ""+(Integer.parseInt(tmp[j-1])+Integer.parseInt(tmp[i+1]));
				i++;
			}
			else if( tmp[i].equals("-") )
			{
				tmp[j-1] = ""+(Integer.parseInt(tmp[j-1])-Integer.parseInt(tmp[i+1]));
				i++;
			}
			else tmp[j++] = tmp[i];
		}
		//if( j!=1 ) System.out.println( "NTAOESUHTNASOEUSNATSNOEUHTSNAHTSNEUOH" );
		/*
		for( int i = 0; i < j; i++ ) System.out.print( tmp[i] +" " );
		System.out.println();
		*/
		return Integer.parseInt( tmp[0] );
	}
}
