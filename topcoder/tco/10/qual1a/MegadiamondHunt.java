import java.math.*;
import java.util.*;

public class MegadiamondHunt
{
	public int getValue( String mine )
	{
		char[] m = mine.toCharArray();
		int n = m.length, lvl[][] = new int[n][n], ans = 0;
		for( int d = 1; d < n; d += 2 ) for( int i = 0; i+d < n; i++ )
		{
			int j = i+d;
			if( m[i]=='<' && m[j]=='>' )
			{
				if( d==1 || lvl[i+1][j-1]!=0 )
				{
					lvl[i][j] = 1+lvl[i+1][j-1];
					ans += lvl[i][j]*2-1;
				}
				for( int k = i+1; k < j; k += 2 )
					if( lvl[i][k]!=0 && lvl[k+1][j]!=0 )
						lvl[i][j] = Math.max( lvl[i][k], lvl[k+1][j] );
			}
		}
		return ans;
	}
}
