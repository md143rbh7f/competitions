#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N 505

int xs[N], n, r, m, k, elly;
double ys[N];

struct EllysRoomAssignmentsDiv1
{
	double getAverage(vs strs)
	{
		stringstream ss(accumulate(all(strs), string()));
		for(int tmp; ss >> tmp;) xs[n++] = tmp;

		elly = xs[0], r = (n + 19) / 20, k = n % r;
		sort(xs, xs + n, greater<int>());
		for(int i = 0; i < n;)
		{
			int j = min(i + r, n);
			ys[m++] = xs[i] >= elly && elly >= xs[j - 1]
				? elly
				: accumulate(xs + i, xs + j, 0.0) / (j - i);
			i = j;
		}

		double s = accumulate(ys, ys + m, 0.0);
		return !k || xs[n - k] >= elly
			? s / m
			: s / m * k / r + (s - ys[m - 1]) / (m - 1) * (r - k) / r;
	}
};

