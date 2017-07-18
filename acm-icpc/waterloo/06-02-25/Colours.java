/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Colours
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Colours().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		double H = in.nextDouble(), V = in.nextDouble(), h = in.nextDouble(), v = in.nextDouble();
		if( H == 0 ) return false;

		System.out.println( "Case " + caseNum + ":" );
		int n = in.nextInt();
		double x0, x1, x2, y0, y1, y2, x, y;
		boolean b = true, xMax, yMax;
		for( int i = 0; i < n; i++ )
		{
			b = true;
			x0 = 0; x1 = h*H; x2 = H;
			y0 = 0; y1 = v*V; y2 = V;
			x = in.nextDouble(); y = in.nextDouble();
			while( true )
			{
				xMax = x > x1;
				yMax = y > y1;
				if( xMax != yMax ) break;
				if( xMax ) x0 = x1; else x2 = x1;
				x1 = h*(x2-x0) + x0;
				if( yMax ) y0 = y1; else y2 = y1;
				y1 = v*(y2-y0) + y0;
				b = !b;
			}
			System.out.println( b ? "black" : "white" );
		}

		return true;
	}

}
