import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class EasySequence
{
	int max = 1<<20;
	public int find( int[] a, int[] b )
	{
		int n = a.length, m = b.length, count = 0, s[] = new int[max];
		for( int i = 0; i < n; i++ ) s[n] += ( s[i] = a[i] );
		s[n] %= 10;
		for( int i = n+1; i < max; i++ ) s[i] = (2*s[i-1]-s[i-n-1]+10)%10;
		outer: for( int i = 0; i < max-m; i++ )
		{
			for( int j = 0; j < m; j++ )
				if( s[i+j] != b[j] )
					continue outer;
			return i;
		}
		return -1;
	}
}
