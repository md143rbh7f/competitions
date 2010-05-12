import java.math.*;
import java.util.*;

public class JingleRingle
{
	public int profit( int[] buy, int[] sell, int tax )
	{
		Arrays.sort( buy );
		Arrays.sort( sell );
		int n = Math.min( buy.length, sell.length ), profit[] = new int[n+1], ans = 0;
		for( int i = 0; i < n; i++ )
		{
			int j = buy.length-i-1;
			profit[i+1] = profit[i]-sell[i]+buy[j]-(buy[j]*tax)/100;
			ans = Math.max( ans, profit[i+1] );
		}
		return ans;
	}
}
