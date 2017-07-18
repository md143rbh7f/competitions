/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class WSCipher
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new WSCipher().solve( caseNum++ ) );
	}

	static final char[] range = { 'a', 'j', 's', 128 };
	boolean solve( int caseNum )
	{
		int k[] = { in.nextInt(), in.nextInt(), in.nextInt() };
		if( k[0] == k[1] && k[1] == k[2] && k[2] == 0 ) return false;

		char[] enc = in.next().toCharArray(), dec = new char[enc.length];
		for( int i = 0; i < enc.length; i++ ) if( enc[i] == '_' ) enc[i] = '~';
		int buf[] = new int[enc.length], count;
		for( int i = 0; i < 3; i++ )
		{
			count = 0;
			for( int j = 0; j < enc.length; j++ )
				if( enc[j] >= range[i] && enc[j] < range[i+1] )
					buf[count++] = j;
			for( int j = 0; j < count; j++ )
				dec[buf[j]] = enc[buf[(j+(k[i]/count+1)*count-k[i])%count]];
		}
		for( int i = 0; i < enc.length; i++ ) if( dec[i] == '~' ) dec[i] = '_';
		System.out.println( new String( dec ) );
		return true;
	}
}
