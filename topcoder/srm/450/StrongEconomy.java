/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class StrongEconomy
{
	public long earn( long n, long k, long p, long t )
	{
		if( n >= (t-1)/k+1 ) return 1;
		long d = 0, have = 0, ans = Long.MAX_VALUE, rate;
		while( ( rate = n*k ) < t-have )
		{
			ans = Math.min( ans, d+(t-have-1)/rate+1 );
			if( have < p )
			{
				long upgr = (p-have-1)/rate+1;
				d += upgr;
				have += upgr*rate;
			}
			have -= p;
			if( n < k ) n++; else k++;
		}
		return Math.min( ans, d+1 );
	}
}
