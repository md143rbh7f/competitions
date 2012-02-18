#include <string>
#include <vector>

using namespace std;

bool seenr[55], seenc[55];
vector<string> map;
int n, m, nonempty, connected;

void recr(int);
void recc(int);

void recr( int i )
{
	if( seenr[i] ) return;
	seenr[i] = true;
	connected++;
	for( int j = 0; j < m; j++ ) if( map[i][j] == '#' ) recc(j);
}

void recc( int j )
{
	if( seenc[j] ) return;
	seenc[j] = true;
	connected++;
	for( int i = 0; i < n; i++ ) if( map[i][j] == '#' ) recr(i);
}

struct MagicBoard
{
	string ableToUnlock( vector<string> _map )
	{
		map = _map;
		n = map.size();
		m = map[0].size();
		int r1 = 0, c1 = 0, startr = -1;
		for( int i = 0; i < n; i++ )
		{
			int cnt = 0;
			for( int j = 0; j < m; j++ ) if( map[i][j] == '#' ) cnt++;
			if( cnt % 2 ) r1++;
			if( cnt > 0 )
			{
				nonempty++;
				if( startr == -1 ) startr = i;
			}
		}
		for( int j = 0; j < m; j++ )
		{
			int cnt = 0;
			for( int i = 0; i < n; i++ ) if( map[i][j] == '#' ) cnt++;
			if( cnt % 2 ) c1++;
			if( cnt > 0 ) nonempty++;
		}
		if( c1 + r1 > 2 || r1 == 2 ) return "NO";
		recr( startr );
		if( connected < nonempty ) return "NO";
		return "YES";
	}
};
