import java.math.*;
import java.util.*;

public class TheAlmostLuckyNumbers
{
	long a, b;
	ArrayList<Long> p = new ArrayList<Long>();

	public long count( long _a, long _b )
	{
		a = _a-1; b = _b;
		for( int l = 1; l <= 10; l++ )
		for( int i = 0; i < 1<<l; i++ )
		{
			long q = 0;
			for( int j = 0; j < l; j++ )
			{
				q *= 10;
				if( (i>>j)%2==0 ) q += 4;
				else q += 7;
			}
			boolean works = true;
			if( q>b ) works = false;
			for( long qq : p ) if( q%qq==0 ) works = false;
			if( works ) p.add(q);
		}
		Collections.sort(p);
		return rec( 1, p.size(), 1 );
	}

	long rec( int coeff, int end, long val )
	{
		long ans = 0;
		for( int i = end-1; i >= 0; i-- )
		{
			long v = lcm( val, p.get(i) );
			if( v<=b ) ans += coeff*(b/v-a/v)+rec(-coeff,i,v);
		}
		return ans;
	}

	static long gcd( long a, long b )
	{
		while( b != 0 )
		{
			long t = a%b;
			a = b;
			b = t;
		}
		return a;
	}

	long lcm( long x, long y )
	{
		long z = x/gcd(x,y);
		if( z>b/y ) return b+1;
		return z*y;
	}
}
