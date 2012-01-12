import java.util.Arrays;

public class Cut
{
	public int getMaximum( int[] lens, int cuts )
	{
		int ans = 0;
		Arrays.sort( lens );
		for( int len : lens ) if( len % 10 == 0 )
		{
			if( cuts >= len / 10 - 1 )
			{
				cuts -= len / 10 - 1;
				ans += len / 10;
			}
			else
			{
				ans += cuts;
				cuts = 0;
			}
		}
		for( int len : lens ) if( len % 10 != 0 )
		{
			if( cuts >= len / 10 )
			{
				cuts -= len / 10;
				ans += len / 10;
			}
			else
			{
				ans += cuts;
				cuts = 0;
			}
		}
		return ans;
	}
}
