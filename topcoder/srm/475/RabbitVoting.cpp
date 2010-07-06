#include <vector>
#include <string>
#include <map>

using namespace std;

struct RabbitVoting
{
	string getWinner( vector<string> names, vector<string> votes )
	{
		int n = names.size(), most = 0;
		string ans = "";
		map<string,int> v;
		for( int i = 0; i < n; i++ ) if( names[i]!=votes[i] )
		{
			v[votes[i]]++;
			if( v[votes[i]]>most )
			{
				most = v[votes[i]];
				ans = votes[i];
			}
			else if( v[votes[i]]==most ) ans = "";
		}
		return ans;
	}
};
