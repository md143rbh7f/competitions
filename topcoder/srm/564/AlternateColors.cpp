#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

string run( vector< pair<ll,string> > & c, ll k )
{
	int n = c.size();
	ll x = min_element( c.begin(), c.end() )->first;
	if( k < n * x ) return c[k%n].second;
	vector< pair<ll,string> > next;
	for( int i = 0; i < c.size(); i++ )
	{
		c[i].first -= x;
		if( c[i].first ) next.push_back( c[i] );
	}
	return run( next, k - n * x );
}

struct AlternateColors
{
	string getColor( ll r, ll g, ll b, ll k )
	{
		vector< pair<ll,string> > c( 3 );
		c[0] = make_pair( r, "RED" );
		c[1] = make_pair( g, "GREEN" );
		c[2] = make_pair( b, "BLUE" );
		return run( c, k - 1 );
	}
};
