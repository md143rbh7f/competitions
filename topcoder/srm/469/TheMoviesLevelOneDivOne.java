import java.math.*;
import java.util.*;
import java.awt.Point;

public class TheMoviesLevelOneDivOne
{
	public long find( int x, int y, int[] xt, int[] yt )
	{
		long ans = ((long)x)*(y-1);
		int n = xt.length;
		HashSet<Point> taken = new HashSet<Point>();
		for( int i = 0; i < n; i++ )
		{
			xt[i]--;
			yt[i]--;
			taken.add( new Point(xt[i],yt[i]) );
		}
		for( int i = 0; i < n; i++ )
		{
			if( yt[i]!=y-1 ) ans--;
			if( yt[i]!=0 && !taken.contains(new Point(xt[i],yt[i]-1)) ) ans--;
		}
		return ans;
	}
}
