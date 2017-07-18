import java.io.*;
import java.math.*;
import java.util.*;

public class History
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		String r[][] = new String[5000][10];
		int n = in.nextInt();
		for( int i = 0; i < n; i++ )
		{
			in.nextLine();
			String name = in.nextLine();
			int t0 = (int)(in.nextDouble()*10), t1 = (int)(in.nextDouble()*10);
			for( int t = t0; t <= t1; t++ ) r[t/10][t%10] = name;
		}
		int c = in.nextInt();
		for( int i = 0; i < c; i++ )
		{
			int y = in.nextInt();
			String tmp = "";
			boolean found = false;
			System.out.printf( "Galactic year %d: ", y );
			for( int j = 0; j < 10; j++ ) if( r[y][j]!=null && !r[y][j].equals(tmp) )
			{
				if( found ) System.out.print( ", " );
				System.out.print( tmp = r[y][j] );
				found = true;
			}
			if( !found ) System.out.print( "None" );
			System.out.println();
		}
	}
}
