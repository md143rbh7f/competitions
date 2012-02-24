import java.util.*;

public class RoyalTreasurer
{
	public int minimalArrangement( int[] a, int[] b )
	{
		Arrays.sort(a);
		Arrays.sort(b);
		int ans = 0;
		for( int i = 0; i < a.length; i++ ) ans += b[i] * a[a.length-i-1];
		return ans;
	}
}
