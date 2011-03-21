import java.io.*;
import java.math.*;
import java.util.*;

public class NumberPyramids
{
	static int mod = 1000000009;
	public int count( int n, int top )
	{
		int pow = 0;
		for( int i = top; i > 0; i >>= 1 ) pow++;
		if( pow < n ) return 0;
		top -= 1<<(n-1);
		int[] coeffs = new int[n];
		coeffs[0] = 1;
		for( int i = 1; i < n; i++ ) coeffs[i] = (coeffs[i-1]*(n-i))/i;
		int[] dp = new int[top+1];
		dp[0] = 1;
		for( int i = 0; i < n; i++ )
			for( int j = coeffs[i]; j <= top; j++ )
				dp[j] = (dp[j]+dp[j-coeffs[i]])%mod;
		return dp[top];
	}
}
