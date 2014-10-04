#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 405

ll x[N], y[N];
double zs[N];

struct SimilarRatingGraph
{
double maxLength(vi _x, vi _y)
{
	int n = _x.size() - 1;
	rep(i, n)
		x[i] = _x[i + 1] - _x[i], y[i] = _y[i + 1] - _y[i], zs[i + 1] = zs[i] + hypot(x[i], y[i]);
	double ans = 0;
	rep(i, n) range(j, i + 1, n)
	{
		int k = 0;
		while(j + k < n && x[i + k] * x[j] == x[j + k] * x[i] && y[i + k] * x[j] == y[j + k] * x[i])
			k++;
		ans = max(ans, max(zs[i + k] - zs[i], zs[j + k] - zs[j]));
	}
	return ans;
}
};
