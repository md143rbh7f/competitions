/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class LotteryCheating
{
	public int minimalChange( String id )
	{
		int maxd = id.length(), min = maxd, dist;
		long start = Long.parseLong(id), sq, temp, max = 1;
		for( int i = 0; i < maxd; i++ ) max *= 10;
		for( int i = 0; i < 100000; i++ )
		{
			sq = (long)i*i;
			if( sq >= max ) break;
			temp = start;
			dist = 0;
			for( int j = 0; j < maxd; j++ )
			{
				if( temp%10 != sq%10 ) dist++;
				temp /= 10;
				sq /= 10;
			}
			if( dist < min ) min = dist;
		}
		return min;
	}
}
