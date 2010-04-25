import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;

public class SpidersOnTheGrid
{
	public int find( String[] a )
	{
		int n = a.length, m = a[0].length(), count = 0;
		boolean[][] g = new boolean[n][m];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		{
			int tx = i, ty = j;
			switch( a[i].charAt(j) )
			{
				case 'N': tx--; break;
				case 'S': tx++; break;
				case 'E': ty++; break;
				case 'W': ty--; break;
			}
			if( tx>=0 && ty>=0 && tx<n && ty<m ) g[tx][ty] = true;
		}
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
			if( !g[i][j] )
				count++;
		return count;
	}
}
