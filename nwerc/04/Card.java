import java.io.*;
import java.math.*;
import java.util.*;

public class Card
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new Card().solve( i );
	}

	void solve( int caseNum )
	{
		int n = in.nextInt(), c[][] = new int[2][n];
		for( int p = 0; p < 2; p++ )
		{
			for( int i = 0; i < n; i++ )
			{
				char[] card = in.next().toCharArray();
				int v = 0;
				switch( card[0] )
				{
					case 'T': v = 10; break;
					case 'J': v = 11; break;
					case 'Q': v = 12; break;
					case 'K': v = 13; break;
					case 'A': v = 14; break;
					default: v = card[0]-'0'; break;
				}
				v *= 4;
				switch( card[1] )
				{
					case 'C': v += 0; break;
					case 'D': v += 1; break;
					case 'S': v += 2; break;
					case 'H': v += 3; break;
				}
				c[p][i] = v;
			}
			Arrays.sort( c[p] );
		}
		int score = 0, j = n-1;
		for( int i = n-1; i >= 0; i-- )
		if( c[0][i] < c[1][j] )
		{
			score++;
			j--;
		}
		System.out.println( score );
	}
}
