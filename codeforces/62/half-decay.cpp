#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

char buf[6];
int h, q, v, e;
map<int,int> sum, el;

double rec( int x, int best )
{
	if( sum[x] <= best ) return best;
	return 0.5 * ( rec( x*2, max( best, el[x] + sum[x*2+1] ) ) + rec( x*2+1, max( best, el[x] + sum[x*2] ) ) );
}

int main()
{
	scanf( "%d%d", &h, &q );
	while(q--)
	{
		scanf( "%s", buf );
		if( buf[0]=='a' )
		{
			scanf( "%d%d", &v, &e );
			el[v] += e;
			while(v)
			{
				sum[v] += e;
				v /= 2;
			}
		}
		else printf( "%.9f\n", rec(1,0) );
	}
	return 0;
}
