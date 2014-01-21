#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define M (1<<15)

int t, n, q;
vector<int> index[2*M];

void init()
{
	for( int i = 0; i < 2*M; i++ ) index[i].clear();
	for( int i = 0; i < n; i++ )
	{
		int x;
		scanf( "%d", &x );
		index[x+M].push_back(i);
	}
	for( int i = M-1; i; i-- )
	{
		int j = 2*i, k = 2*i+1;
		index[i].resize( index[j].size() + index[k].size() );
		merge( index[j].begin(), index[j].end(), index[k].begin(), index[k].end(), index[i].begin() );
	}
}

bool intersects( int range, int a, int b )
{
	vector<int>::iterator lo = lower_bound( index[range].begin(), index[range].end(), a );
	return lo != index[range].end() && *lo < b;
}

int query( int x, int a, int b )
{
	int range = 1;
	for( int bit = M >> 1; bit; bit >>= 1 )
	{
		int good = 2 * range + ( x & bit ? 0 : 1 );
		int bad = 2 * range + ( x & bit ? 1 : 0 );
		if( intersects( good, a, b ) ) range = good;
		else range = bad;
	}
	return x ^ ( range - M );
}

int main()
{
	scanf( "%d", &t );
	while(t--)
	{
		scanf( "%d%d", &n, &q );
		init();
		while(q--)
		{
			int x, a, b;
			scanf( "%d%d%d", &x, &a, &b );
			a--;
			printf( "%d\n", query( x, a, b ) );
		}
	}
	return 0;
}
