import java.math.*;
import java.util.*;

public class SortingGame
{
	public int fewestMoves( int[] b, int k )
	{
		int n = b.length;
		String temp, temp2;
		HashMap<String,Integer> d = new HashMap<String,Integer>();
		LinkedList<String> q = new LinkedList<String>();
		char[] ptr = new char[n];
		for( int i = 0; i < n; i++ ) ptr[i] = (char)b[i];
		temp = new String(ptr);
		d.put( temp, 0 );
		q.add( temp );
		while( !q.isEmpty() )
		{
			temp = q.poll();
			ptr = temp.toCharArray();
			boolean works = true;
			for( int i = 1; i < n; i++ ) if( ptr[i]<ptr[i-1] ) works = false;
			if( works ) return d.get( temp );
			for( int i = 0; i<n && i+k<=n; i++ )
			{
				flip( ptr, i, i+k );
				temp2 = new String(ptr);
				if( !d.containsKey(temp2) )
				{
					d.put( temp2, d.get(temp)+1 );
					q.add( temp2 );
				}
				flip( ptr, i, i+k );
			}
		}
		return -1;
	}

	void flip( char[] perm, int i, int j )
	{
		for( int k = 0; k < (j-i)/2; k++ )
		{
			perm[i+k] ^= perm[j-k-1];
			perm[j-k-1] ^= perm[i+k];
			perm[i+k] ^= perm[j-k-1];
		}
	}
}
