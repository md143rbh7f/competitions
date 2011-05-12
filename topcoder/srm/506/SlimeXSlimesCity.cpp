#include <algorithm>
#include <vector>

using namespace std;

struct SlimeXSlimesCity
{
	int merge( vector<int> p )
	{
		int ans = 0, n = p.size();
		sort(p.begin(),p.end());
		for( int i = 0; i < n; i++ )
		{
			long long tot = p[i];
			bool ok = true;
			for( int j = 0; j < n; j++ ) if( j != i )
			{
				if( p[j] <= tot ) tot += p[j];
				else
				{
					ok = false;
					break;
				}
			}
			if(ok) ans++;
		}
		return ans;
	}
};
