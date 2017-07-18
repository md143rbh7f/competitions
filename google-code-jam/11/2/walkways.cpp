#include <algorithm>
#include <cstdio>
#include <utility>

#define THE_YEAR_WE_MAKE_CONTACT 2010

using namespace std;

int T, case_num, x, s, r, t, n, a, b, w, m, prev;
double have, ans, run, dist;
pair<int,int> segments[THE_YEAR_WE_MAKE_CONTACT];

int main()
{
	scanf( "%d", &T );
	for( int case_num = 1; case_num <= T; case_num++ )
	{
		scanf( "%d%d%d%d%d", &x, &s, &r, &t, &n );
		prev = m = 0;
		for( int i = 0; i < n; i++ )
		{
			scanf( "%d%d%d", &a, &b, &w );
			segments[m++] = make_pair( s, a - prev );
			segments[m++] = make_pair( s + w, b - a );
			prev = b;
		}
		segments[m++] = make_pair( s, x - prev );
		sort( segments, segments + m );
		have = t, ans = 0;
		for( int i = 0; i < m; i++ )
		{
			if( have > 0 )
			{
				run = min( 1.0 * segments[i].second / ( segments[i].first + r - s ), have );
				dist = run * ( segments[i].first + r - s );
				ans += run + ( segments[i].second - dist ) / segments[i].first;
				have -= run;
			}
			else ans += 1.0 * segments[i].second / segments[i].first;
		}
		printf( "Case #%d: %.9f\n", case_num, ans );
	}
	return 0;
}
