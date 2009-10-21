/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class MagicalSource
{
	static int INF = 0x3fffffff;

	static long[] bases;
	static
	{
		bases = new long[12];
		bases[0] = 1;
		for( int i = 1; i < bases.length; i++ )
			bases[i] = 10*bases[i-1]+1;
	}

	public long calculate( long x )
	{
		long min = x;
		for( int i = 1; i < bases.length; i++ )
		{
			long test = x/bases[i];
			if( test * bases[i] == x ) min = test;
		}
		return min;
	}
}
