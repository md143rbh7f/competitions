#include <cstdio>
#include <vector>

using namespace std;

#define N 50005
#define K 505

vector<int> g[N];
int n, k, a, b;
long long cnt[N][K];

long long rec( int v, int p )
{
	long long ans = 0;
	cnt[v][0] = 1;
	for( int i = 0; i < g[v].size(); i++ )
	{
		int u = g[v][i];
		if( u == p ) continue;
		ans += rec( u, v );
		for( int j = 0; j < k; j++ ) ans += cnt[v][j] * cnt[u][k-j-1];
		for( int j = 1; j <= k; j++ ) cnt[v][j] += cnt[u][j-1];
	}
	return ans;
}

int main()
{
	scanf( "%d%d", &n, &k );
	for( int i = 1; i < n; i++ )
	{
		scanf( "%d%d", &a, &b );
		a--, b--;
		g[a].push_back(b), g[b].push_back(a);
	}
	printf( "%lld\n", rec(0,-1) );
	return 0;
}
