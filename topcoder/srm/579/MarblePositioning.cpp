#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define all(i) (i).begin(),(i).end()

double x[8];

struct MarblePositioning
{
	double totalWidth( vi r )
	{
		double ans = 1e13;
		sort(all(r));
		int n = r.size();
		do
		{
			REP(i,1,n)
			{
				x[i] = 0;
				rep(j,i) x[i] = max( x[i], x[j] + sqrt( pow( r[i] + r[j], 2.0 ) - pow( r[i] - r[j], 2.0 ) ) );
			}
			ans = min( ans, x[n-1] );
		}
		while(next_permutation(all(r)));
		return ans;
	}
};
