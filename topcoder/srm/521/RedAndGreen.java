public class RedAndGreen
{
	public int minPaints( String s )
	{
		int n = s.length(), cnt[] = new int[n];
		if( s.charAt(0) == 'R' ) cnt[0] = 1;
		for( int i = 1; i < n; i++ ) cnt[i] = cnt[i-1] + ( s.charAt(i) == 'R' ? 1 : 0 );
		int best = cnt[n-1];
		for( int i = 0; i < n; i++ ) best = Math.min( best, ( i + 1 - cnt[i] ) + ( cnt[n-1] - cnt[i] ) );
		return best;
	}
}
