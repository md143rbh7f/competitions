#include <string>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

struct CutTheNumbers
{
	int maximumSum( vector<string> board )
	{
		int n = board.size(), m = board[0].size(), ans = 0;
		rep(mask,1<<(n*m))
		{
			int seen = 0, sum = 0;
			rep(i,n) rep(j,m) if(!(1&(seen>>(i*m+j))))
			{
				int x = i, y = j, tmp = 0;
				while( x < n && y < m && (1&(mask>>(i*m+j))) == (1&(mask>>(x*m+y))) )
				{
					tmp = 10 * tmp + board[x][y] - '0';
					seen |= 1<<(x*m+y);
					if( (1&(mask>>(i*m+j))) ) x++;
					else y++;
				}
				sum += tmp;
			}
			if( sum > ans ) ans = sum;
		}
		return ans;
	}
};
