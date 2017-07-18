#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

char buf[2][1010];
int n, tax;

long long calc( vector<int> & remove, vector<int> & add, long long base )
{
	long long tot = base * ( add.size() + remove.size() );
	sort( add.begin(), add.end() );
	sort( remove.begin(), remove.end() );
	for( int i = 0; i < remove.size(); i++ )
		tot += ( remove.size() - i - 1 ) * remove[i];
	for( int i = 0; i < add.size(); i++ )
		tot += ( add.size() - i ) * add[i];
	return tot;
}

int main()
{
	for( int case_num = 1; ; case_num++ )
	{
		scanf( "%d", &n );
		if(!n) break;
		scanf( "%s%s", buf[0], buf[1] );
		vector<int> add, remove, both;
		long long base = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d", &tax );
			if( buf[0][i] == '1' && buf[1][i] == '1' )
			{
				base += tax;
				both.push_back(tax);
			}
			else if( buf[0][i] == '1' ) remove.push_back( tax );
			else if( buf[1][i] == '1' ) add.push_back( tax );
		}
		long long ans = calc( remove, add, base );
		sort( both.begin(), both.end() );
		for( int i = both.size()-1; i >= 0; i-- )
		{
			base -= both[i];
			remove.push_back( both[i] );
			add.push_back( both[i] );
			ans = min( ans, calc( remove, add, base ) );
		}
		printf( "Case %d: %lld\n", case_num, ans );
	}
	return 0;
}
