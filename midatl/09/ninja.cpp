#include <cmath>
#include <cstdio>
#include <map>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define L 1005
#define INF 1234567890

int n, d, id[L], x[L];
map<int,int> sorted;

bool solve()
{
	scanf( "%d%d", &n, &d );
	if( !n && !d ) return false;

	sorted.clear();
	rep(i,n)
	{
		int h;
		scanf( "%d", &h );
		sorted[h] = i;
	}

	int ord = 0;
	foreach( it, sorted ) x[ord++] = it->second;

	rep(i,n-1) if( abs( x[i+1] - x[i] ) > d )
	{
		printf( "-1\n" );
		return true;
	}

	rep(i,n) id[x[i]] = i;

	rep(i,n) if( x[i] > x[0] || x[i] > x[n-1] ) x[i] = INF;
	
	rep(t,n) rep(i,n-1)
	{
		x[i] = min( x[i], x[i+1] + d );
		x[i+1] = min( x[i+1], x[i] + d );
		x[id[i]] = min( x[id[i]], x[id[i+1]] - 1 );
	}

	printf( "%d\n", (int) abs( x[n-1] - x[0] ) );

	return true;
}

int main()
{
	while( solve() );
	return 0;
}
