import java.io.*;
import java.math.*;
import java.util.*;

public class Palindrometer
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	
	static int palin( int a, int l, int mid )
	{
		int res = a, tmp = a;
		if( l%2==1 ) res = res*10+mid;
		for( int i = 0; i < l/2; i++ )
		{
			res = res*10+tmp%10;
			tmp /= 10;
		}
		return res;
	}

	public static void main( String[] args )
	{
		while(true)
		{
			String s = in.next().trim();
			if(s.equals("0")) break;
			int n = s.length(), a = Integer.parseInt(s), m = 1;
			for( int i = 0; i < n/2; i++ ) m *= 10;
			int best = 1<<30;
			for( int i = 0; i < m; i++ )
			{
				if( n%2==0 )
				{
					int p = palin( i, n, 0 );
					if( p >= a ) best = Math.min( best, p-a );
				}
				else for( int j = 0; j < 10; j++ )
				{
					int p = palin( i, n, j );
					if( p >= a ) best = Math.min( best, p-a );
				}
			}
			System.out.println( best );
		}
	}
}
