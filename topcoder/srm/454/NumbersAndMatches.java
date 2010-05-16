import java.math.*;
import java.util.*;

public class NumbersAndMatches
{
	static int
	max = 126,
	have[] = new int[10],
	move[][] = new int[10][10],
	shape[][] =
	{
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 0, 0, 0 },
		{ 1, 1, 0, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 0, 0, 1 },
		{ 0, 1, 1, 0, 0, 1, 1 },
		{ 1, 0, 1, 1, 0, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1 },
	};
	static
	{
		for( int i = 0; i < 10; i++ )
		for( int k = 0; k < 7; k++ )
		if( shape[i][k]==1 )
			have[i]++;
		for( int i = 0; i < 10; i++ ) for( int j = 0; j < 10; j++ )
		for( int k = 0; k < 7; k++ )
		if( shape[i][k]!=shape[j][k] )
			move[i][j]++;
	}

	public long differentNumbers( long n, int k )
	{
		k *= 2;
		String N = ""+n;
		int l = N.length(), nums[] = new int[l], start = 0;
		for( int i = 0; i < l; i++ ) start += have[(nums[i]=N.charAt(i)-'0')];
		long dp[][][] = new long[l+1][k+1][max+1], ans = 0;
		dp[0][0][start] = 1;
		for( int i = 0; i < l; i++ )
		for( int d = 0; d <= k; d++ )
		for( int s = 0; s <= max; s++ )
		for( int dig = 0; dig < 10; dig++ )
		{
			int dd = d+move[nums[i]][dig], ss = s-have[nums[i]]+have[dig];
			if( dd<=k && ss>=0 && ss<=max ) dp[i+1][dd][ss] += dp[i][d][s];
		}
		for( int d = 0; d <= k; d++ ) ans += dp[l][d][start];
		return ans;
	}
}
