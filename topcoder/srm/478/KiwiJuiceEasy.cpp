#include <vector>

using namespace std;

typedef vector<int> vi;

struct KiwiJuiceEasy
{
	vi thePouring( vi c, vi x, vi a, vi b )
	{
		int m = a.size();
		for( int i = 0; i < m; i++ )
		{
			int A = x[a[i]], B = x[b[i]];
			if( A+B<c[b[i]] ) x[a[i]] = 0, x[b[i]] = A+B;
			else x[a[i]] = A+B-c[b[i]], x[b[i]] = c[b[i]];
		}
		return x;
	}
};
