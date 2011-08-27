#include <cmath>
#include <vector>

using namespace std;

int INF = 9001, p[51], d0[51], d1[51], n, s, t, ans = INF;

struct CirclesCountry
{
	int leastBorders( vector<int> cx, vector<int> cy, vector<int> cr, int x0, int y0, int x1, int y1 )
	{
		cx.push_back(0), cy.push_back(0), cr.push_back(INF);
		s = t = n = cx.size();
		for( int i = 0; i < n; i++ )
		{
			if( hypot( cx[i] - x0, cy[i] - y0 ) < cr[i] && cr[i] < cr[s] ) s = i;
			if( hypot( cx[i] - x1, cy[i] - y1 ) < cr[i] && cr[i] < cr[t] ) t = i;
			p[i] = n, d0[i] = d1[i] = INF;
			for( int j = 0; j < n; j++ ) if( hypot( cx[i] - cx[j], cy[i] - cy[j] ) < cr[j] && cr[i] < cr[j] && cr[j] < cr[p[i]] ) p[i] = j;
		}
		d0[s] = d1[t] = 0;
		for( int i = s; i != n; i = p[i] ) d0[p[i]] = d0[i] + 1;
		for( int i = t; i != n; i = p[i] ) d1[p[i]] = d1[i] + 1;
		for( int i = 0; i <= n; i++ ) ans = min( ans, d0[i] + d1[i] );
		return ans;
	}
};
