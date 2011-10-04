#include <vector>

using namespace std;

struct SRMCodingPhase
{
	int countScore( vector<int> pts, vector<int> t, int luck )
	{
		int MAX = 75, best = 0;
		for( int m = 0; m < 1<<3; m++ )
		{
			int ttime = 0;
			for( int i = 0; i < 3; i++ ) if((m>>i)&1) ttime += t[i];
			if( ttime - luck > MAX ) continue;
			int spent[3], have = luck, tot = 0;
			for( int i = 0; i < 3; i++ ) if((m>>i)&1)
			{
				if( t[i] > MAX ) have -= t[i] - MAX, spent[i] = MAX;
				else spent[i] = t[i];
			}
			for( int i = 2; i >= 0; i-- ) if((m>>i)&1)
			{
				if( spent[i] > have ) spent[i] -= have, have = 0;
				else have -= spent[i] - 1, spent[i] = 1;
				tot += pts[i] - spent[i] * ( 1<<(i+1) );
			}
			if( tot > best ) best = tot;
		}
		return best;
	}
};
