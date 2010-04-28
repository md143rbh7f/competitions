import java.math.*;
import java.util.*;

public class WordsGame
{
	public int minimumSwaps( String[] grid, String word )
	{
		int n = word.length(), canon[] = new int[128], count[] = new int[128], ans = 1000;
		char[] g[] = new char[n][n], w = word.toCharArray();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) g[i][j] = grid[i].charAt(j);
		for( int i = 0; i < n; i++ ) canon[w[i]]++;
		for( int z = 0; z < 2; z++ )
		{
			for( int i = 0; i < n; i++ )
			{
				Arrays.fill(count,0);
				boolean works = true;
				for( int j = 0; j < n; j++ ) count[g[i][j]]++;
				for( int k = 0; k < 128; k++ ) if( canon[k]!=count[k] ) works = false;
				if( works ) ans = Math.min( ans, dist( w, g[i] ) );
			}
			for( int i = 0; i < n; i++ ) for( int j = i+1; j < n; j++ )
			{
				g[i][j] ^= g[j][i];
				g[j][i] ^= g[i][j];
				g[i][j] ^= g[j][i];
			}
		}
		return ans==1000 ? -1 : ans;
	}

	int dist( char[] a, char[] c )
	{
		int n = a.length, ans = 0;
		char[] b = new char[n];
		for( int i = 0; i < n; i++ ) b[i] = c[i];
		for( int i = 0; i < n; i++ )
		if( a[i] != b[i] )
		for( int j = i+1; j < n; j++ )
		if( a[i] == b[j] )
		{
			b[i] ^= b[j];
			b[j] ^= b[i];
			b[i] ^= b[j];
			ans++;
		}
		return ans;
	}
}
