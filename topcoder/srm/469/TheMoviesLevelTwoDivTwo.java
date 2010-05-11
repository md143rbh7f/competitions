import java.math.*;
import java.util.*;

public class TheMoviesLevelTwoDivTwo
{
	public int[] find( int[] len, int[] scary )
	{
		int n = len.length, perm[] = new int[n], best[] = new int[n], besttot = -1;
		for( int i = 0; i < n; i++ ) perm[i] = i;
		do
		{
			int tot = 0, sleep = 74;
			for( ; tot < n; tot++ )
			{
				int c = perm[tot];
				sleep -= scary[c];
				if( sleep < 0 ) break;
				sleep += 47;
				sleep -= len[c]-scary[c];
				if( sleep < 0 ) break;
			}
			if( tot > besttot )
			{
				for( int i = 0; i < n; i++ ) best[i] = perm[i];
				besttot = tot;
			}
		}
		while( next_permutation(perm) );
		return best;
	}

	static boolean next_permutation( int[] perm )
	{
		int n = perm.length;
		int inc = -1;
		for( int i = 0; i < n-1; i++ ) if( perm[i] < perm[i+1] ) inc = i;
		if( inc != -1 )
		{
			int inc_val = perm[inc];
			perm[inc] = Integer.MAX_VALUE;
			int min_ptr = inc;
			for( int i = inc + 1; i < n; i++ ) if( perm[i] < perm[min_ptr] && perm[i] > inc_val ) min_ptr = i;
			if( min_ptr == -1 ) min_ptr = inc;
			perm[inc] = perm[min_ptr];
			perm[min_ptr] = inc_val;
		}
		Arrays.sort( perm, inc + 1, n );
		return inc == -1 ? false : true;
	}
}
