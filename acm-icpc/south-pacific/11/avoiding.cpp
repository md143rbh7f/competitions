#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

int K, T = 60 * 12, t[3], h, m, p[3], tmp[3];
set<int> possible;

int main()
{
	scanf( "%d", &K );
	while(K--)
	{
		for( int i = 0; i < 3; i++ )
		{
			scanf( "%d:%d", &h, &m );
			t[i] = 60 * h + m;
			p[i] = i;
		}
		possible.clear();
		do
		{
			for( int i = 0; i < 3; i++ ) tmp[i] = t[p[i]];
			while( tmp[1] <= tmp[0] ) tmp[1] += T;
			while( tmp[2] <= tmp[1] ) tmp[2] += T;
			bool ok = true;
			if( tmp[1] - tmp[0] > 480 ) ok = false;
			if( tmp[2] - tmp[1] > 480 ) ok = false;
			if( tmp[2] - tmp[1] != tmp[1] - tmp[0] ) ok = false;
			if(ok) possible.insert(tmp[1]%T);
		}
		while(next_permutation(p,p+3));
		if( possible.size() == 1 )
		{
			int correct_hour = *possible.begin() / 60, correct_minute = *possible.begin() % 60;
			if( correct_hour == 0 ) correct_hour = 12;
			printf( "The correct time is %d:%02d\n", correct_hour, correct_minute );
		}
		else printf( "Look at the sun\n" );
	}
	return 0;
}
