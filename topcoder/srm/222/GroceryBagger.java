/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class GroceryBagger
{
	public int minimumBags( int str, String[] type )
	{
		HashMap<String,Integer> count = new HashMap<String,Integer>();
		for( String t : type )
		{
			if( !count.containsKey(t) ) count.put(t,0);
			count.put(t,count.get(t)+1);
		}
		int ans = 0;
		for( String t : count.keySet() ) ans += (count.get(t)+str-1)/str;
		return ans;
	}
}
