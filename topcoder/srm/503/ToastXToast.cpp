#include <algorithm>
#include <vector>

using namespace std;

struct ToastXToast
{
	int bake( vector<int> a, vector<int> b )
	{
		int n = a.size(), m = b.size();
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		if( a[0] > b[0] || a[n-1] > b[m-1] ) return -1;
		if( a[n-1] < b[0] ) return 1;
		return 2;
	}
};
