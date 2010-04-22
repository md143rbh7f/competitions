import java.math.*;
import java.util.*;

public class RoadOrFlightEasy
{
	public int minTime( int n, int[] rt, int[] ft, int k )
	{
		boolean[] done = new boolean[n];
		int t = 0;
		for( int i = 0; i < k; i++ )
		{
			int best = 0, besti = -1;
			for( int j = 0; j < n; j++ )
			if( !done[j] && rt[j]-ft[j]>best )
			{
				best = rt[j]-ft[j];
				besti = j;
			}
			if( besti==-1 ) break;
			done[besti] = true;
			t += ft[besti];
		}
		for( int i = 0; i < n; i++ ) if( !done[i] ) t += rt[i];
		return t;
	}
}
