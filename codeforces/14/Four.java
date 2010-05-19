import java.io.*;
import java.math.*;
import java.util.*;
import java.awt.Point;

public class Four
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		Point[][] pts = new Point[4][2];
		for( int i = 0; i < 4; i++ ) for( int j = 0; j < 2; j++ ) pts[i][j] = new Point( in.nextInt(), in.nextInt() );
		HashSet<Point> pts2 = new HashSet<Point>();
		for( int i = 0; i < 4; i++ )
		{
			pts2.add( pts[i][0] );
			pts2.add( pts[i][1] );
		}
		if( pts2.size()!=4 )
		{
			System.out.println( "NO" );
			return;
		}
		int minx = 1<<30, miny = minx, maxx = -minx, maxy = -minx;
		for( Point pt : pts2 )
		{
			if( pt.x<minx ) minx = pt.x;
			if( pt.x>maxx ) maxx = pt.x;
			if( pt.y<miny ) miny = pt.y;
			if( pt.y>maxy ) maxy = pt.y;
		}
		boolean left = false, right = false, bottom = false, top = false;
		for( int i = 0; i < 4; i++ )
		{
			if( pts[i][0].x==pts[i][1].x && pts[i][0].y!=pts[i][1].y )
			{
				if( pts[i][0].x==minx ) left = true;
				else if( pts[i][0].x==maxx ) right = true;
			}
			if( pts[i][0].y==pts[i][1].y && pts[i][0].x!=pts[i][1].x )
			{
				if( pts[i][0].y==miny ) bottom = true;
				else if( pts[i][0].y==maxy ) top = true;
			}
		}
		if( left&&right&&bottom&&top ) System.out.println( "YES" );
		else System.out.println( "NO" );
	}
}
