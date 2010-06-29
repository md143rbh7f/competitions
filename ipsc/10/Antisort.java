import java.io.*;
import java.math.*;
import java.util.*;

public class A
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		System.out.println( c );
		for( int t = 0; t < c; t++ )
		{
			int n = in.nextInt(), nums[] = new int[n];
			for( int i = 0; i < n; i++ ) nums[i] = in.nextInt();
			Arrays.sort( nums );
			int temp = nums[0];
			nums[0] = nums[1];
			nums[1] = temp;
			System.out.println();
			System.out.println( n );
			for( int i = 0; i < n; i++ ) System.out.print( nums[i]+ " " );
			System.out.println();
		}
	}
}
