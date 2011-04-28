#include <string>

using namespace std;

int n, k;

bool can_swap( int a, int b )
{
	if(a>b) swap(a,b);
	int d = b-a, m = ( k - d - 1 ) / 2;
	if( d>=k || d%2==k%2 || a-m<1 || b+m>n ) return false;
	return true;
}

struct StonesGame
{
	string winner( int _n, int m, int _k, int l )
	{
		n = _n, k = _k;
		if( can_swap( m, l ) ) return "Romeo";
		bool strangelet = true;
		for( int i = 1; i <= n; i++ ) if( can_swap( m, i ) && !can_swap( i, l ) ) strangelet = false;
		if( strangelet ) return "Strangelet";
		return "Draw";
	}
};
