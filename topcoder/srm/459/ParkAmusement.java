import java.io.*;
import java.math.*;
import java.util.*;

public class ParkAmusement
{
	public double getProbability( String[] landings, int start, int K )
	{
		n = landings.length; k = K;
		g = (LinkedList<Integer>[])(new LinkedList[n]);
		exits = new LinkedList<Integer>();
		for( int i = 0; i < n; i++ )
		{
			g[i] = new LinkedList<Integer>();
			switch( landings[i].charAt(i) )
			{
				case 'E': exits.add(i); break;
				case '0':
					for( int j = 0; j < n; j++ )
						if( landings[i].charAt(j) == '1' ) 
							g[i].add(j);
					break;
			}
		}
		
		prob = new double[2][n];
		for( int i = 0; i < n; i++ ) prob[0][i] = 1.0;
		double safe = run();
		
		prob = new double[2][n];
		prob[0][start] = 1.0;
		double safeFromStart = run();

		return safeFromStart/safe;
	}

	int n, k;
	double[][] prob;
	LinkedList<Integer> g[], exits;

	double run()
	{
		for( int i = 0; i < k; i++ ) for( int j = 0; j < n; j++ )
		{
			int b = g[j].size();
			for( int c : g[j] ) prob[(i+1)%2][c] += prob[i%2][j]/b;
			prob[i%2][j] = 0;
		}
		double safe = 0;
		for( int i : exits ) safe += prob[k%2][i];
		return safe;
	}
}
