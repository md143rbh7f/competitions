#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define N 1005

struct item
{
	int cost, id, type;
	bool operator<(const item & o) const
	{
		if( type != o.type ) return type < o.type;
		if( cost != o.cost ) return cost > o.cost;
		return id < o.id;
	}
};

item items[N];
int n, k;
vector<int> carts[N];

int main()
{
	scanf( "%d%d", &n, &k );
	for( int i = 0; i < n; i++ )
	{
		scanf( "%d%d", &(items[i].cost), &(items[i].type) );
		items[i].id = i+1;
	}
	sort( items, items + n );
	for( int i = 0, j = 0; i < n; i++ )
	{
		carts[j].push_back(i);
		if( j < k-1 ) j++;
	}
	double ans = 0;
	for( int i = 0; i < k; i++ )
	{
		bool discount = false;
		int least = 1<<30;
		for( int j = 0; j < carts[i].size(); j++ )
		{
			item & it = items[carts[i][j]];
			ans += it.cost;
			if( it.cost < least ) least = it.cost;
			if( it.type == 1 ) discount = true;
		}
		if( discount ) ans -= 0.5 * least;
	}
	printf( "%.1lf\n", ans );
	for( int i = 0; i < k; i++ )
	{
		printf( "%d", (int) carts[i].size() );
		for( int j = 0; j < carts[i].size(); j++ ) printf( " %d", items[carts[i][j]].id );
		printf( "\n" );
	}
	return 0;
}
