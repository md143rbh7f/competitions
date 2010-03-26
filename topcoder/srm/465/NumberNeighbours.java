/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class NumberNeighbours
{
	static int pow = 7;
	public int numPairs( int[] ns )
	{
		int n = ns.length;
		HashMap<Integer,Integer> count = new HashMap<Integer,Integer>();
		for( int i = 0; i < n; i++ )
		{
			int num = n[i];
			int[] canon = new int[9];
			for( int j = 0; j < pow; j++ )
			{
				if( num%10 != 0 ) canon[num%10]++;
				num /= 10;
			}
			int c = 0;
			for( int j = 0; j < 10; j++ )
			{
				c *= 10;
				c += canon[j];
			}
			if( !count.containsKey(c) ) count.put(c,0);
			count.put(c,count.get(c)+1);
		}
		int res = 0;
		for( int i : count.keySet() ) res += count.get(i)*(count.get(i)-1)/2;
		return res;
	}
}
