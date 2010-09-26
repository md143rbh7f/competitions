import java.io.*;
import java.math.*;
import java.util.*;

public class JBC
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new JBC().solve( caseNum++ ) );
	}

	HashMap<Character,BigInteger> dict = new HashMap<Character,BigInteger>();

	BigInteger eval( int base, char q[] )
	{
		BigInteger coeff = BigInteger.ONE, ans = BigInteger.ZERO, b = new BigInteger(""+base);
		for( int i = q.length-1; i >= 0; i-- )
		{
			if( dict.get(q[i]).compareTo(b) >= 0 ) return BigInteger.ZERO;
			ans = ans.add(coeff.multiply(dict.get(q[i])));
			coeff = coeff.multiply(b);
		}
		return ans;
	}

	boolean solve( int caseNum )
	{
		if( !in.hasNextLine() ) return false;
		String base = in.nextLine().trim();
		int max = base.length();
		if( max==0 ) return true;
		for( int i = 0; i < max; i++ ) dict.put( base.charAt(i), new BigInteger(""+i) );
		while( true )
		{
			if( !in.hasNextLine() ) break;
			char q[] = in.nextLine().trim().toCharArray();
			if( q.length==0 ) break;
			BigInteger res = BigInteger.ZERO;
			for( int i = 2; i <= max; i++ ) res = res.add( eval( i, q ) );
			System.out.println( res );
		}
		if( in.hasNextLine() ) System.out.println();
		return true;
	}
}
