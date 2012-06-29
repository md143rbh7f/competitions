#include <cstdio>
#include <set>

using namespace std;

multiset<int> lo, hi;

void rebalance()
{
	if( lo.size() < hi.size() )
	{
		int tmp = *hi.begin();
		lo.insert( tmp );
		hi.erase( hi.find(tmp) );
	}
	else if( lo.size() > hi.size() + 1 )
	{
		int tmp = *lo.rbegin();
		hi.insert( tmp );
		lo.erase( lo.find(tmp) );
	}
}

void error()
{
	printf( "Wrong!\n" );
}

void print_median()
{
	if( lo.empty() ) error();
	else if( lo.size() > hi.size() ) printf( "%d\n", *lo.rbegin() );
	else
	{
		long long med = (long long) *lo.rbegin() + *hi.begin();
		printf( med % 2 ? "%.1lf\n" : "%.0lf\n", 0.5 * med );
	}
}

int main()
{
	char cmd[2];
	int n, num;
	scanf( "%d", &n );
	while(n--)
	{
		scanf( "%s%d", cmd, &num );
		if( cmd[0] == 'a' )
		{
			if( lo.empty() || num <= *lo.rbegin() ) lo.insert( num );
			else hi.insert( num );
		}
		else
		{
			if( lo.find(num) != lo.end() ) lo.erase( lo.find(num) );
			else if( hi.find(num) != hi.end() ) hi.erase( hi.find(num) );
			else
			{
				error();
				continue;
			}
		}
		rebalance();
		print_median();
	}
	return 0;
}
