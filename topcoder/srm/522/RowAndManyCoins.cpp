#include <string>

using namespace std;

struct RowAndManyCoins
{
	string getWinner( string s )
	{
		return ( s[0] == 'A' || s[s.size()-1] == 'A' ) ? "Alice" : "Bob";
	}
};
