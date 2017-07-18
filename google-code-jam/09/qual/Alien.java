/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Alien
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int l = in.nextInt(), d = in.nextInt(), n = in.nextInt();
		in.nextLine();
		HashSet<String> words = new HashSet<String>();
		for( int i = 0; i < d; i++ ) words.add( in.nextLine() );
		for( int i = 1; i <= n; i++ )
		{
			String pattern = in.nextLine();
			HashSet<Character>[] match = (HashSet<Character>[])(new HashSet[l]);
			for( int k = 0; k < l; k++ ) match[k] = new HashSet<Character>();
			int j = 0;
			boolean inParens = false;
			for( int k = 0; k < pattern.length(); k++ )
			{
				char c = pattern.charAt(k);
				if( c=='(' ) inParens = true;
				else
				{
					if( c==')' ) inParens = false;
					else match[j].add( c );
					if( !inParens ) j++;
				}
			}
			int count = 0;
			outer: for( String w : words )
			{
				for( int k = 0; k < l; k++ )
					if( !match[k].contains(w.charAt(k)) )
						continue outer;
				count++;
			}
			System.out.printf( "Case #%d: %d\n", i, count );
		}
	}
}
