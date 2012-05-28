#include <cstdio>
#include <vector>

using namespace std;

#define N 100005

int n, k, s[N], t[N], d[N], p[N], pred[N], cnt[N];
vector<int> g[N], q[N];
bool done[N];

int find( int x )
{
	int y = x;
	while( p[y] >= 0 ) y = p[y];
	while( p[x] >= 0 )
	{
		int tmp = x;
		x = p[x];
		p[tmp] = y;
	}
	return y;
}

void merge( int x, int y )
{
	int a = find(x), b = find(y);
	if( a == b ) return;
	if( p[a] > p[b] ) a ^= b, b ^= a, a ^= b;
	p[a] += p[b];
	p[b] = a;
}

void dfs0( int v )
{
	p[v] = -1;
	pred[v] = v;
	for( int i = 0; i < g[v].size(); i++ )
	{
		int u = g[v][i];
		if( d[u] ) continue;
		d[u] = d[v] + 1;
		dfs0(u);
		merge( u, v );
		pred[find(v)] = v;
	}
	done[v] = true;

	for( int i = 0; i < q[v].size(); i++ )
	{
		int u = q[v][i];
		if( !done[u] ) continue;
		int lca = pred[find(u)];
		cnt[u]++, cnt[v]++;
		cnt[lca] -= 2;
	}
}

void dfs1( int v )
{
	for( int i = 0; i < g[v].size(); i++ )
	{
		int u = g[v][i];
		if( d[u] < d[v] ) continue;
		dfs1( g[v][i] );
		cnt[v] += cnt[u];
	}
}

int main()
{
	scanf( "%d", &n );
	for( int i = 0; i < n - 1; i++ )
	{
		int & a = s[i], & b = t[i];
		scanf( "%d%d", &a, &b );
		g[a].push_back(b), g[b].push_back(a);
	}

	scanf( "%d", &k );
	for( int i = 0; i < k; i++ )
	{
		int a, b;
		scanf( "%d%d", &a, &b );
		q[a].push_back(b), q[b].push_back(a);
	}

	d[1] = 1;
	dfs0(1), dfs1(1);
	for( int i = 0; i < n - 1; i++ ) printf( "%d ", cnt[ d[s[i]] > d[t[i]] ? s[i] : t[i] ] );
	printf( "\n" );

	return 0;
}
