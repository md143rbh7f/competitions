#include <cstdio>
#include <list>

using namespace std;

#define N 100005

int n, k, x[N];
long long tot, bad[N];

int main()
{
	scanf( "%d%d", &n, &k );
	for( int i = 1; i <= n; i++ ) scanf( "%d", &x[i] ), tot += x[i];
	
	list<int> q;
	q.push_back(0);
	for( int i = 1; i <= n+1; i++ )
	{
		bad[i] = x[i] + bad[q.front()];
		while( !q.empty() && bad[i] <= bad[q.back()] ) q.pop_back();
		q.push_back(i);
		if( q.front() < i-k ) q.pop_front();
	}

	printf( "%lld\n", tot - bad[n+1] );

	return 0;
}
