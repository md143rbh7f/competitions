import java.io.*;
import java.math.*;
import java.util.*;

public class Photographer
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int n = in.nextInt(), x0 = in.nextInt(), ab[][] = new int[n][2];
		for( int i = 0; i < n; i++ )
		{
			ab[i][0] = in.nextInt();
			ab[i][1] = in.nextInt();
			if( ab[i][0]>ab[i][1] )
			{
				ab[i][0]^=ab[i][1];
				ab[i][1]^=ab[i][0];
				ab[i][0]^=ab[i][1];
			}
		}
		int min = -1, max = 1001;
		for( int i = 0; i < n; i++ )
		{
			if( ab[i][0]>min ) min = ab[i][0];
			if( ab[i][1]<max ) max = ab[i][1];
			if( min>max )
			{
				System.out.println( -1 );
				return;
			}
		}
		if( x0>=min && x0<=max ) System.out.println( 0 );
		else System.out.println( Math.min( Math.abs(x0-min), Math.abs(x0-max) ) );
	}
}
