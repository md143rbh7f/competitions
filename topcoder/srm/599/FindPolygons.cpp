#include <algorithm>
#include <vector>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

struct line
{
	int r, x, y;
	
	bool operator<(const line & o) const
	{
		if(r != o.r) return r < o.r;
		if(x != o.x) return x < o.x;
		return y < o.y;
	}
};

struct FindPolygons
{
	double minimumPolygon(int L)
	{
		if(L % 2 || L < 4) return -1;

		vector<line> ls;
		int L2 = (L + 1) / 2;
		rep(x, L2) rep(y, L2)
		{
			int r2 = x * x + y * y, r = sqrt(r2);
			if(r < L2 && r * r == r2) ls.push_back({r, x, y});
		}
		sort(all(ls));

		int n = ls.size(), ans = L;
		rep(i, n)
		{
			line & a = ls[i];
			if(a.x < a.y) continue;
			range(j, i + 1, n)
			{
				line & b = ls[j];
				if(b.r + a.r >= L) break;
				int cr = L - a.r - b.r, cx = a.x - b.x, cy = a.y - b.y;
				if(cr * cr != cx * cx + cy * cy) continue;
				ans = min(ans, max(a.r, max(b.r, cr)) - min(a.r, min(b.r, cr)));
			}
		}

		if(ans == L) ans = (bool)(L % 4);
		return ans;
	}
};
