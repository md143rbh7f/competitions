import java.io.*;
import java.math.*;
import java.util.*;

public class Vitamins
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		ArrayList<String> bad = new ArrayList<String>();
		while(true)
		{
			double a = in.nextDouble();
			if(a<0) break;
			String u = in.next();
			double r = in.nextDouble();
			String v = in.nextLine().trim();
			if(a/r>=0.01) System.out.printf( "%s %.1f %s %.0f%%\n", v, a, u, a/r*100  );
			else bad.add(v);
		}
		System.out.println( "Provides no significant amount of:" );
		for( String b : bad ) System.out.println( b );
	}
}
