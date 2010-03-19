/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class ColorfulStrings
{
	static int N = 8;
	static ArrayList<Integer>[] cache = (ArrayList<Integer>[])(new ArrayList[N+1]);
	static
	{
		for( int n = 1; n < cache.length; n++ ) cache[n] = new ArrayList<Integer>();
		for( int i = 0; i < 10; i++ ) cache[1].add(i);

		int[] nums = { 2, 3, 4, 5, 6, 7, 8, 9 };
		outer: for( int mask = 0; mask < (1<<N); mask++ )
		{
			int n = 0;
			for( int i = 0; i < N; i++ ) if( ((mask>>i)&1) == 1 ) n++;
			if( n < 2 ) continue outer;
			int nums2[] = new int[n], count = 0;
			for( int i = 0; i < N; i++ ) if( ((mask>>i)&1) == 1 ) nums2[count++] = nums[i];
			inner: do
			{
				HashSet<Integer> prodSet = new HashSet<Integer>();
				for( int i = 0; i < n; i++ ) for( int j = i; j < n; j++ )
				{
					int prod = 1;
					for( int l = i; l <= j; l++ ) prod *= nums2[l];
					if( prodSet.contains(prod) ) continue inner;
					prodSet.add(prod);
				}
				int res = 0;
				for( int i = 0; i < n; i++ ) res = 10*res+nums2[i];
				cache[n].add(res);
			}
			while( next_permutation(nums2) );
		}
		for( int i = 1; i <= N; i++ ) Collections.sort(cache[i]);
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

	public String getKth( int n, int k )
	{
		if( n > 8 || (k-1)>=cache[n].size() ) return "";
		return ""+cache[n].get(k-1);
	}
}
