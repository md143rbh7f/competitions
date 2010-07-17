#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define MAX 36

bool g[MAX][MAX];
int n, k, s = 1, d[MAX];
double mem[MAX][1<<16], tmp[MAX];

void calc( int v, int seen )
{
	if( mem[v][seen]>-1 ) return;
	if( seen==(1<<s)-1 )
	{
		mem[v][seen] = 1;
		return;
	}
	int m = 0;
	rep(c,n) if( g[v][c] && !(seen&(1<<d[c])) ) calc( c, seen|(1<<d[c]) );
	rep(c,n) if( g[v][c] ) tmp[m++] = seen&(1<<d[c]) ? 0 : mem[c][seen|(1<<d[c])];
	sort( tmp, tmp+m );
	reverse( tmp, tmp+m );
	if( m<=k ) mem[v][seen] = tmp[0];
	else
	{
		double c = 1.0*k/m;
		int t = m-k, b = m-1;
		mem[v][seen] = 0;
		rep(i,m-k+1)
		{
			mem[v][seen] += c*tmp[i];
			c *= 1.0*t/b;
			t--, b--;
		}
	}
}

struct FriendTour
{
	double tourProbability( vector<string> friends, int K )
	{
		n = friends.size(), k = K;
		rep(i,n)
		{
			istringstream iss(friends[i]);
			int j;
			while( iss>>j ) g[i][j-1] = true;
		}
		rep(i,n) if( g[0][i] ) d[i] = s++;
		rep(i,MAX) rep(j,1<<16) mem[i][j] = -1;
		calc( 0, 1 );
		return mem[0][1];
	}
};
