/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Gnome
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		System.out.println( "Gnomes:" );
		for( int i = 1; i <= c; i++ ) new Gnome().solve( i );
	}

	void solve( int caseNum )
	{
		int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
		if( ( a <= b && b <= c ) || ( a >= b && b >= c ) ) System.out.println( "Ordered" );
		else System.out.println( "Unordered" );
	}
}
