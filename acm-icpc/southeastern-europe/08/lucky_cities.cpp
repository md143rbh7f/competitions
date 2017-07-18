#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 100005

vector<int> g[N];
map< int, vector<int> > _h[N], * h;
int n, m, ord[N], low[N], par[N], t, q[N];
int _sta[N], _stb[N], * sta, * stb;
bool odd[N];

inline void push( int a, int b ) { *(sta++) = a, *(stb++) = b; }
void pop( int a, int b )
{
	h->clear();
	do
	{
		sta--, stb--;
		(*h)[*sta].push_back( *stb ), (*h)[*stb].push_back( *sta );
	}
	while( *sta != a || *stb != b );
	h++;
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
			if( low[*j] >= ord[i] ) pop( i, *j );
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
	h = _h, sta = _sta, stb = _stb, t = 0;
	for( int i = 0; i < n; i++ ) ord[i] = -1;
	for( int i = 0; i < n; i++ ) if( ord[i] == -1 )
	{
		par[i] = -1;
		tarjan_dfs( i );
	}
}

void mark_odd_cycles()
{
	map<int,bool> col;
	for( int i = 0; i < n; i++ ) odd[i] = false;
	for( map< int, vector<int> > * k = _h; k != h; k++ )
	{
		col.clear();

		int * i = q, * ii = i + 1;
		*i = k->begin()->first, col[*i] = false;
		while( i < ii )
		{
			foreach( j, (*k)[*i] )
			{
				if( !col.count( *j ) ) col[*j] = !col[*i], *(ii++) = *j;
				else if( col[*j] == col[*i] ) goto good;
			}
			i++;
		}
		continue;

		good:
		foreach( it, *k ) odd[it->first] = true;
	}
}

void run()
{
	scanf( "%d%d", &n, &m );
	for( int i = 0; i < n; i++ ) g[i].clear();
	for( int i = 0; i < m; i++ )
	{
		int a, b;
		scanf( "%d%d", &a, &b );
		a--, b--;
		g[a].push_back( b ), g[b].push_back( a );
	}

	tarjan();
	mark_odd_cycles();

	int tot = 0;
	for( int i = 0; i < n; i++ ) tot += odd[i];
	printf( "%d\n", tot );
}

int main()
{
	int t;
	scanf( "%d", &t );
	while( t-- ) run();
	return 0;
}
