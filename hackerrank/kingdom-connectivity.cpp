#include <iostream>
#include <vector>

using namespace std;

#define N 10005
#define MOD 1000000000

vector<int> g1[N], g2[N];
int p[N], q[N], cnt[N];
bool seen1[N], seen2[N], ok[N];

void dfs( vector<int> * g, bool * seen, int i )
{
	if( seen[i] ) return;
	seen[i] = true;
	for( int j = 0; j < g[i].size(); j++ ) dfs( g, seen, g[i][j] );
}

int main()
{
	int n, m;
	cin >> n >> m;

	for( int i = 0; i < m; i++ )
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g1[x].push_back(y), g2[y].push_back(x);
	}

	dfs( g1, seen1, 0 ), dfs( g2, seen2, n-1 );
	int s = 0;
	for( int i = 0; i < n; i++ ) if( seen1[i] && seen2[i] )
	{
		s++;
		ok[i] = true;
	}
	if( !ok[n-1] )
	{
		cout << 0 << endl;
		return 0;
	}

	int qptr = 0;
	bool cycle = false;
	for( int i = 0; i < n; i++ ) if( ok[i] ) for( int j = 0; j < g1[i].size(); j++ ) if( ok[g1[i][j]] ) p[g1[i][j]]++;
	for( int i = 0; i < n; i++ ) if( ok[i] && p[i] == 0 ) q[qptr++] = i;
	for( int i = 0; i < s; i++ )
	{
		if( i == qptr )
		{
			cycle = true;
			break;
		}
		int x = q[i];
		for( int j = 0; j < g1[x].size(); j++ )
		{
			int y = g1[x][j];
			if( ok[y] )
			{
				p[y]--;
				if( p[y] == 0 ) q[qptr++] = y;
			}
		}
	}
	if( cycle )
	{
		cout << "INFINITE PATHS" << endl;
		return 0;
	}

	cnt[0] = 1;
	for( int i = 0; i < s; i++ )
	{
		int x = q[i];
		for( int j = 0; j < g1[x].size(); j++ )
		{
			int y = g1[x][j];
			cnt[y] = ( cnt[y] + cnt[x] ) % MOD;
		}
	}
	cout << cnt[n-1] << endl;

	return 0;
}
