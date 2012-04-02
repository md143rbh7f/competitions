#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct EllysJuice
{
	vector<string> getWinners( vector<string> players )
	{
		sort( players.begin(), players.end() );
		set<string> winners;
		do
		{
			map<string,double> drank;
			double amt = 1;
			for( int i = 0; i < players.size(); i++ )
			{
				if(!(i%2)) amt /= 2;
				drank[players[i]] += amt;
			}
			bool win = true;
			double best = 0;
			string winner;
			for( map<string,double>::iterator it = drank.begin(); it != drank.end(); it++ )
			{
				if( it->second > best )
				{
					win = true;
					winner = it->first;
					best = it->second;
				}
				else if( it->second == best ) win = false;
			}
			if( win ) winners.insert( winner );
		}
		while( next_permutation( players.begin(), players.end() ) );
		vector<string> ans;
		for( set<string>::iterator it = winners.begin(); it != winners.end(); it++ ) ans.push_back( *it );
		return ans;
	}
};
