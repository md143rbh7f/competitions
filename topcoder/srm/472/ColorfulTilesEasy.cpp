#include <string>

using namespace std;

class ColorfulTilesEasy
{
	public:
	int theMin( string room )
	{
		int n = room.size(), ans = 10;
		for( int i = 0; i < 1<<n; i++ )
		{
			bool works = true;
			int c = 0;
			for( int j = 0; j < n; j++ )
			{
				if( i&(1<<j) ) c++;
				else if( j && room[j]==room[j-1] && !(i&(1<<(j-1))) ) works = false;
			}
			if( works && c<ans ) ans = c;
		}
		return ans;
	}
};
