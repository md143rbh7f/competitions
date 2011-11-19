#include <cmath>
#include <string>
#include <vector>

using namespace std;

int x[26], y[26];

struct AlphabetPath
{
	string doesItExist( vector<string> g )
	{
		for( int i = 0; i < g.size(); i++ ) for( int j = 0; j < g[0].size(); j++ )	if( g[i][j] != '.' ) x[g[i][j]-'A'] = i, y[g[i][j]-'A'] = j;
		bool ok = true;
		for( int c = 1; c < 26; c++ ) if( abs( x[c] - x[c-1] ) + abs( y[c] - y[c-1] ) > 1 ) ok = false;
		return ok ? "YES" : "NO";
	}
};
