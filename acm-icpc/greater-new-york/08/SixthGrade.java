/*
	Siyang Chen
 */

import java.io.*;
import java.util.*;

public class SixthGrade
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );
	static int INF = 0x3fffffff;

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new SixthGrade().solve( i );
	}

	void solve( int caseNum )
	{
		int a = in.nextInt(), b = in.nextInt();
		int[] ans = gcd_lcm( a, b );
		System.out.println( caseNum + " " + ans[1] + " " + ans[0] );
	}

	public static int gcd( int a, int b )
	{
		if( b == 0 ) return a;
		return gcd( b, a % b );
	}

	public static int[] gcd_lcm( int a, int b )
	{
		int d = gcd( a, b );
		int m = a * b / d;
		int[] ans = { d, m };
		return ans;
	}

}
