#include <cstdlib>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pi;
typedef pair<int,pi> pii;
#define mp(a,b) make_pair((a),(b))

int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
bool seen[50][50];

int val( char c )
{
	if( c>='0' && c<='9' ) return c-'0';
	if( c>='a' && c<='z' ) return c-'a'+10;
	if( c>='A' && c<='Z' ) return c-'A'+36;
	return -1;
}

class ActivateGame
{
	public:
	int findMaxScore( vector<string> g )
	{
		int n = g.size(), m = g[0].size(), ans = 0;
		set<pii> q;
		q.insert( mp(0,mp(0,0)) );
		while( !q.empty() )
		{
			pii v = *q.begin();
			q.erase(q.begin());
			int diff = v.first, i = v.second.first, j = v.second.second;
			if( !seen[i][j] )
			{
				seen[i][j] = true;
				ans -= diff;
				for( int d = 0; d < 4; d++ )
				{
					int ii = i+dx[d], jj = j+dy[d];
					if( ii>=0 && jj>=0 && ii<n && jj < m ) q.insert( mp( -abs(val(g[i][j])-val(g[ii][jj])), mp(ii,jj) ) );
				}
			}
		}
		return ans;
	}
};
