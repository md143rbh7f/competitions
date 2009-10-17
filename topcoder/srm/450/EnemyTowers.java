/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class EnemyTowers
{
	static int INF = Integer.MAX_VALUE;
	static int NINF = Integer.MIN_VALUE;

	static int MAX = 1 << 30;
	int u, hp, at, nw, ns;
	public int attack( int _u, int _hp, int _at, int _nw, int _ns )
	{
		u = _u; hp = _hp; at = _at; nw = _nw; ns = _ns;
		int D = MAX, cur = 0;
		long drounds = NINF, rounds = INF, trial[], diff;
		while( D != 0 )
		{
			if( cur+D <= u )
			{
				trial = val( cur+D );
				diff = trial[1]-trial[0];
				if( diff <= 0 && diff >= drounds )
				{
					drounds = diff;
					rounds = trial[0] > trial[1] ? trial[0] : trial[1];
					cur += D;
				}
			}
			D >>= 1;
		}
		trial = val( cur+1 );
		diff = trial[1]-trial[0];
		if( diff*diff < drounds*drounds ) rounds = trial[0] > trial[1] ? trial[0] : trial[1];
		if( rounds < INF ) return (int)rounds;
		return -1;
	}

	long[] val( int n )
	{
		long[] ans = { sim( n, nw ), sim( u-n, ns ) };
		return ans;
	}

	int sim( int n, int tow )
	{
		long hptot = (long)tow * (long)hp;
		int r = 0;
		while( hptot > 0 && n > 0 )
		{
			r++;
			hptot -= n;
			n -= (hptot+hp-1)/hp*(long)at;
		}
		if( hptot <= 0 ) return r;
		else return INF;
	}

}
