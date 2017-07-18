import java.util.*;

public class Rules
{
	public static void main( String[] args )
	{
		Scanner in = new Scanner( System.in );
		int q = in.nextInt();
		String s[] = new String[q];
		in.nextLine();
		for( int i = 0; i < q; i++ ) s[i] = in.nextLine();
		int r = in.nextInt();
		for( int i = 0; i < r; i++ )
		{
			int j = in.nextInt();
			System.out.printf( "Rule %d: %s\n", j, ( j >= 1 && j <= q ) ?  s[j-1] : "No such rule" );
		}
	}
}
