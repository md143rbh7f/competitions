#include <vector>

using namespace std;

typedef vector<int> vi;

class OnTheFarmDivTwo
{
	public:
	vi animals( int h, int l )
	{
		vi ans;
		if( l%2 || l<2*h || l>4*h ) return ans;
		int b = l/2-h, a = h-b;
		ans.push_back( a ), ans.push_back( b );
		return ans;
	}
};
