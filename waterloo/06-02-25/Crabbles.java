/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Crabbles
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Crabbles().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();

		HashSet<Word> dict = new HashSet<Word>(n);
		for( int i = 0; i < n; i++ )
			dict.add( new Word( in.next() ) );

		int m = in.nextInt(), p;
		char[] have;
		int[] value;
		for( int i = 0; i < m; i++ )
		{
			int max = 0;

			p = in.nextInt();
			have = new char[p];
			value = new int[p];
			for( int j = 0; j < p; j++ )
			{
				have[j] = (char)( in.next().charAt(0) - 'a' );
				value[j] = in.nextInt();
			}

			for( int j = 0; j < (1<<p); j++ )
			{
				char[] test = new char[26];
				for( int k = 0; k < p; k++ )
					if( ( ( j >> k ) & 1 ) == 1 )
						test[have[k]]++;
				Word testWord = new Word( test );
				int testMax = 0;
				if( dict.contains( testWord ) )
					for( int k = 0; k < p; k++ )
						if( ( ( j >> k ) & 1 ) == 1 )
							testMax += value[k];
				if( testMax > max ) max = testMax;
			}

			System.out.println( max );
		}

		return false;
	}

	class Word
	{
		char[] c;
		
		Word( String s )
		{
			c = new char[26];
			for( int i = 0; i < s.length(); i++ )
				c[s.charAt(i)-'a']++;
		}

		Word( char[] _c )
		{
			c = _c;
		}

		public int hashCode()
		{
			int hash = 0;
			for( int i = 0; i < 26; i++ )
			{
				hash += c[i];
				hash <<= 1;
			}
			return hash;
		}

		public boolean equals( Object obj )
		{
			Word o = (Word)obj;
			for( int i = 0; i < 26; i++ ) if( c[i] != o.c[i] ) return false;
			return true;
		}

	}

}
