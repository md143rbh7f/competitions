#include <string>
#include <vector>

using namespace std;

struct GogoXCake
{
	string solve( vector<string> cake, vector<string> cutter )
	{
		for( int i = 0; i + cutter.size() <= cake.size(); i++ )
		for( int j = 0; j + cutter[0].size() <= cake[0].size(); j++ )
		{
			bool ok = true;
			for( int k = 0; k < cutter.size(); k++ ) for( int l = 0; l < cutter[0].size(); l++ ) if( cutter[k][l] == '.' && cake[i+k][j+l] == 'X' ) ok = false;
			if(ok) for( int k = 0; k < cutter.size(); k++ ) for( int l = 0; l < cutter[0].size(); l++ ) if( cutter[k][l] == '.' ) cake[i+k][j+l] = 'X';
		}
		for( int i = 0; i < cake.size(); i++ ) for( int j = 0; j < cake[0].size(); j++ ) if( cake[i][j] == '.' ) return "NO";
		return "YES";
	}
};
