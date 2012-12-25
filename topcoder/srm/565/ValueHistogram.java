public class ValueHistogram
{
	int N = 10;

	public String[] build( int[] values )
	{
		int[] cnt = new int[N];
		for( int v : values ) cnt[v]++;
		int top = 0;
		for( int c : cnt ) top = Math.max( top, c + 1 );
		String[] ans = new String[top];
		for( int i = 0; i < top; i++ )
		{
			ans[i] = "";
			for( int j = 0; j < N; j++ )
				ans[i] += cnt[j] >= top - i ? 'X' : '.';
		}
		return ans;
	}
}
