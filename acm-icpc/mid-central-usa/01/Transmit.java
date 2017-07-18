/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Transmit
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Transmit().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int x = in.nextInt(), y = in.nextInt();
		double r = in.nextDouble(), r2 = r*r;
		if( r < 0 ) return false;

		int n = in.nextInt();
		ArrayList<Double> angles = new ArrayList<Double>();
		for( int i = 0; i < n; i++ )
		{
			int dx = in.nextInt() - x, dy = in.nextInt() - y;
			if( dx*dx + dy*dy <= r2 )
			{
				double a = Math.atan2( dy, dx );
				if( a < 0 ) a += 2*Math.PI;
				angles.add( a );
			}
		}
		n = angles.size();
		Collections.sort( angles );

		int max = 0;
		for( int i = 0; i < n; i++ )
		{
			double a = angles.get(i);
			int pts = 0;
			for( int j = 0; j < n; j++ )
			{
				double a1 = angles.get(j), a2 = a1+2*Math.PI;
				if( ( a1-a <= Math.PI && a1 >= a ) || ( a2-a <= Math.PI && a2 > a ) ) pts++;
			}
			max = max > pts ? max : pts;
		}
		System.out.println( max );
		return true;
	}
}
