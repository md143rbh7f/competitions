#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define MAX 1000005

struct line
{
	int r0, c0, r1, c1;
	line( int _r0, int _c0, int _r1, int _c1 ) : r0(_r0), c0(_c0), r1(_r1), c1(_c1) {}
};

inline bool operator<( const line & a, const line & b )
{
	if( a.r0 != b.r0 ) return a.r0 < b.r0;
	if( a.c0 != b.c0 ) return a.c0 < b.c0;
	if( a.r1 != b.r1 ) return a.r1 < b.r1;
	return a.c1 < b.c1;
}

int T, R, C, tree[MAX], ans_r, ans_c;
long long num_intersections;
map< int, vector<int> > mir_r, mir_c;
map< int, map<int,bool> > mir_type;
vector<line> v0, h0, v1, h1;

int find_adj( vector<int> & v, int x, bool inc, int inf )
{
	int l = 0, r = v.size() - 1;
	while( l < r )
	{
		int m = ( l + r ) / 2;
		if( v[m] < x ) l = m + 1;
		else r = m;
	}
	l += inc ? 1 : -1;
	
	int xx;
	if( l < 0 ) xx = 0;
	else if( l < v.size() ) xx = v[l];
	else xx = inf;
	return xx;
}

void fire_laser( int r, int c, int dir, vector<line> & v, vector<line> & h )
{
	while(true)
	{
		bool inc = dir >> 1;
		if( dir % 2 )
		{
			int cc = find_adj( mir_r[r], c, inc, C+1 );
			h.push_back( line( r, inc ? c : cc, r, inc ? cc : c ) );
			c = cc;
		}
		else
		{
			int rr = find_adj( mir_c[c], r, inc, R+1 );
			v.push_back( line( inc ? r : rr, c, inc ? rr : r, c ) );
			r = rr;
		}
		if( r < 1 || r > R || c < 1 || c > C ) break;
		dir ^= 1 ^ ( mir_type[r][c] << 1 );
	}

	sort( v.begin(), v.end() );
	sort( h.begin(), h.end() );
}

void tree_edit( int x, int d )
{
	for( ; x <= R || x <= C; x += x&(-x) ) tree[x] += d;
}

int tree_sum( int x )
{
	int ans = 0;
	for( ; x; x -= x&(-x) ) ans += tree[x];
	return ans;
}

void find_intersections( vector<line> & v, vector<line> & h )
{
	bool found = false;
	set<line> window;

	for( int i = 0, j = 0; i < h.size(); i++ )
	{
		line & cur_h = h[i];
		if( cur_h.c1 - cur_h.c0 <= 1 ) continue;

		while( !window.empty() )
		{
			line cur_v = *(window.begin());
			if( cur_v.r0 > cur_h.r0 ) break;
			tree_edit( cur_v.c0, -1 );
			window.erase( window.begin() );
		}

		for( ; j < v.size(); j++ )
		{
			line & cur_v = v[j];
			if( cur_v.r0 >= cur_h.r0 ) break;
			if( cur_v.r1 <= cur_h.r1 ) continue;
			tree_edit( cur_v.c0, 1 );
			window.insert( line( cur_v.r1, cur_v.c1, cur_v.r0, cur_v.c0 ) );
		}

		int base = tree_sum( cur_h.c0 ), cnt = tree_sum( cur_h.c1 - 1 ) - base;
		num_intersections += cnt;
		if( !found && cnt )
		{
			found = true;
			int best_r = cur_h.r0, best_c, l = cur_h.c0 + 1, r = cur_h.c1 - 1;
			while( l < r )
			{
				int m = ( l + r ) / 2;
				if( tree_sum( m ) > base ) r = m;
				else l = m + 1;
			}
			best_c = l;
			if( best_r < ans_r || ( best_r == ans_r && best_c < ans_c ) )
			{
				ans_r = best_r;
				ans_c = best_c;
			}
		}
	}

	foreach( it, window ) tree_edit( it->c0, -1 );
}

void run()
{
	v0.clear(), h0.clear(), v1.clear(), h1.clear();
	printf( "Case %d: ", T );

	fire_laser( 1, 0, 3, v0, h0 );
	if( h0.back().r1 == R && h0.back().c1 == C+1 )
	{
		printf( "0\n" );
		return;
	}
	fire_laser( R, C+1, 1, v1, h1 );

	num_intersections = 0;
	ans_r = ans_c = MAX;
	find_intersections( v0, h1 ), find_intersections( v1, h0 );

	if( num_intersections == 0 ) printf( "impossible\n" );
	else printf( "%lld %d %d\n", num_intersections, ans_r, ans_c );
}

void add_mirror( int r, int c, bool flag )
{
	mir_r[r].push_back(c), mir_c[c].push_back(r);
	mir_type[r][c] = flag;
}

int main()
{
	for( T = 1; ; T++ )
	{
		int m, n, r, c;
		cin >> R >> C >> m >> n;
		if( cin.fail() ) break;

		mir_r.clear(), mir_c.clear(), mir_type.clear();
		add_mirror( 1, 0, true ), add_mirror( R, C+1, true );
		for( int i = 0; i < m + n; i++ )
		{
			cin >> r >> c;
			add_mirror( r, c, i < m );
		}
		foreach( it, mir_r ) sort( it->second.begin(), it->second.end() );
		foreach( it, mir_c ) sort( it->second.begin(), it->second.end() );

		run();
	}
	return 0;
}
