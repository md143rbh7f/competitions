import java.util.*;

public class ColorfulChocolates
{
	public int maximumSpread( String ch, int m )
	{
		int n = ch.length(), ans = 0;
		for( char c = 'A'; c <= 'Z'; c++ )
		{
			ArrayList<Integer> pos = new ArrayList<Integer>();
			for( int i = 0; i < n; i++ ) if( ch.charAt(i) == c ) pos.add(i);
			for( int i = 0; i < n; i++ ) for( int j = 0; j < pos.size(); j++ )
			{
				int dist = 0;
				for( int k = 0; i + k < n && j + k < pos.size(); k++ )
				{
					dist += Math.abs( i + k - pos.get( j + k ) );
					if( dist > m ) break;
					if( k + 1 > ans ) ans = k + 1;
				}
			}
		}
		return ans;
	}
}
