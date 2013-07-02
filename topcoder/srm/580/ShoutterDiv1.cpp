#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define iter(i,a,b) for(__typeof__(a) i=(a);i!=(b);i++)
#define rep(i,n) iter(i,0,n)
#define acc(f,x,y) x=f(x,y)

#define N 2505
#define INF 123456789

int n, s[N], t[N], min_s = INF, min_t = INF, mem_s[N], mem_t[N];

void parse( int coeff, vs * v, int i, int j, int & ans )
{
	rep(k,4) ans = 10 * ans + v[k][i][j] - '0';
	ans *= coeff;
}

int rec( int i, int * u, int * v, int min_v, int * mem )
{
	int & ans = mem[i];
	if( ans != -1 ) return ans;
	if( -u[i] <= min_v ) return ans = 0;
	int j = i;
	rep(k,n) if( -u[i] <= v[k] && u[k] > u[j] ) j = k;
	if( j == i ) return ans = INF;
	return ans = 1 + rec( j, u, v, min_v, mem );
}

int work( int i )
{
	return rec( i, s, t, min_t, mem_s ) + rec( i, t, s, min_s, mem_t );
}

struct ShoutterDiv1
{
	int count( vs s3, vs s2, vs s1, vs s0, vs t3, vs t2, vs t1, vs t0 )
	{
		vs ss[] = { s3, s2, s1, s0 }, ts[] = { t3, t2, t1, t0 };
		rep(i,s0.size()) rep(j,s0[i].size())
		{
			parse( -1, ss, i, j, s[n] ), parse( 1, ts, i, j, t[n] );
			acc( min, min_s, s[n] ), acc( min, min_t, t[n] );
			mem_s[n] = mem_t[n] = -1;
			n++;
		}
		long long ans = 0;
		rep(i,n)
		{
			int best = work( i );
			rep(j,n) if( s[i] <= s[j] && t[i] <= t[j] )
				acc( min, best, 1 + work( j ) );
			ans += best;
		}
		return ans < INF ? ans : -1;
	}
};
