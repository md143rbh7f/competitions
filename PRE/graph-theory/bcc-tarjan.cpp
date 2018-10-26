/*
 * Tarjan's algorithm to find biconnected components, articulation points, and
 * bridges is a modified version of Tarjan's algorithm for strongly connected
 * components.
 *
 * 1. Biconnected components are subgraphs in which every vertex is connected
 * via a cycle to every other vertex.
 * 2. Bridges are edges which, when removed from the graph, leave the graph
 * disconnected.
 * 3. Articulation points are vertices which, when removed from the graph,
 * leave the graph disconnected.
 *
 * In order to compute the above three things, this algorithm performs a DFS on
 * the graph while keeping track of a value lowlink[i]. If ord[i] is the DFS
 * traversal order of node i, then lowlink[i] is defined to be minimum ord[j],
 * such that j is reachable from i with at most one 'back edge'.
 */

// graph as adj list
vector<int> g[N];

// graph size, dfs time, dfs order, lowlink, parent
int n, t, ord[N], low[N], par[N];

/*
 * _h[i] is the i-th biconnected component as an adjacency list.
 * (i.e. _h[i][j] is the neighbours of j in the i-th component)
 */
map< int, vector<int> > _h[N], * h;

// bridges
int _ba[N], _bb[N], * ba, * bb;

// root children cnt, articulation points
int root_children;
bool art[N];

// stack of edges
int _sta[N], _stb[N], * sta, * stb;

// push an edge onto the stack
inline void push( int a, int b ) { *(sta++) = a, *(stb++) = b; }

// process a component (either a bridge or BCC)
void pop( int a, int b )
{
	h->clear();
	int cnt = 0;
	do
	{
		sta--, stb--, cnt++;
		(*h)[*sta].push_back( *stb ), (*h)[*stb].push_back( *sta );
	}
	while( *sta != a || *stb != b );
	if( cnt == 1 ) *(ba++) = a, *(bb++) = b; // bridge
	else h++;
}

void tarjan_dfs( int i )
{
	low[i] = ord[i] = t++;
	foreach( j, g[i] )
	{
		if( ord[*j] == -1 )
		{
			push( i, *j ), par[*j] = i;
			tarjan_dfs( *j );
			low[i] = min( low[i], low[*j] );
			if( low[*j] >= ord[i] ) pop( i, *j ), art[i] = true;
			if( par[i] == -1 ) root_children++;
		}
		else if( ord[*j] < ord[i] && *j != par[i] )
		{
			push( *j, i );
			low[i] = min( low[i], ord[*j] );
		}
	}
}

void tarjan()
{
	h = _h, sta = _sta, stb = _stb, ba = _ba, bb = _bb, t = 0;
	for( int i = 0; i < n; i++ ) ord[i] = -1, art[i] = false;
	for( int i = 0; i < n; i++ ) if( ord[i] == -1 )
	{
		par[i] = -1, root_children = 0;
		tarjan_dfs( i );
		art[i] = root_children > 1;
	}
}
