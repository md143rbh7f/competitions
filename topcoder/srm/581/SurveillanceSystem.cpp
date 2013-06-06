#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 55

char mapping[] = "-?+";
int cnt[N], cover[N], ans[N];
vi start[N];

struct SurveillanceSystem
{
	string getContainerInfo( string desc, vi x, int l )
	{
		foreach(i,x) cnt[*i]++;

		int n = desc.size(), sum = 0;
		for( int i = n - 1; i >= 0; i-- )
		{
			sum += ( desc[i] == 'X' ) - ( i + l < n ? desc[i+l] == 'X' : 0 );
			if( i + l <= n ) start[sum].push_back( i );
		}

		rep(i,l+1) if( cnt[i] )
		{
			foreach(j,start[i]) rep(k,l) cover[*j+k]++;
			rep(j,n) if( cover[j] )
			{
				int mark = 1 + ( start[i].size() - cover[j] < cnt[i] );
				ans[j] = max( ans[j], mark );
				cover[j] = 0;
			}
		}

		string ans_s;
		rep(i,n) ans_s += mapping[ans[i]];
		return ans_s;
	}
};
