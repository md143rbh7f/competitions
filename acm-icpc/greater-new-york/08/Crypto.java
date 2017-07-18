/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Crypto
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		in.nextLine();
		for( int i = 1; i <= c; i++ ) new Crypto().solve( i );
	}

	void solve( int caseNum )
	{
		char[] old = in.nextLine().toCharArray();
		String codecString = in.nextLine();
		char[] codec = new char[26];
		for( int i = 0; i < 26; i++ ) codec[i] = codecString.charAt( i );
		for( int i = 0; i < old.length; i++ ) if( old[i] != ' ' ) old[i] = codec[old[i]-'A'];
		System.out.println( caseNum + " " + new String( old ) );
	}
}
