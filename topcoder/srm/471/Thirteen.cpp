#include <algorithm>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pi;
typedef pair<int,pi> pii;

#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int g[50][50], d[50][13], INF = 1111111;

int value( char c )
{
	if( c>='A' && c <='Z' ) return c-'A'+1;
	if( c>='a' && c <='z' ) return c-'a'+27;
	return INF;
}

class Thirteen
{
	public:
	int calcTime( vector<string> city )
	{
		int n = city.size(), ans = INF;
		rep(i,n) rep(j,n) g[i][j] = value( city[i][j] );
		rep(i,n) rep(m,13) d[i][m] = INF;
		d[0][0] = 0;
		set<pii> pq;
		pq.insert( mp(0,mp(0,0)) );
		while( !pq.empty() )
		{
			pii v = *pq.begin();
			pq.erase( pq.begin() );
			int dist = v.first, i = v.second.first, m = v.second.second;
			if( dist==d[i][m] )
			rep(j,n) if( g[i][j]<INF )
			{
				int dist2 = dist+g[i][j], m2 = dist2%13;
				if( m2 && dist2<d[j][m2] )
				{
					d[j][m2] = dist2;
					pq.insert( mp( dist2, mp( j, m2 ) ) );
				}
			}
		}
		for( int m = 1; m < 13; m++ ) ans = min( ans, d[n-1][m] );
		return ans==INF ? -1 : ans;
	}
};
