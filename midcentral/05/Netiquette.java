/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Netiquette
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Netiquette().solve( caseNum++ ) );
	}

	char[] line;
	boolean solve( int caseNum )
	{
		line = ( " " + in.nextLine() + " " ).toCharArray();
		if( line.length == 3 && line[1] == '#' ) return false;

		for( int i = 1; i < line.length-1; i++ )
			if( !okay2( i ) || !okay3( i ) )
			{
				System.out.println( "suspicious" );
				return true;
			}

		System.out.println( "OK" );

		return true;
	}

	boolean okay2( int i )
	{
		if( isCap( line[i] ) && isCap( line[i+1] ) ) return false;
		if( isDig( line[i] ) && isLetter( line[i+1] ) ) return false;
		if( isDig( line[i+1] ) && isLetter( line[i] ) ) return false;
		if( isPuncNonQuote( line[i] ) && isPuncNonQuote( line[i+1] ) ) return false;
		return true;
	}

	boolean okay3( int i )
	{
		if( line[i-1] == ' ' && line[i+1] == ' ' && line[i] != 'a' && line[i] != 'A' && line[i] != 'I' ) return false;
		return true;
	}

	boolean isDig( char c )
	{
		return c >= '0' && c <= '9';
	}

	boolean isLetter( char c )
	{
		return isCap( c ) || ( c >= 'a' && c <= 'z' );
	}

	boolean isCap( char c )
	{
		return c >= 'A' && c <= 'Z';
	}

	boolean isPuncNonQuote( char c )
	{
		return c != '"' && c != ' ' && !isLetter( c ) && !isDig( c );
	}
}
