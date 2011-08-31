#include <string>

using namespace std;

struct NetworkXZeroOne
{
	string reconstruct( string msg )
	{
		bool o_even = false;
		for( int i = 0; i < msg.size(); i++ ) if( msg[i] != '?' )
		{
			if( ( !(i%2) && msg[i]=='o' ) || ( i%2 && msg[i]=='x' ) ) o_even = true;
			break;
		}
		for( int i = 0; i < msg.size(); i++ ) msg[i] = ( o_even ^ (i%2) ) ? 'o' : 'x';
		return msg;
	}
};
