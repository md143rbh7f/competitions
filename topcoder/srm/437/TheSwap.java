import java.math.*;
import java.util.*;

public class TheSwap
{
	public int findMax( int n, int k )
	{
		TreeSet<Integer>[] res = (TreeSet<Integer>[])(new TreeSet[k+1]);
		for( int t = 0; t <= k; t++ ) res[t] = new TreeSet<Integer>();
		res[0].add(n);
		for( int t = 0; t < k; t++ ) for( int r : res[t] )
		{
			char[] N = (""+r).toCharArray();
			for( int i = 0; i < N.length; i++ ) for( int j = i+1; j < N.length; j++ )
			if( i!=0 || N[j]!='0' )
			{
				N[i] ^= N[j]; N[j] ^= N[i]; N[i] ^= N[j];
				res[t+1].add( Integer.parseInt( new String(N) ) );
				N[i] ^= N[j]; N[j] ^= N[i]; N[i] ^= N[j];
			}
		}
		if( res[k].size()==0 ) return -1;
		return res[k].last();
	}
}
