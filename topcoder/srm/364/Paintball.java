/*
	AxiomOfChoice
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Paintball
{
	public String[] getLeaderboard( String[] players, String[] messages )
	{
		HashMap<String,String> teams = new HashMap<String,String>();
		HashMap<String,Integer> score = new HashMap<String,Integer>();
		HashMap<String,Integer> teamScore = new HashMap<String,Integer>();
		for( String s : players )
		{
			String[] sp = s.split(" ");
			teams.put(sp[0],sp[1]);
			score.put(sp[0],0);
			teamScore.put(sp[1],0);
		}
		for( String m : messages )
		{
			String[] ms = m.split(" ");
			if( teams.get(ms[0]).equals(teams.get(ms[2])) )
				score.put(ms[0],score.get(ms[0])-1);
			else
			{
				score.put(ms[0],score.get(ms[0])+1);
				score.put(ms[2],score.get(ms[2])-1);
			}
		}
		for( String p : teams.keySet() )
			teamScore.put(teams.get(p),teamScore.get(teams.get(p))+score.get(p));
		String[] sortedTeams = new String[teamScore.size()];
		int temp = 0;
		for( String s : teamScore.keySet() ) sortedTeams[temp++] = s;
		Arrays.sort( sortedTeams, new MapComparator(teamScore) );
		String[] sortedPlayers = new String[score.size()];
		temp = 0;
		for( String s : score.keySet() ) sortedPlayers[temp++] = s;
		Arrays.sort( sortedPlayers, new MapComparator(score) );
		ArrayList<String> res = new ArrayList<String>();
		for( String team : sortedTeams )
		{
			res.add( team+" "+teamScore.get(team) );
			for( String player : sortedPlayers )
			if( teams.get(player).equals(team) )
				res.add( "  "+player+" "+score.get(player) );
		}
		return res.toArray( new String[1] );
	}

	class MapComparator implements Comparator<String>
	{
		HashMap<String,Integer> map;
		MapComparator( HashMap<String,Integer> _map ) { map = _map; }
		public int compare( String a, String b )
		{
			if( map.get(a) != map.get(b) ) return map.get(b)-map.get(a);
			return a.compareTo(b);
		}
	}
}
