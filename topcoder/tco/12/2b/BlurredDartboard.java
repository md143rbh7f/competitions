public class BlurredDartboard
{
	public int minThrows( int[] pts, int p )
	{
		int n = pts.length, max = 0, tot = n * ( n + 1 ) / 2, k = 0;
		boolean[] known = new boolean[n+1];
		for( int pt : pts ) if( pt > 0 )
		{
			tot -= pt;
			known[pt] = true;
			k++;
			if( pt > max ) max = pt;
		}
		
		int ans0 = max > 0 ? ( p + max - 1 ) / max : 1<<30; // only use known
		if( tot == 0 ) return ans0;
		
		int x = p / tot * ( n - k ), y = 0, q = p % tot, tmp = 0;
		for( int i = 1; tmp < q; i++ ) if( !known[i] )
		{
			tmp += i;
			y++;
		}
		int ans1 = x + y; // only use unknown
		if( max == 0 ) return ans1;
		
		int ans2 = x + ( q + max - 1 ) / max; // use both

		return Math.min( Math.min( ans0, ans1 ), ans2 );
	}
}
