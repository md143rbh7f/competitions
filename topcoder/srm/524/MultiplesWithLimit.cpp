#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define N 10010
bool bad[10];
int prev[N], prev_dig[N];
char digs[N];

struct MultiplesWithLimit
{
	string minMultiples( int n, vector<int> bad_digs )
	{
		for( int i = 0; i < bad_digs.size(); i++ ) bad[bad_digs[i]] = true;
		for( int i = 0; i < n; i++ ) prev[i] = -1;
		list<int> q;
		for( int d = 1; d < 10; d++ ) if( !bad[d] && prev[d%n] == -1 )
		{
			prev[d%n] = n, prev_dig[d%n] = d;
			q.push_back(d%n);
		}
		while(!q.empty())
		{
			int u = *q.begin();
			q.pop_front();
			for( int d = 0; d < 10; d++ ) if( !bad[d] )
			{
				int v = ( 10 * u + d ) % n;
				if( prev[v] == -1 )
				{
					prev[v] = u, prev_dig[v] = d;
					q.push_back(v);
				}
			}
		}
		if( prev[0] == -1 ) return "IMPOSSIBLE";
		int len = 0;
		for( int v = 0; v != n; v = prev[v] ) digs[len++] = prev_dig[v] + '0';
		ostringstream ans;
		if( len < 9 ) for( int i = len-1; i >= 0; i-- ) ans << digs[i];
		else ans << digs[len-1] << digs[len-2] << digs[len-3] << "..." << digs[2] << digs[1] << digs[0] << "(" << len << " digits)";
		return ans.str();
	}
};
