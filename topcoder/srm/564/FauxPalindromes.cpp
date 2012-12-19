#include <string>

using namespace std;

bool is( string s )
{
	int n = s.size();
	for( int i = 0; i < n; i++ ) if( s[i] != s[n-i-1] ) return false;
	return true;
}

string faux( string s )
{
	string ret;
	ret += s[0];
	int n = s.size();
	for( int i = 1; i < n; i++ ) if( s[i] != s[i-1] ) ret += s[i];
	return ret;
}

struct FauxPalindromes
{
	string classifyIt( string s )
	{
		if( is( s ) ) return "PALINDROME";
		if( is( faux( s ) ) ) return "FAUX";
		return "NOT EVEN FAUX";
	}
};
