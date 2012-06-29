#include <map>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

map<int,int> c;

struct ColorfulRabbits
{
	int getMinimum( vector<int> r )
	{
		for( int i = 0; i < r.size(); i++ ) c[r[i]]++;
		int ans = 0;
		foreach( i, c ) ans += ( i->second + i->first ) / ( i->first + 1 ) * ( i->first + 1 );
		return ans;
	}
};
