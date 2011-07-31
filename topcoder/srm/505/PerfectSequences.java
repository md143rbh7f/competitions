import java.math.BigInteger;

public class PerfectSequences
{
	public String fixIt( int[] s )
	{
		int n = s.length;
		if( n == 1 ) return "Yes";
		for( int i = 0; i < n; i++ )
		{
			boolean ok = true;
			BigInteger sum = BigInteger.ZERO, prod = BigInteger.ONE;
			for( int j = 0; j < n; j++ ) if( j != i )
			{
				if( s[j] < 0 || s[j] > n ) ok = false;
				BigInteger x = new BigInteger( "" + s[j] );
				sum = sum.add( x );
				prod = prod.multiply( x );
			}
			if( !ok ) continue;
			for( int j = 0; j <= n; j++ ) if( j != s[i] )
			{
				BigInteger x = new BigInteger( "" + j );
				if( prod.multiply( x ).compareTo( sum.add( x ) ) == 0 ) return "Yes";
			}
		}
		return "No";
	}
}
