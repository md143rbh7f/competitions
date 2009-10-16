/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Rag
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		generate();
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Rag().solve( i );
	}

	void solve( int caseNum )
	{
		int r = in.nextInt();
		System.out.println( caseNum + " " + r + " " + pow[r] );
	}

	static final BigInteger MAX = new BigInteger( "100000000000000000000" );
    static final BigInteger ONE = BigInteger.ONE;
    static final BigInteger TWO = BigInteger.valueOf(2);
    static final BigInteger FOUR = BigInteger.valueOf(4);
    static final BigInteger FIVE = BigInteger.valueOf(5);
    static final BigInteger TEN = BigInteger.TEN;
	
	static BigInteger[] pow2 = new BigInteger[50];
	static BigInteger[] pow = new BigInteger[21];

	static void generate()
	{
		pow2[0] = TWO;
        for( int i = 1; i < pow2.length; i++ )
			pow2[i] = pow2[i-1].multiply( pow2[i-1] ).mod( MAX );

        pow[1] = ONE;
        BigInteger d = FOUR,
			k = pow[1].add( d ),
			val = BigInteger.valueOf( 32 );
        for( int i = 2; i < 21; i++ )
		{
            while( !works( val, i ) )
			{
                k = k.add(d);
                val = getPow(k);
            }
            pow[i] = k;
            d = d.multiply(FIVE);
        }
	}

	static boolean works( BigInteger val, int d )
	{
        for( ; d > 0; d--)
		{
            int dig = val.mod( TEN ).intValue();
            if( dig != 1 && dig != 2 ) return false;
            val = val.divide(TEN);
        }
        return true;
	}

    static BigInteger getPow( BigInteger n )
	{
        BigInteger ans = ONE;
        for( int i = 0; i <= n.bitLength(); i++ )
			if( n.testBit(i) )
				ans = ans.multiply( pow2[i] ).mod( MAX );
        return ans;
    }
}
