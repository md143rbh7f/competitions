/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class BuildingCities
{
	public int findMinimumCities( int step, int max, int[] x, int[] y )
	{
		int n = x.length;
		double[][] dist = new double[n][n];
		int[][] cost = new int[n][n];
		for( int i = 0; i < n; i++ ) for( int j = i+1; j < n; j++ )
		{
			int dx = x[i]-x[j], dy = y[i]-y[j];
			double d = Math.sqrt(dx*dx+dy*dy);
			dist[i][j] = dist[j][i] = d;
			cost[i][j] = cost[j][i] = (int)(Math.ceil(d/step)-1);
		}
		
		// minDist[x][y] := minimum distance from start to x while building cost[0][x]-y cities
		minDist = new double[n][n];
		for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) minDist[i][j] = 100000;
		minDist[0][0] = 0;

		PriorityQueue<State> pq = new PriorityQueue<State>();
		State ptr = new State(0,0);
		pq.add( ptr );
		while( !pq.isEmpty() )
		{
			ptr = pq.poll();
			int v = ptr.v, built = cost[0][v]-ptr.c;
			double d = minDist[v][ptr.c];
			for( int c = 0; c < n; c++ ) if( c != v )
			{
				int nextBuilt = cost[0][c]-(built+cost[v][c]);
				if( nextBuilt >= 0 && minDist[c][nextBuilt] > d+dist[v][c] )
				{
					minDist[c][nextBuilt] = d+dist[v][c];
					State child = new State(c,nextBuilt);
					pq.remove(child);
					pq.add(child);
				}
			}
		}

		for( int i = n-1; i >= 0; i-- )
			if( minDist[n-1][i] < max )
				return cost[0][n-1]-i;

		return -1;
	}

	double[][] minDist;
	
	class State implements Comparable<State>
	{
		int v, c;
		State( int _v, int _c ) { v = _v; c = _c; }
		public int compareTo( State o )
		{
			double da = minDist[v][c], db = minDist[o.v][o.c];
			if( da < db ) return -1;
			if( da > db ) return 1;
			if( c > o.c ) return -1;
			if( c < o.c ) return 1;
			return v-o.v;
		}
		public boolean equals( Object other )
		{
			State o = (State)other;
			return v==o.v && c==o.c;
		}
	}
}
