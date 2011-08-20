public class FortunateNumbers
{
	public int getFortunate( int[] a, int[] b, int[] c )
	{
		boolean seen[] = new boolean[90001];
		int ans = 0;
		for( int i : a ) for( int j : b ) for( int k : c )
		{
			int s = i + j + k;
			boolean ok = true;
			for( int t = s; t > 0; t /= 10 ) if( ( t%10 != 5 ) && ( t %10 != 8 ) ) ok = false;
			if( ok && !seen[s] )
			{
				ans++;
				seen[s] = true;
			}
		}
		return ans;
	}
}
