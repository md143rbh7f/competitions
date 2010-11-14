#include <string>

using namespace std;

struct BunnyExamAfter
{
	int getMaximum( string b, string g, string w )
	{
		int ans = 0;
		for( int i = 0; i < b.size(); i++ )
		{
			if(g[i]!=w[i]) ans++;
			else if(w[i]!=b[i]) ans+=2;
		}
		return ans;
	}
};
