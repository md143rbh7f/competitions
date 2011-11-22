#include <vector>

using namespace std;

#define MAX 1<<11

int p[MAX], q[MAX], n;

struct LongestSequence
{
	int maxLength( vector<int> c )
	{
		n = c.size();
		bool all_positive = true, all_negative = true;
		for( int i = 0; i < n; i++ )
		{
			if( c[i] < 0 ) all_positive = false;
			else all_negative = false;
		}
		if( all_positive || all_negative ) return -1;
		int best = 0;
		for( int d = MAX; d; d >>= 1 )
		{
			int m = best + d;
			for( int i = 0; i <= m; i++ ) p[i] = 0;
			for( int i = 0; i <= m; i++ ) for( int j = 0; j < n; j++ )
			{
				int k = i - c[j];
				if( k >= 0 && k <= m ) p[k]++;
			}
			int qlen = 0;
			bool ok = true;
			for( int i = 0; i <= m; i++ ) if( p[i] == 0 ) q[qlen++] = i;
			for( int i = 0; i <= m; i++ )
			{
				if( i >= qlen )
				{
					ok = false;
					break;
				}
				for( int j = 0; j < n; j++ )
				{
					int k = q[i] - c[j];
					if( k >= 0 && k <= m )
					{
						p[k]--;
						if( p[k] == 0 ) q[qlen++] = k;
					}
				}
			}
			if( ok ) best += d;
		}
		return best;
	}
};
