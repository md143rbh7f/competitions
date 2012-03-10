#include <algorithm>
#include <cstdio>

using namespace std;

struct box
{
	int col, len, id;
	bool operator<(const box & o) const
	{
		if( col != o.col ) return col < o.col;
		if( len != o.len ) return len > o.len;
		return id < o.id;
	}
};

struct color
{
	int start, len;
	bool operator<(const color & o) const
	{
		if( len != o.len ) return len < o.len;
		return start < o.start;
	}
};

#define MAX 100005

box b[MAX];
color c[MAX];
long long max_sum[MAX];
int max_col[MAX];

int main()
{
	int n;
	scanf( "%d\n", &n );
	for( int i = 0; i < n; i++ )
	{
		b[i].id = i+1;
		scanf( "%d%d", &(b[i].col), &(b[i].len) );
	}
	sort(b,b+n);

	int m = 0;
	for( int i = 0; i < n; m++ )
	{
		int j = i;
		while( j < n && b[j].col == b[i].col ) j++;
		c[m].start = i, c[m].len = j - i;
		i = j;
	}
	sort(c,c+m);

	long long ans = 0;
	int x = 0, y = 0;
	for( int i = 0; i < m; i++ )
	{
		long long sum = 0;
		for( int j = 0; j < c[i].len; j++ )
		{
			sum += b[c[i].start+j].len;
			for( int k = j; k < j+2; k++ ) if( max_sum[k] && sum + max_sum[k] > ans ) 
			{
				ans = sum + max_sum[k];
				x = max_col[k], y = i;
			}
		}
		if( sum > max_sum[c[i].len] )
		{
			max_sum[c[i].len] = sum;
			max_col[c[i].len] = i;
		}
	}

	printf( "%I64d\n%d\n", ans, 2 * c[x].len + ( c[y].len > c[x].len ) );
	for( int i = 0; i < c[x].len; i++ ) printf( "%d %d ", b[c[y].start+i].id, b[c[x].start+i].id );
	if( c[y].len > c[x].len ) printf( "%d", b[c[y].start+c[x].len].id );
	printf( "\n" );

	return 0;
}
