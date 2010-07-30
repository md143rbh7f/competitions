#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

vi pts;
int w, d, INF = 1000000, nd[50];

bool dec( int i )
{
	while( nd[i]>=0 && (pts[i]-d*nd[i])%w ) nd[i]--;
	return nd[i]>=0;
}

struct TheTournamentDivOne
{
	int find( vi _pts, int _w, int _d )
	{
		pts = _pts, w = _w, d = _d;
		int n = pts.size(), tot = 0, ans = INF;
		rep(i,n) tot += pts[i];

		rep(i,n)
		{
			nd[i] = pts[i]/d;
			if( !dec(i) ) return -1;
		}

		while(1)
		{
			int totd = 0, top = 0;
			rep(i,n) totd += nd[i];
			rep(i,n) if( nd[i]>nd[top] ) top = i;
			if( totd%2==0 && nd[top]<=totd/2 )
			{
				int sum = totd/2 + (tot-d*totd)/w;
				if( sum<ans ) ans = sum;
			}
			nd[top]--;
			if( !dec(top) ) break;
		}

		return ans == INF ? -1 : ans;
	}
};
