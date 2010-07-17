import java.util.*;

public class Badgers
{
	public int feedMost( int[] hunger, int[] greed, int totalFood )
	{
		int best = 0, n = hunger.length, req[] = new int[n];
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 0; j < n; j++ ) req[j] = hunger[j]+greed[j]*(i-1);
			Arrays.sort( req );
			int need = 0;
			for( int j = 0; j < i; j++ ) need += req[j];
			if( need > totalFood ) break;
			best = i;
		}
		return best;
	}
}
