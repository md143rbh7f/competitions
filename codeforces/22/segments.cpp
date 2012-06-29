#include <cstdio>
#include <list>
#include <set>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define T 10000
#define TT 2*T+1

list<int> s[TT], res;
int n, x, y, e[TT], m;
set<int> q;

int main()
{
	scanf( "%d", &n );
	rep(i,n)
	{
		scanf( "%d%d", &x, &y );
		if( x>y )
		{
			int t = x;
			x = y;
			y = t;
		}
		s[x+T].push_back(i);
		e[i] = y+T;
	}
	rep(i,TT)
	{
		foreach(j,s[i]) q.insert( e[*j] );
		if( q.size()>0 && *q.begin()==i )
		{
			q.clear();
			m++;
			res.push_back(i);
		}
	}
	printf( "%d\n", m );
	foreach(i,res) printf( "%d ", *i-T );
	return 0;
}
