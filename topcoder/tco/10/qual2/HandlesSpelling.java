import java.math.*;
import java.util.*;

public class HandlesSpelling
{
	public int spellIt( String[] parts, String[] b )
	{
		int n = 0, m = b.length;
		for( String i : parts ) n += i.length();
		char[] s = new char[n];
		int temp = 0;
		for( int i = 0; i < parts.length; i++ )
		{
			char[] t = parts[i].toCharArray();
			for( int j = 0; j < t.length; j++ ) s[temp+j] = t[j];
			temp += parts[i].length();
		}
		boolean[][] g = new boolean[n][n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			int o = b[j].length();
			if( i+o<=n )
			{
				boolean works = true;
				for( int k = 0; k < o; k++ ) if( s[i+k] != b[j].charAt(k) ) works = false;
				if( works ) g[i][i+o-1] = true;
			}
		}
		int[][] dp = new int[n][n];
		for( int d = 0; d < n; d++ ) for( int i = 0; i+d < n; i++ )
		{
			int j = i+d;
			if( i<j ) dp[i][j] = Math.max( dp[i][j-1], dp[i+1][j] );
			if( g[i][j] ) dp[i][j] = j-i+1;
			for( int k = 0; k < m; k++ )
			{
				int l = b[k].length();
				if( l <= d )
				{
					if( g[i][i+l-1] ) dp[i][j] = Math.max( dp[i][j], l+dp[i+l][j] );
					if( g[j-l+1][j] ) dp[i][j] = Math.max( dp[i][j], l+dp[i][j-l] );
				}
			}
		}
		int ans = -n;
		for( int i = 0; i < n; i++ ) for( int j = i; j < n; j++ )
		{
			int A = dp[i][j];
			if( A==j-i+1 )
			{
				int B = n - ( A + (i==0?0:dp[0][i-1]) + (j==n-1?0:dp[j+1][n-1]) );
				ans = Math.max( ans, A*A-B );
			}
		}
		return ans;
	}
}
