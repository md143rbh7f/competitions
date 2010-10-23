#include <vector>

using namespace std;

long long s[50], t[50], MAX = ((long long)1)<<31;
vector<int> ans;

struct AfraidOfEven
{
	vector<int> restoreProgression( vector<int> seq )
	{
		int n = seq.size();
		for( int i = 0; i < n; i++ ) s[i] = seq[i];
		for( int i = 0; i < 32; i++ ) for( int j = 0; j < 32; j++ )
		{
			t[0] = s[0]<<i, t[1] = s[1]<<j;
			if( t[0]>=MAX || t[1]>=MAX ) continue;
			long long a = t[1]-t[0];
			bool works = true;
			for( int k = 2; k < n; k++ )
			{
				bool ok = false;
				for( int l = 0; l < 32; l++ ) if( (s[k]<<l)<MAX && s[k]<<l==t[k-1]+a )
				{
					t[k]=s[k]<<l;
					ok = true;
					break;
				}
				if(!ok)
				{
					works = false;
					break;
				}
			}
			if(works)
			{
				for( int i = 0; i < n; i++ ) ans.push_back(t[i]);
				return ans;
			}
		}
		return ans;
	}
};
