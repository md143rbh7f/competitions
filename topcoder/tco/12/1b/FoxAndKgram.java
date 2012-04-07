public class FoxAndKgram
{
	int N = 50;
	
	public int maxK( int[] len )
	{
		int[] cnt = new int[N+1];
		for( int l : len ) cnt[l]++;
		for( int k = N; k > 0; k-- )
		{
			int tot = 0;
			for( int i = 1; i < k - 1; i++ ) tot += Math.min( cnt[i], cnt[k-1-i] );
			tot = tot / 2 + cnt[k];
			if( tot >= k ) return k;
		}
		return 0;
	}
}
