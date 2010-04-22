import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class TheHexagonsDivTwo
{
	public long count( int n, int k )
	{
		int[] count = new int[k];
		for( int i = 1; i <= n; i++ ) count[i%k]++;

		long ans = 0, add;
		int[] r = new int[6], num = new int[k];
		boolean works;
		for( int c = 0; c < k; c++ )
		{
			for( int i = 0; i < 6; i++ ) r[i] = 0;
			outer: while( true )
			{
				works = true;
				for( int i = 0; i < 6; i++ ) if( r[i]==c || r[i]==r[(i+1)%6] ) works = false;
				if( works )
				{
					for( int i = 0; i < k; i++ ) num[i] = 0;
					for( int i = 0; i < 6; i++ ) num[r[i]]++;
					add = count[c];
					for( int i = 0; i < 6; i++ ) add *= 1+count[r[i]]-(num[r[i]]--);
					ans += add;
				}
				int ptr = 0;
				while( r[ptr] == k-1 )
				{
					r[ptr] = 0;
					ptr++;
					if( ptr == 6 ) break outer;
				}
				r[ptr]++;
			}
		}

		return ans/6;
	}
}
