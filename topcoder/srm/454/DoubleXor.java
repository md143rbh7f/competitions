import java.math.*;
import java.util.*;

public class DoubleXor
{
	public int calculate( int n )
	{
		int[] res = new int[7];
		while( n != 0 )
		{
			int temp = n;
			for( int i = 0; i < 7; i++ )
			{
				res[i] = (res[i]^(temp%10))%10;
				temp /= 10;
			}
			n--;
		}
		int ans = 0;
		for( int i = 6; i >= 0; i-- ) ans = 10*ans+res[i];
		return ans;
	}
}
