#include <string>

using namespace std;

bool balls[100000];

struct MathContest
{
	int countBlack( string input, int reps )
	{
		int m = input.size(), n = m*reps;
		for( int i = 0; i < reps; i++ ) for( int j = 0; j < m; j++ ) balls[i*m+j] = input[j] == 'W';
		int cnt = 0;
		bool flip = false, inv = false;
		for( int l = 0, r = n-1; l <= r; )
		{
			int cur = 0;
			if( !inv )
			{
				cur = balls[l];
				l++;
			}
			else
			{
				cur = balls[r];
				r--;
			}
			if( flip ) cur = !cur;
			if( cur == 1 ) inv = !inv;
			else
			{
				cnt++;
				flip = !flip;
			}
		}
		return cnt;
	}
};
