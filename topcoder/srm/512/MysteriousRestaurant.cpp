#include <string>
#include <vector>

using namespace std;

int tot[50][50], best[50];

struct MysteriousRestaurant
{
	int maxDays( vector<string> cost, int budget )
	{
		int cur = 0;
		for( int i = 0; i < cost.size(); i++ )
		{
			best[i] = 9001;
			for( int j = 0; j < cost[0].size(); j++ )
			{
				char c = cost[i][j];
				if( c >= '0' && c <= '9' ) tot[i][j] = c-'0';
				else if( c >= 'A' && c <= 'Z' ) tot[i][j] = c-'A'+10;
				else tot[i][j] = c-'a'+36;
				if( i >= 7 ) tot[i][j] += tot[i-7][j];
				if( tot[i][j] < best[i] ) best[i] = tot[i][j];
			}
			cur = cur + best[i] - ( i >= 7 ? best[i-7] : 0 );
			if( cur > budget ) return i;
		}
		return cost.size();
	}
};
