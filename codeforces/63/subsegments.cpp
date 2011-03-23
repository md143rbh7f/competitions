#include <cstdio>
#include <map>
#include <set>

using namespace std;

set<int> one;
map<int,int> two;
int n, k, a[100000], i;

void process( int x )
{
	if(two[x]==1) one.insert(x);
	else one.erase(x);
}

void print()
{
	if(one.rbegin()==one.rend()) printf( "Nothing\n" );
	else printf( "%d\n", *one.rbegin() );
}

int main()
{
	scanf( "%d%d", &n, &k );
	for( i = 0; i < n; i++ )
	{
		scanf( "%d", &a[i] );
		if( i >= k )
		{
			print();
			two[a[i-k]]--;
			process(a[i-k]);
		}
		two[a[i]]++;
		process(a[i]);
	}
	print();
	return 0;
}
