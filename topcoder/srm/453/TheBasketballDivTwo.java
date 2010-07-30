import java.math.*;
import java.util.*;

public class TheBasketballDivTwo
{
	public int find( String[] table )
	{
		int n = table.length, have[] = new int[n], have2[] = new int[n], max = 0, m = 0, min = 100;
		ArrayList<int[]> unk = new ArrayList<int[]>();
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) if( i!=j )
		switch( table[i].charAt(j) )
		{
			case 'W': have[i]++; break;
			case 'L': have[j]++; break;
			case '?': unk.add(new int[]{i,j}); m++; break;
		}
		for( int s = 0; s < 1<<m; s++ )
		{
			Arrays.fill(have2,0);
			max = 0;
			for( int i = 0; i < m; i++ ) have2[unk.get(i)[(s>>i)%2]]++;
			for( int i = 0; i < n; i++ ) max = have[i]+have2[i]>max ? have[i]+have2[i] : max;
			if( min>max ) min = max;
		}
		return min;
	}
}
