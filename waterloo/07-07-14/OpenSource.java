/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class OpenSource
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new OpenSource().solve( caseNum++ ) );
	}

	HashMap<String,HashSet<String>> signUp = new HashMap<String,HashSet<String>>();
	HashSet<String> students = new HashSet<String>();
	HashSet<String> bad = new HashSet<String>();
	boolean solve( int caseNum )
	{
		String last = "";
		while( in.hasNextLine() )
		{
			String l = in.nextLine();
			if( l.equals("0") ) return false;
			if( l.equals("1") ) break;
			if( upperCase(l) )
			{
				last = l;
				signUp.put( last, new HashSet<String>() );
			}
			else signUp.get(last).add(l);
		}
		for( String p : signUp.keySet() ) for( String s : signUp.get(p) )
			if( students.contains(s) ) bad.add(s);
			else students.add(s);
		for( String p : signUp.keySet() ) for( String s : bad )
			signUp.get(p).remove(s);
		String[] res = new String[signUp.size()];
		int t = 0;
		for( String s : signUp.keySet() ) res[t++] = s;
		Arrays.sort( res, new Comp() );
		for( String s : res ) System.out.println( s + " " + signUp.get(s).size() );
		return true;
	}

	boolean upperCase( String s )
	{
		for( int i = 0; i < s.length(); i++ )
			if( s.charAt(i)!=' ' && (s.charAt(i)<'A'||s.charAt(i)>'Z') )
				return false;
		return true;
	}

	class Comp implements Comparator<String>
	{
		public int compare( String a, String b )
		{
			if( signUp.get(a).size() != signUp.get(b).size() )
				return signUp.get(b).size()-signUp.get(a).size();
			return a.compareTo(b);
		}
	}
}
