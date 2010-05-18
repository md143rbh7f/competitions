import java.math.*;
import java.util.*;

public class TheProduct
{
	long inf = 1l<<60;
	public long maxProduct( int[] nums, int k, int md )
	{
		int n = nums.length;
		// dp[0=max/1=min][used][index]
		long max[][] = new long[k][n], min[][] = new long[k][n], ans = -inf;
		for( int j = 0; j < n; j++ ) max[0][j] = min[0][j] = nums[j];
		for( int i = 1; i < k; i++ )
		for( int j = 0; j < n; j++ )
		{
			max[i][j] = -inf;
			min[i][j] = inf;
			for( int l = j-1; l>=0 && j-l<=md; l-- )
			{
				if( max[i-1][l]!=-inf )
				{
					max[i][j] = Math.max( max[i][j], nums[j]*max[i-1][l] );
					min[i][j] = Math.min( min[i][j], nums[j]*max[i-1][l] );
				}
				if( min[i-1][l]!=inf )
				{
					max[i][j] = Math.max( max[i][j], nums[j]*min[i-1][l] );
					min[i][j] = Math.min( min[i][j], nums[j]*min[i-1][l] );
				}
			}
		}
		for( int j = 0; j < n; j++ ) if( max[k-1][j]!=-inf ) ans = ans>max[k-1][j] ? ans : max[k-1][j];
		return ans;
	}
}
