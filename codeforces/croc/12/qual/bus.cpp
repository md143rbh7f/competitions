#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

#define N 100005

pair<int,int> s[N];
int n, m, ans[N];

int main()
{
	scanf( "%d%d", &n, &m );
	int t = -1;
	for( int a = 0; a < n; )
	{
		int b = a, tmp;
		while( b < n && b < a + m )
		{
			scanf( "%d%d", &tmp, &(s[b%m].first) );
			s[b%m].second = b;
			b++;
		}
		if( tmp > t ) t = tmp;
		sort( s, s + b - a );
		int x = 0;
		for( int i = a; i < b; )
		{
			t += s[i%m].first - x;
			x = s[i%m].first;
			int j = i;
			while( j < b && s[j%m].first == x ) ans[s[(j++)%m].second] = t;
			t += 1 + ( j - i ) / 2;
			i = j;
		}
		t += x;
		a = b;
	}
	for( int i = 0; i < n; i++ ) printf( "%d ", ans[i] );
	return 0;
}
