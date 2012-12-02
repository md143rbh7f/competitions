#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define N 105
#define M 50

int rect[N][N], clip[M][M], code['Z'];
ll cnt[4], d[4];

struct PastingPaintingDivOne
{
	vector<ll> countColors( vector<string> _clip, int t )
	{
		code['R'] = 1, code['G'] = 2, code['B'] = 3;
		int n = _clip.size(), m = _clip[0].size();
		rep(i,n) rep(j,m) clip[i][j] = code[_clip[i][j]];
		int s = 0;
		for( ; s < t && s < M; s++ )
		{
			REP(i,1,4) d[i] = 0;
			rep(i,n) rep(j,m) if( clip[i][j] )
			{
				int & c = rect[i+s][j+s];
				d[c]--;
				c = clip[i][j];
				d[c]++;
			}
			REP(i,1,4) cnt[i] += d[i];
		}
		t -= s;
		REP(i,1,4) cnt[i] += t * d[i];
		return vector<ll>( cnt + 1, cnt + 4 );
	}
};
