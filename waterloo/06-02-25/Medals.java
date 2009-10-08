/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class Medals
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Medals().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt(), c = -1, tot = 0, g[] = new int[n], s[] = new int[n], b[] = new int[n], lim = 5;
		double coeff[] = new double[3];
		if( n == 0 ) return false;

		for( int i = 0; i < n; i++ )
		{
			if( in.next().equals( "Canada" ) ) c = i;
			g[i] = in.nextInt();
			s[i] = in.nextInt();
			b[i] = in.nextInt();
			tot += g[i] + s[i] + b[i];
		}

		if( c != -1 )
		{
			coeff[0] = 1;
			for( int i = 0; i < lim; i++ )
			{
				coeff[1] = 1;
				for( int j = 0; j < lim; j++ )
				{
					coeff[2] = 1;
					for( int k = 0; k < lim; k++ )
					{
						double can = coeff[0] * g[c] + coeff[1] * s[c] + coeff[2] * b[c];
						for( int l = 0; l < n; l++ )
						{
							double other = coeff[0] * g[l] + coeff[1] * s[l] + coeff[2] * b[l];
							if( l != c && other >= can ) break;
							if( l == n-1 )
							{
								System.out.println( "Canada wins!" );
								return true;
							}
						}
						coeff[2] /= tot;
					}
					coeff[1] /= tot;
				}
				coeff[0] /= tot;
			}
		}

		System.out.println( "Canada cannot win." );
		return true;

	}
	
}
