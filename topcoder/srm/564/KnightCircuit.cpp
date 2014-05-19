#include <algorithm>
#include <list>
#include <utility>

using namespace std;

typedef long long ll;

bool seen[25][100005];

struct KnightCircuit
{
	ll maxSize(int w, int h, int a, int b)
	{
		if(w > h) swap(w, h);
		if(a > b) swap(a, b);
		int g = __gcd(a, b);
		if(g > 1) a /= g, b /= g, w = (w - 1) / g + 1, h = (h - 1) / g + 1;
		if(w >= a + b && h >= 2 * b)
			return a % 2 == b % 2 ? ((ll) w * h + 1) / 2 : (ll) w * h;
		int ans = 0;
		for(int i0 = 0; i0 < w; i0++) for(int j0 = 0; j0 < h; j0++)
		if(!seen[i0][j0])
		{
			int s = 0;
			list<pair<int,int>> q {{i0, j0}};
			while(!q.empty())
			{
				int i = q.front().first, j = q.front().second;
				q.pop_front();
				if(i < 0 || j < 0 || i >= w || j >= h || seen[i][j])
					continue;
				seen[i][j] = true, s++;
				q.push_back({i + a, j + b});
				q.push_back({i - a, j + b});
				q.push_back({i + a, j - b});
				q.push_back({i - a, j - b});
				q.push_back({i + b, j + a});
				q.push_back({i - b, j + a});
				q.push_back({i + b, j - a});
				q.push_back({i - b, j - a});
			}
			ans = max(ans, s);
		}
		return ans;
	}
};
