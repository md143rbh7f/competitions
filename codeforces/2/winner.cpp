#include <cstdio>
#include <map>
#include <string>

using namespace std;

int n, i, d[1000], hi;
char s[1000][33];
map<string,int> v, vv;
map<string,int>::iterator it;

int main()
{
	scanf( "%d", &n );
	for( i = 0; i < n; i++ )
	{
		scanf( "%s%d", s[i], &d[i] );
		v[s[i]] += d[i];
	}
	for( it = v.begin(); it != v.end(); it++ ) if( hi < it->second ) hi = it->second;
	for( i = 0; i < n; i++ ) if( v[s[i]]==hi )
	{
		vv[s[i]] += d[i];
		if( vv[s[i]] >= hi )
		{
			printf( "%s", s[i] );
			break;
		}
	}
	return 0;
}
