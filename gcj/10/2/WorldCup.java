import java.io.*;
import java.math.*;
import java.util.*;

public class WorldCup
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int c = in.nextInt();
		for( int i = 1; i <= c; i++ ) new WorldCup().solve( i );
	}

	// small case only
	int p, P, m[], price[], teams[][];
	void solve( int caseNum )
	{
		p = in.nextInt();
		P = 1<<p;
		price = new int[P];
		m = new int[P];
		for( int i = 0; i < P; i++ ) m[i] = in.nextInt();
		for( int i = p-1; i >= 0; i-- ) for( int j = 0; j < 1<<i; j++ ) price[(1<<i)+j] = in.nextInt();
		teams = new int[2*P][];
		teams[1] = new int[P];
		for( int i = 0; i < P; i++ ) teams[1][i] = i;
		for( int i = 2; i < 2*P; i++ )
		{
			int l = teams[i/2].length/2, add = l*(i%2);
			teams[i] = new int[l];
			for( int j = 0; j < teams[i].length; j++ ) teams[i][j] = teams[i/2][j+add];
		}
		System.out.printf( "Case #%d: %d\n", caseNum, rec( m, 1 ) );
	}

	int inf = 777777777;
	int rec( int[] have, int k )
	{
		boolean need = false;
		if( k >= 2*P ) return inf;
		for( int i = 0; i < teams[k].length; i++ ) if( have[teams[k][i]]<p ) need = true;
		if( need )
		{
			if( k >= P ) return inf;
			// use or not use
			int use[] = new int[P], skip[] = new int[P];
			for( int i = 0; i < teams[k].length; i++ )
			{
				use[teams[k][i]] = Math.min( p, have[teams[k][i]]+1 );
				skip[teams[k][i]] = have[teams[k][i]];
			}
			return Math.min( inf, Math.min( price[k]+rec(use,k*2)+rec(use,k*2+1), rec(skip,k*2)+rec(skip,k*2+1) ) );
		}
		return 0;
	}
}
