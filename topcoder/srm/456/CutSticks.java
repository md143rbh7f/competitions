import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class CutSticks
{
	public double maxKth( int[] l, int c, int k )
	{
		sort(l);
		int n = l.length;
		double d = 1l<<32, best = 0;
		while( (d/=2) != 0 )
		{
			double test = best+d;
			int i = n-1;
			long can = 0;
			while( i>=0 && l[i]>=test ) can += l[i--]/test;
			if( can>=k && (n-i-1)+c>=k ) best = test;
		}
		return best;
	}
}
