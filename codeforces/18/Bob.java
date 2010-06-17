import java.io.*;
import java.math.*;
import java.util.*;

public class Bob
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	static int SPACE_ODYSSEY = 2001;
	public static void main( String[] args )
	{
		int n = in.nextInt(), w[] = new int[SPACE_ODYSSEY], s[] = new int[SPACE_ODYSSEY], pow = 0;
		boolean taken[] = new boolean[n+1];
		ArrayList<Integer> can = new ArrayList<Integer>();
		BigInteger ans = BigInteger.ZERO, step = BigInteger.ONE;
		for( int i = 1; i <= n; i++ )
		{
			String a = in.next();
			int o = in.nextInt();
			if( a.charAt(0)=='w' )
			{
				if( s[o]==0 ) w[o] = i;
			}
			else s[o] = i;
		}
		for( int i = SPACE_ODYSSEY-1; i >= 0; i-- ) if( w[i]>0 && w[i]<s[i] )
		{
			boolean works = true;
			for( int j = w[i]; j <= s[i]; j++ ) if( taken[j] ) works = false;
			if( works )
			{
				for( int j = w[i]; j <= s[i]; j++ ) taken[j] = true;
				can.add(i);
			}
		}
		Collections.sort(can);
		for( int a : can )
		{
			while( pow < a )
			{
				step = step.shiftLeft(1);
				pow++;
			}
			ans = ans.add(step);
		}
		System.out.println( ans );
	}
}
