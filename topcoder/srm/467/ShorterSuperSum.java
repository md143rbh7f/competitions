import java.math.*;
import java.util.*;

public class ShorterSuperSum
{
	public int calculate( int k, int n )
	{
		int ans = 1;
		for( int i = 0; i <= k; i++ )
		{
			ans *= n+i;
			ans /= i+1;
		}
		return ans;
	}
}
