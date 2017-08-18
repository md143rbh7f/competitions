#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#define mp(a,b) make_pair((a),(b))

typedef pair<int,int> pii;
#define N 262144
#define INF 2147483647

int n, m, q, opt, s, t, ds[N], dt[N], comp[N], tree_start, tree[2*N];
vector<pii> g[N], bridges;

void dijkstra( int x, int d[N] )
{
	set<pii> q;
	for( int i = 0; i < n; i++ ) d[i] = -1;
	d[x] = 0;
	q.insert( mp( 0, x ) );
	while( !q.empty() )
	{
		int u = q.begin()->second;
		q.erase( q.begin() );
		for( int i = 0; i < g[u].size(); i++ )
		{
			int v = g[u][i].first, w = g[u][i].second;
			if( d[v] == -1 || d[u] + w < d[v] )
			{
				q.erase( mp( d[v], v ) );
				d[v] = d[u] + w;
				q.insert( mp( d[v], v ) );
			}
		}
	}
}

bool cmp( const pii & a, const pii & b )
{
	if( ds[a.first] != ds[b.first] ) return ds[a.first] < ds[b.first];
	if( ds[a.second] != ds[b.second] ) return ds[a.second] < ds[b.second];
	return a < b;
}

void find_bridges()
{
	vector<pii> opt_edges;
	for( int u = 0; u < n; u++ ) if( ds[u] + dt[u] == opt ) for( int i = 0; i < g[u].size(); i++ )
	{
		int v = g[u][i].first, w = g[u][i].second;
		if( ds[u] + w + dt[v] == opt ) opt_edges.push_back( mp( u, v ) );
	}
	sort( opt_edges.begin(), opt_edges.end(), cmp );

	for( int i = 0; i < opt_edges.size(); i++ )
	{
		bool prev = i == 0 || ds[opt_edges[i-1].second] <= ds[opt_edges[i].first];
		bool next = i == opt_edges.size()-1 || ds[opt_edges[i].second] <= ds[opt_edges[i+1].first];
		if( prev && next ) bridges.push_back( opt_edges[i] );
	}
}

int bridge_id( int u, int v )
{
	vector<pii>::iterator it = lower_bound( bridges.begin(), bridges.end(), mp( u, v ), cmp );
	return it != bridges.end() && *it == mp( u, v ) ? (int)( it - bridges.begin() ) : -1;
}

void find_comp_dfs( int u, int c )
{
	comp[u] = c;
	for( int i = 0; i < g[u].size(); i++ )
	{
		int v = g[u][i].first, w = g[u][i].second;
		if( comp[v] == -1 && ds[u] + w == ds[v] && bridge_id( u, v ) == -1 ) find_comp_dfs( v, c );
	}
}

void find_comps()
{
	for( int i = 0; i < n; i++ ) comp[i] = -1;
	find_comp_dfs( s, 0 );
	for( int i = 0; i < bridges.size(); i++ ) find_comp_dfs( bridges[i].second, i + 1 );
}

void init_tree()
{
	tree_start = 1;
	while( tree_start < bridges.size() ) tree_start *= 2;
	for( int i = 1; i < 2 * tree_start; i++ ) tree[i] = INF;
}

void update_tree( int i, int j, int val )
{
	for( i += tree_start, j += tree_start; i <= j; i = ( i + 1 ) / 2, j = ( j - 1 ) / 2 )
	{
		if( i % 2 == 1 ) tree[i] = min( tree[i], val );
		if( j % 2 == 0 ) tree[j] = min( tree[j], val );
	}
}

int query_tree( int id )
{
	int ans = INF;
	for( id += tree_start; id; id /= 2 ) ans = min( ans, tree[id] );
	return ans;
}

void find_bypasses()
{
	init_tree();
	for( int u = 0; u < n; u++ ) for( int i = 0; i < g[u].size(); i++ )
	{
		int v = g[u][i].first, w = g[u][i].second;
		if( comp[u] < comp[v] && bridge_id( u, v ) == -1 ) update_tree( comp[u], comp[v] - 1, ds[u] + w + dt[v] );
	}
}

int main()
{
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < m; i++ )
	{
		int u, v, w;
		scanf( "%d%d%d", &u, &v, &w );
		g[u].push_back( mp( v, w ) ), g[v].push_back( mp( u, w ) );
	}

	scanf( "%d%d", &s, &t );
	dijkstra( s, ds ), dijkstra( t, dt );
	opt = ds[t];

	find_bridges(), find_comps(), find_bypasses();

	scanf( "%d", &q );
	while(q--)
	{
		int u, v;
		scanf( "%d%d", &u, &v );
		if( comp[u] > comp[v] ) u ^= v, v ^= u, u ^= v;

		int id = bridge_id( u, v );
		if( id == -1 ) printf( "%d\n", opt );
		else
		{
			int bypass_len = query_tree( id );
			if( bypass_len == INF ) printf( "Infinity\n" );
			else printf( "%lld\n", bypass_len );
		}
	}

	return 0;
}
