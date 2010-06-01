import java.io.*;
import java.math.*;
import java.util.*;

public class Laser
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Laser().solve( i );
	}

	void solve( int caseNum )
	{
		long n = in.nextInt(), m = in.nextInt(), x1 = in.nextInt(), y1 = in.nextInt(), x2 = in.nextInt(), y2 = in.nextInt(), dx = Math.abs(x1-x2), dy = Math.abs(y1-y2), x3 = n-dx, y3 = m-dy, x4 = 1+dx, y4 = 1+dy, mid = x3>=x4 && y3>=y4 ? (x3-x4+1)*(y3-y4+1) : 0, melted = 2*x3*y3-mid, ans = n*m-melted;
		System.out.println( ans );
	}
}
