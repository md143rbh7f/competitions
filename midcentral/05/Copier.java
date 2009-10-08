/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Copier
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;
	static int MAX;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Copier().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int ix = in.nextInt(), iy = in.nextInt(), px = in.nextInt(), py = in.nextInt();
		if( ix == 0 ) return false;

		if( ix < iy )
		{
			ix ^= iy;
			iy ^= ix;
			ix ^= iy;
		}

		if( px < py )
		{
			px ^= py;
			py ^= px;
			px ^= py;
		}

		double sx = px / ( 1.0 * ix), sy = py / ( 1.0 * iy);
		if( sx >= 1 && sy >= 1 ) System.out.println( "100%" );
		else System.out.println( (int)( Math.min( sx, sy ) * 100 ) + "%" );

		return true;
	}
}
