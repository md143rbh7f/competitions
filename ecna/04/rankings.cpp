#include <algorithm>
#include <cstdio>

using namespace std;

char buf[5], bestp[6];
int a[100][5], n, q[5], p[5], best;

int main()
{
	while(1)
	{
		scanf( "%d", &n );
		if(!n) break;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%s", buf );
			for( int j = 0; j < 5; j++ ) a[i][buf[j]-'A'] = j;
		}
		for( int i = 0; i < 5; i++ ) p[i] = i;
		best = 10000;
		do
		{
			for( int i = 0; i < 5; i++ ) q[p[i]] = i;
			int dist = 0;
			for( int k = 0; k < n; k++ )
			for( int i = 0; i < 5; i++ )
			for( int j = i+1; j < 5; j++ )
				if( ( q[i] > q[j] && a[k][i] < a[k][j] ) || ( q[i] < q[j] && a[k][i] > a[k][j] ) )
					dist++;
			if( dist < best )
			{
				best = dist;
				for( int i = 0; i < 5; i++ ) bestp[i] = p[i]+'A';
			}
		}
		while( next_permutation( p, p+5 ) );
		printf( "%s is the median ranking with value %d.\n", bestp, best );
	}
	return 0;
}
