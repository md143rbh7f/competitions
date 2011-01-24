#include <cstdio>
#include <map>

using namespace std;

int n, a, l, best, bestl;
map<int,int> last;

int main()
{
	for( n = 2; n < 1000; n++ ) for( a = 1, l = 0, last.clear(); ; )
	{
		while( a < n ) a *= 10, l++;
		if( last.count(a) )
		{
			if( bestl < l-last.count(a) ) bestl = l-last[a], best = n;
			break;
		}
		last[a] = l;
		a -= (a/n)*n;
		if(!a) break;
	}
	printf( "%d\n", best );
	return 0;
}
