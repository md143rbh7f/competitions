/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class DuLL
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new DuLL().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt(); if( n==0 ) return false;
		int p = in.nextInt(), s = in.nextInt();

		int[] ds = new int[n], ps = new int[p];
		LinkedList<Integer>[] dep = (LinkedList<Integer>[])(new LinkedList[p]);
		for( int i = 0; i < n; i++ ) ds[i] = in.nextInt();
		for( int i = 0; i < p; i++ )
		{
			ps[i] = in.nextInt();
			dep[i] = new LinkedList<Integer>();
			String deps = in.next();
			for( int j = 0; j < deps.length(); j++ ) dep[i].add( deps.charAt(j)-'A' );
		}

		int need[] = new int[n], max = 0, size = 0, copies[] = new int[p], cmd;
		for( int i = 0; i < s; i++ )
		{
			cmd = in.nextInt();
			if( cmd > 0 )
			{
				cmd--;
				if( copies[cmd] == 0 ) for( int dll : dep[cmd] )
				{
					if( need[dll] == 0 ) size += ds[dll];
					need[dll]++;
				}
				size += ps[cmd];
				copies[cmd]++;
			}
			else
			{
				cmd = -1-cmd;
				copies[cmd]--;
				size -= ps[cmd];
				if( copies[cmd] == 0 ) for( int dll : dep[cmd] )
				{
					need[dll]--;
					if( need[dll] == 0 ) size -= ds[dll];
				}
			}
			if( size > max ) max = size;
		}
		System.out.println( max );

		return true;
	}
}
