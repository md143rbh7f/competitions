/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class TheCitiesAndRoadsDivTwo
{
	public int find( String[] _map )
	{
		map = _map;
		n = map.length;
		seen = new boolean[n];
		ArrayList<Integer> comps = new ArrayList<Integer>();
		for( int i = 0; i < n; i++ )
		{
			int size = dfs(i);
			if( size != 0 ) comps.add( size );
		}
		if( comps.size() == 1 ) return 1;
		int ans = 1;
		for( int i : comps ) ans *= i;
		for( int i = 0; i < comps.size()-2; i++ ) ans *= n;
		return ans;
	}

	int n;
	String[] map;
	boolean[] seen;

	int dfs( int i )
	{
		if( seen[i] ) return 0;
		seen[i] = true;
		int ans = 1;
		for( int j = 0; j < n; j++ )
			if( map[i].charAt(j) == 'Y' )
				ans += dfs(j);
		return ans;
	}
}
