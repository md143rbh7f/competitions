#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define L 9

int p[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, i, j, k, a, b, c;
long long ans;
set<int> m;

int main()
{
	do
	{
		a = p[0];
		for( i = 1; i < L; i++ )
		{
			b = p[i];
			for( j = i+1; j < L; j++ )
			{
				c = 0;
				for( k = j; k < L; k++ ) c = 10*c + p[k];
				if( a*b == c ) m.insert(c);
				b = 10*b+p[j];
			}
			a = 10*a+p[i];
		}
	}
	while(next_permutation(p,p+L));
	foreach(i,m) ans += *i;
	printf( "%lld\n", ans );
	return 0;
}
