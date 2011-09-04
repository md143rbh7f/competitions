/*
	AxiomOfChoice
 */

import java.math.*;
import java.util.*;

public class MatrixGame
{
	public String[] getMinimal( String[] matrix )
	{
		int n = matrix.length, m = matrix[0].length(), cols[] = new int[m], buf[] = new int[n], min[] = new int[n];
		for( int j = 0; j < m; j++ ) cols[j] = j;
		for( int i = 0; i < n; i++ ) min[i] = (1<<8)-1;
		outer: do
		{
			for( int i = 0; i < n; i++ )
			{
				buf[i] = 0;
				for( int j = 0; j < m; j++ ) buf[i] |= (matrix[i].charAt(cols[j])-'0')<<j;
			}
			Arrays.sort( buf );
			for( int i = 0; i < n; i++ )
			if( buf[i] != min[i] )
			{
				if( buf[i] < min[i] ) for( int j = 0; j < n; j++ ) min[j] = buf[j];
				continue outer;
			}
		}
		while( next_permutation( cols ) );
		String[] ret = new String[n];
		for( int i = 0; i < n; i++ )
		{
			ret[i] = "";
			for( int j = m-1; j >= 0; j-- ) ret[i] += (min[i]>>j)&1;
		}
		return ret;
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
