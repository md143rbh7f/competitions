import java.math.*;
import java.util.*;

public class SuperSum
{
	BigInteger mod = new BigInteger( "1000000007" );
	public int calculate( int K, int N )
	{
		BigInteger n = new BigInteger(""+N);
		BigInteger ans = BigInteger.ONE, denom = BigInteger.ONE;
		for( int i = 0; i <= K; i++ )
		{
			ans = ans.multiply(n);
			n = n.add(BigInteger.ONE);
		}
		for( int i = 0; i <= K; i++ )
		{
			ans = ans.divide(denom);
			denom = denom.add(BigInteger.ONE);
		}
		ans = ans.mod( mod );
		return ans.intValue();
	}
}
