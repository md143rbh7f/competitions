#include <string>

using namespace std;

struct KingXNewBaby
{
	string isValid( string name )
	{
		int n = name.size();
		if( n != 8 ) return "NO";
		int last = -1, cnt = 0;
		for( int i = 0; i < n; i++ ) if( name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u' )
		{
			cnt++;
			if( last != -1 && name[i] != name[last] ) return "NO";
			last = i;
		}
		if( cnt != 2 ) return "NO";
		return "YES";
	}
};
