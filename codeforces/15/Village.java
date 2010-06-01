import java.io.*;
import java.math.*;
import java.util.*;

public class Village
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int n = in.nextInt(), t = 2*in.nextInt(), h[][] = new int[n][2], ans = 2;
		for( int i = 0; i < n; i++ )
		{
			h[i][0] = 2*in.nextInt();
			h[i][1] = in.nextInt();
		}
		Arrays.sort( h, new Comp() );
		for( int i = 1; i < n; i++ )
		{
			int d = (h[i][0]-h[i][1])-(h[i-1][0]+h[i-1][1]);
			if( d > t ) ans += 2;
			else if( d == t ) ans++;
		}
		System.out.println( ans );
	}

	static class Comp implements Comparator<int[]> { public int compare( int[] a, int[] b ) { return a[0]-b[0]; } }
}
