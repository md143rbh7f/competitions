#include <string>
#include <vector>

using namespace std;

vector<int> c;
int b, w, tot, odd;

bool ok( string & s )
{
	int n = s.size(), y = 0, x = 0;
	int c_[] = { 0, 0, 0 }, b_ = 0, tot_ = 0, odd_ = 0, need = 0;

	while(1)
	{
		if( c_[0] > c[0] || c_[1] > c[1] || c_[2] > c[2] ||
			x >= w || b_ > b || tot_ > tot || need > odd - odd_ )
			return false;
		if( y == n ) return true;

		if( s[y] == 'b' )
		{
			int z = y;
			while( z < s.size() && s[z] == 'b' ) z++;
			if( z == 1 ) return false;
			if( y == 0 && z == 3 )
			{
				y += 2, b_++, tot_ += 2;
				continue;
			}

			int d = z - y;
			if( d % 2 ) x++, tot_ += z, odd_ += z % 2;
			else tot_ += d;
			b_ += ( d + 1 ) / 2, y = z;
		}
		else c_[s[y]-'0']++, odd_++, tot_++, y++;
	}
	return false;
}

struct SkewedPerspectives
{
	vector<string> areTheyPossible( vector<int> _c, int _b, int _w, vector<string> views )
	{
		c = _c, b = _b, w = _w, odd = c[0] + c[1] + c[2], tot = odd + 2 * b;
		int n = views.size();
		vector<string> ans(n);
		for( int i = 0; i < n; i++ ) ans[i] = ok( views[i] ) ? "valid" : "invalid";
		return ans;
	}
};
