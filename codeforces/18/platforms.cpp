#include <cstdio>

typedef long long ll;

using namespace std;

int main()
{
	int n, d, m, l;
	ll p = 0;
	scanf( "%d%d%d%d", &n, &d, &m, &l );
	while(1)
	{
		if( p%m>l || p/n>=m )
		{
			printf( "%lld", p );
			break;
		}
		if( p && p%m==0 )
		{
			printf( "%lld", (((ll)n*m+d-1)/d)*d );
			break;
		}
		p += d;
	}
	return 0;
}
