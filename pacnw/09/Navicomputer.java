import java.io.*;
import java.math.*;
import java.util.*;

public class Navicomputer
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Navicomputer().solve( i );
	}

	void solve( int caseNum )
	{
		in.nextLine();
		String s0 = in.nextLine();
		double x0 = in.nextDouble(), y0 = in.nextDouble(), z0 = in.nextDouble();
		in.nextLine();
		String s1 = in.nextLine();
		double x1 = in.nextDouble(), y1 = in.nextDouble(), z1 = in.nextDouble();
		System.out.printf( "%s to %s: %.2f\n", s0, s1, Math.sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)+(z0-z1)*(z0-z1)) );
	}
}
