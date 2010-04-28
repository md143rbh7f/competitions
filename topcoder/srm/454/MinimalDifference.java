import java.math.*;
import java.util.*;

public class MinimalDifference
{
	public int findNumber( int a, int b, int c )
	{
		 int s = digitSum(c), min = 1000, ans = -1, k;
		 for( int i = a; i <= b; i++ )
		 {
			k = digitSum(i);
			if( Math.abs(k-s)<min )
			{
				min = Math.abs(k-s);
				ans = i;
			}
		 }
		 return ans;
	}
	
	int digitSum( int a )
	{
		int ret = 0;
		while( a != 0 )
		{
			ret += a%10;
			a /= 10;
		}
		return ret;
	}
}
