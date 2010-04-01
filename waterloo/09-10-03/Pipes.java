/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Pipes
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Pipes().solve( caseNum++ ) );
	}

	static int N=1<<0, E=1<<1, S=1<<2, W=1<<3, U=15,
	pos[][] =
	{
		{},
		{ N, E, S, W },
		{ N|E, E|S, S|W, W|N },
		{ U-N, U-E, U-S, U-W },
		{ U },
	};

	int mx, my, n, deg[], mask[], rot[];

	boolean solve( int caseNum )
	{
		my = in.nextInt();
		mx = in.nextInt();
		n = mx*my;
		if( n == 0 ) return false;
		deg = new int[n]; mask = new int[n];
		for( int i = 0; i < n; i++ )
		{
			String desc = in.next();
			if( !desc.equals("x") ) deg[i] = desc.length();
		}
		int ptr = 0;
		if( works(0) ) System.out.println( "SOLVABLE" );
		else System.out.println( "UNSOLVABLE" );
		return true;
	}

	boolean works( int x )
	{
		if( x==n ) return true;
		if( deg[x] == 0 ) return works(x+1);
		boolean no = x>=mx && (mask[x-mx]&S)==S;
		boolean we = x%mx!=0 && (mask[x-1]&E)==E;
		boolean so = x+mx<n && deg[x+mx]!=0;
		boolean ea = x%mx!=mx-1 && deg[x+1]!=0;
		for( int i = 0; i < pos[deg[x]].length; i++ )
		{
			int m = pos[deg[x]][i];
			if(
				(!no&&((m&N)==N)) || (no&&((m&N)==0)) ||
				(!we&&((m&W)==W)) || (we&&((m&W)==0)) ||
				(!so&&((m&S)==S)) ||
				(!ea&&((m&E)==E))
				)
				continue;
			mask[x] = m;
			if( works(x+1) ) return true;
		}
		return false;
	}
}
