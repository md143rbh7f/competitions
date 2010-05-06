import java.awt.Point;
import java.math.*;
import java.util.*;

public class RobotSimulation
{
	int[] dx = { 0, 0, -1, 1 } ,dy = { 1, -1, 0, 0 };
	public int cellsVisited( String c, int t )
	{
		int x = 0, y = 0, old = 0, dif = 0, n = c.length();
		boolean end = true;
		HashSet<Point> pts = new HashSet<Point>();
		for( int i = 0; i<t && i<10; i++ )
		{
			old = pts.size();
			for( int j = 0; j < n; j++ )
			{
				pts.add( new Point( x, y ) );
				int d = 0;
				switch( c.charAt(j) )
				{
					case 'U': d = 0; break;
					case 'D': d = 1; break; 
					case 'L': d = 2; break;
					case 'R': d = 3; break;
				}
				x += dx[d]; y += dy[d];
			}
			if( pts.contains( new Point( x, y ) ) ) end = false;
			dif = pts.size()-old;
		}
		return pts.size()+dif*(t>10?t-10:0)+(end?1:0);
	}
}
