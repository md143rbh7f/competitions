#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
#define MOD 1000000009
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

map< vector<int>, int > dist;

struct FoxStones
{
	int getCount( int n, int m, vector<int> sx, vector<int> sy )
	{
		int l = sx.size();
		for( int i = 1; i <= n; i++ ) for( int j = 1; j <= m; j++ )
		{
			vector<int> d;
			for( int k = 0; k < l; k++ ) d.push_back( max( abs(sx[k]-i), abs(sy[k]-j) ) );
			dist[d]++;
		}
		ll ans = 1;
		foreach(i,dist)
		{
			int x = i->second;
			while(x)
			{
				ans = (ans*x) % MOD;
				x--;
			}
		}
		return (int) ans;
	}
};
