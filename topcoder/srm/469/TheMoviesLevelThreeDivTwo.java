import java.math.*;
import java.util.*;

public class TheMoviesLevelThreeDivTwo
{
	public int find( int[] tj, int[] tb )
	{
		int n = tj.length, t[][] = { tj, tb }, ans = 0;
		outer:
		for( int m = 1; m < (1<<n)-1; m++ )
		{
			for( int b = 0; b < 2; b++ )
			{
				int x = 0, y = 0;
				for( int i = 0; i < n; i++ ) if( (m>>i)%2 == b ) x += t[b][i];
				for( int i = 0; i < n; i++ )
				if( (m>>i)%2 != b )
				{
					y += t[1-b][i];
					if( y > x ) continue outer;
					x += t[b][i];
				}
			}
			ans++;
		}
		return ans;
	}
}
