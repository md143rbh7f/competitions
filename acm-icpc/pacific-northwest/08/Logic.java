/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Logic
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Logic().solve( caseNum++ ) );
	}

	static char[] chars = { 'C', 'N', 'K', 'A', 'D', 'E', 'J' };
	static int[][] f =
	{
		{ 1, 1, 0, 1 }, // C
		{ 1, 0, 1, 0 }, // N
		{ 0, 0, 0, 1 }, // K
		{ 0, 1, 1, 1 }, // A
		{ 1, 1, 1, 0 }, // D
		{ 1, 0, 0, 1 }, // E
		{ 0, 1, 1, 0 }, // J
	};
	static HashMap<Character,Integer> fMap = new HashMap<Character,Integer>();
	static
	{
		for( int i = 0; i < f.length; i++ )
			fMap.put( chars[i], i );
	}

	String line;
	boolean solve( int caseNum )
	{
		line = in.nextLine();
		int n = line.length();
		if( n == 0 ) return false;

		for( int i = 0; i < line.length(); i++ )
		{
			char c = line.charAt(i);
			if( !( isUp(c) || isLow(c) ) )
			{
				System.out.printf( "%s is invalid: invalid character\n", line );
				return true;
			}
			if( c == 'N' ) n++;
		}

		char[] l = new char[n];
		int z = 0;
		for( int i = 0; i < line.length(); i++ )
		{
			l[z] = line.charAt(i);
			if( l[z] == 'N' ) z++;
			z++;
		}

		if( !valid( l ) ) return true;

		HashMap<Character,Integer> id = new HashMap<Character,Integer>();
		int nextId = 1;
		for( int i = 0; i < n; i++ )
		{
			if( isLow(l[i]) )
			{
				if( !id.containsKey(l[i]) )
					id.put( l[i], nextId++ );
				l[i] = (char)(int)id.get(l[i]);
			}
			else if( l[i]!=0 ) l[i] = (char)(32+(int)fMap.get(l[i]));
		}

		int num = 1 << nextId;
		int stack[] = new int[256];
		int sp = 0;
		boolean wasTrue = false, wasFalse = false;
		for( int i = 0; i < num; i += 2 )
		{
			for( int j = n-1; j >= 0; j-- )
			{
				if( l[j] < 32 ) stack[sp++] = ( i >> l[j] ) & 1;
				else
				{
					stack[sp-2] = f[l[j]-32][2*stack[sp-1]+stack[sp-2]];
					sp--;
				}
			}
			sp = 0;
			if( stack[0] == 1 ) wasTrue = true;
			else wasFalse = true;
			if( wasFalse && wasTrue )
			{
				System.out.printf( "%s is valid: contingent\n", line );
				return true;
			}
		}
		if( wasFalse ) System.out.printf( "%s is valid: contradiction\n", line );
		else System.out.printf( "%s is valid: tautology\n", line );

		return true;
	}

	boolean valid( char[] l )
	{
		int sp = 0;
		boolean done[] = new boolean[512];
		done[0] = true;
		for( int i = 0; i < l.length; i++ )
		{
			if( isUp( l[i] ) ) sp++;
			else
			{
				while( done[sp] )
				{
					done[sp] = false;
					sp--;
					if( sp < 0 )
					{
						if( i < l.length-1 )
						{
							System.out.printf( "%s is invalid: extraneous text\n", line );
							return false;
						}
						else return true;
					}
				}
				if( !done[sp] ) done[sp] = true;
			}
		}
		System.out.printf( "%s is invalid: insufficient operands\n", line );
		return false;
	}

	boolean isUp( char a )
	{
		return fMap.containsKey( a );
	}

	boolean isLow( char a )
	{
		return a >= 'a' && a <= 'z';
	}
}
