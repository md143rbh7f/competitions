#include <algorithm>
#include <cstdio>
#include <list>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MAX 1024

int n, m, a, b, min1[MAX][MAX], min2[MAX][MAX], h[MAX][MAX];
bool built[MAX][MAX];
ll sum[MAX][MAX];

int main()
{
	scanf( "%d%d%d%d", &n, &m, &a, &b );
	rep1(i,n) rep1(j,m)
	{
		scanf( "%I64d", &h[i][j] );
		sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + h[i][j];
	}
	rep1(i,n)
	{
		list<int> q;
		rep1(j,m)
		{
			if( !q.empty() && q.front() == j-b ) q.pop_front();
			while( !q.empty() && h[i][j] <= h[i][q.back()] ) q.pop_back();
			q.push_back(j);
			min1[i][j] = h[i][q.front()];
		}
	}
	rep1(j,m)
	{
		list<int> q;
		rep1(i,n)
		{
			if( !q.empty() && q.front() == i-a ) q.pop_front();
			while( !q.empty() && min1[i][j] <= min1[q.back()][j] ) q.pop_back();
			q.push_back(i);
			min2[i][j] = min1[q.front()][j];
		}
	}
	vector< pair<ll, pair<int,int> > > v;
	for( int i = a; i <= n; i++ ) for( int j = b; j <= m; j++ )
	{
		ll tot = sum[i][j] - sum[i-a][j] - sum[i][j-b] + sum[i-a][j-b];
		ll level = a * b * (ll) min2[i][j];
		v.push_back( make_pair( tot-level, make_pair( i-a+1, j-b+1 ) ) );
	}
	sort( v.begin(), v.end() );
	list<int> ans;
	for( int k = 0; k < v.size(); k++ )
	{
		int x = v[k].second.first, y = v[k].second.second;
		if( built[x][y] || built[x+a-1][y] || built[x][y+b-1] || built[x+a-1][y+b-1] ) continue;
		for( int i = 0; i < a; i++ ) for( int j = 0; j < b; j++ ) built[x+i][y+j] = true;
		ans.push_back(k);
	}
	printf( "%d\n", (int) ans.size() );
	for( list<int>::iterator it = ans.begin(); it != ans.end(); it++ )
	{
		int k = *it;
		ll dirt = v[k].first;
		int x = v[k].second.first, y = v[k].second.second;
		printf( "%d %d %I64d\n", x, y, dirt );
	}
	return 0;
}
