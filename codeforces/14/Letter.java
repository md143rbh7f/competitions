import java.io.*;
import java.math.*;
import java.util.*;

public class Letter
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int n = in.nextInt(), m = in.nextInt();
		char[][] map = new char[n][];
		for( int i = 0; i < n; i++ ) map[i] = in.next().toCharArray();
		int minx = 100, miny = 100, maxx = 0, maxy = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; j++ )
		if( map[i][j]=='*' )
		{
			if( i<minx ) minx = i;
			if( i>maxx ) maxx = i;
			if( j<miny ) miny = j;
			if( j>maxy ) maxy = j;
		}
		for( int i = minx; i <= maxx; i++ )
		{
			for( int j = miny; j <= maxy; j++ ) System.out.print( map[i][j] );
			System.out.println();
		}
	}
}
