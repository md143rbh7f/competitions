import java.util.*;

public class EllysNumbers
{
	public long getSubsets( long n, String[] _special )
	{
		String tmp = "";
		for( String s : _special ) tmp += s;
		String tmp2[] = tmp.split(" ");
		HashSet<Integer> special = new HashSet<Integer>();
		for( String s : tmp2 ) special.add( Integer.parseInt( s ) );

		boolean containsOne = special.contains(1);
		if( containsOne ) special.remove(1);

		// factors <= prime factors of all special numbers
		TreeSet<Integer> factors = new TreeSet<Integer>();
		for( int s : special )
		{
			for( long i = 2; i * i <= s; i++ ) if( s % i == 0 )
			{
				factors.add( (int) i );
				while( s % i == 0 ) s /= i;
			}
			if( s != 1 ) factors.add( s );
		}

		// decompose n in terms of factors of special numbers
		long nn = n;
		HashMap<Integer,Integer> nPow = new HashMap<Integer,Integer>();
		for( int f : factors ) if( nn % f == 0 )
		{
			int pow = 0;
			while( nn % f == 0 )
			{
				nn /= f;
				pow++;
			}
			nPow.put( f, pow );
		}
		if( nn != 1 ) return 0;
		
		// factors <= prime factors of n
		TreeSet<Integer> factors2 = new TreeSet<Integer>();
		for( int f : factors ) if( nPow.containsKey(f) ) factors2.add(f);
		factors = factors2;

		// special <= valid special numbers
		HashSet<Integer> special2 = new HashSet<Integer>();
		for( int ss : special )
		{
			HashMap<Integer,Integer> sPow = new HashMap<Integer,Integer>();
			int s = ss;
			for( int f : factors ) if( s % f == 0 )
			{
				int pow = 0;
				while( s % f == 0 )
				{
					s /= f;
					pow++;
				}
				sPow.put( f, pow );
			}
			if( s != 1 ) continue;
			boolean ok = true;
			for( int f : sPow.keySet() ) if( sPow.get(f) != nPow.get(f) ) ok = false;
			if( ok ) special2.add(ss);
		}
		special = special2;

		// do dp
		int l = factors.size(), L = 1<<l;

		long dp[] = new long[L];
		ArrayList<Integer> codes = new ArrayList<Integer>();
		for( int s : special )
		{
			int mask = 0, index = 0;
			for( int f : factors )
			{
				if( s % f == 0 ) mask |= 1 << index;
				index++;
			}
			codes.add( mask );
		}

		dp[0] = containsOne ? 2 : 1;
		for( int code : codes ) for( int i = code; i < L; i = (i+1)|code ) dp[i] += dp[i-code];

		return dp[L-1];
	}
}
