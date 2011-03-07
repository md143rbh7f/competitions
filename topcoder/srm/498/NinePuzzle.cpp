#include <string>

using namespace std;

string s[2];
int cnt[2][4];

struct NinePuzzle
{
	int getMinimumCost( string x, string y )
	{
		s[0] = x, s[1] = y;
		for( int i = 0; i < 2; i++ ) for( int j = 0; j <= 9; j++ ) switch(s[i][j])
		{
			case 'R': cnt[i][0]++; break;
			case 'G': cnt[i][1]++; break;
			case 'B': cnt[i][2]++; break;
			case 'Y': cnt[i][3]++; break;
		}
		int ans = 0;
		for( int i = 0; i < 4; i++ )
		{
			if( cnt[0][i] < cnt[1][i] ) ans += cnt[1][i]-cnt[0][i];
			if( cnt[0][i] > cnt[1][i] ) ans += cnt[0][i]-cnt[1][i];
		}
		return ans/2;
	}
};
