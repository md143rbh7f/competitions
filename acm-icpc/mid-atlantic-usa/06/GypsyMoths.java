import java.io.*;
import java.math.*;
import java.util.*;

public class GypsyMoths
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new GypsyMoths().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt(), bestc = 0;
		if(n==0) return false;
		double x = in.nextDouble(), y = in.nextDouble(), v = in.nextDouble(), bestr = 1000000, d[] = new double[n];
		for( int i = 0; i < n; i++ ) d[i] = Math.atan2( in.nextDouble()-x, in.nextDouble()-y )*180/Math.PI;
		for( int i = 0; i < 3600; i++ )
		{
			int c = 0;
			double a = 0.1*i-v/2, b = 0.1*i+v/2;
			for( int j = 0; j < n; j++ ) if( (d[j]>a&&d[j]<b) || (d[j]+360>a&&d[j]+360<b) ) c++;
			if(c>bestc)
			{
				bestc = c;
				bestr = 0.1*i;
			}
			else if(c==bestc&&i<bestr*10) bestr = 0.1*i;
		}
		System.out.printf( "Point the camera at angle %.1f to view %d infested trees.\n", bestr, bestc );
		return true;
	}
}
