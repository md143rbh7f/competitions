/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class LuckyNumbers
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;


	public static void main( String[] args )
	{
		generate();
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new LuckyNumbers().solve( i );
	}

	boolean solve( int caseNum )
	{
		long A = in.nextLong(), B = in.nextLong();
		System.out.println( count( B + 1 ) - count( A ) );
		return true;
	}

	static long[] veryLucky;
	static int MAX = 1 << 20;

	static void generate()
	{
		int digs = 12, end = 2, count = 0, len = (1<<(digs+1))-2;
		long lucky[] = new long[len], max = 1000000000000l;

		for( int i = 1; i <= digs; i++ )
		{
			for( int j = 0; j < end; j++ )
			{
				long val = 0;
				for( int k = i-1; k >= 0; k-- )
				{
					val *= 10;
					if( ( ( j >> k ) & 1 ) == 0 ) val += 4;
					else val += 7;
				}
				lucky[len-(++count)] = val;
			}
			end <<= 1;
		}

		HashSet<Long> very = new HashSet<Long>( 500000, 1 );
		int sp = 0;
		long val[] = new long[len+1]; val[0] = 1;
		while( sp != -1 )
		{
			if( sp == len )
			{
				very.add( val[sp] );
				sp--;
			}
			else if( val[sp] < max )
			{
				val[sp+1] = val[sp];
				if( 1.0*val[sp]*lucky[sp] < max ) val[sp] *= lucky[sp];
				else val[sp] = max;
				sp++;
			}
			else sp--;
		}

		count = 0;
		veryLucky = new long[very.size()];
		for( long i : very ) veryLucky[count++] = i;
		Arrays.sort( veryLucky );
	}

	static int count( long a )
	{
		int count = 0, step = MAX;
		while( ( step >>= 1 ) != 0 )
			if( ( count + step ) < veryLucky.length && veryLucky[count+step] < a )
				count += step;
		return count - 1;
	}
}
