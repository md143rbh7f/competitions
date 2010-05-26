public class PrimeSequences
{
	public int getLargestGenerator( int N, int D )
	{
		int[] len = new int[N+1];
		len[0] = len[1] = 0;
		for( int i = 2; i <= N; i++ ) len[i] = 1;
		for( int i = 2; i <= N; i++ )
		{
			if( len[i]!=0 )
			{
				for( int j = 2*i; j <= N; j += i ) len[j] = 0;
				len[i] = len[i/2]+1;
			}
		}
		int ans = N;
		while( ans>=0 && len[ans]<D ) ans--;
		return ans;
	}
}
