#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define L 42

set<long long> ok, seen;
long long f[L];
int a[50], b[50];

struct SubFibonacci
{
	int maxElements( vector<int> s )
	{
		int n = s.size();
		if( n <= 4 ) return n;
		f[1] = 1;
		for( int i = 2; i < L; i++ ) f[i] = f[i-1] + f[i-2];
		sort(s.begin(),s.end());
		for( int i = 0; i < n; i++ ) ok.insert(s[i]);
		for( int i = 0; i < n; i++ ) for( int j = i+1; j <n; j++ ) for( int m = 0; m+1 < L; m++ )
		{
			long long d = s[j] - f[m] * s[i];
			if( d <= 0 || d % f[m+1] ) continue;
			long long c = d / f[m+1];
			seen.clear();
			seen.insert(s[i]);
			for( int k = 0; k+1 < L; k++ )
			{
				long long tmp = s[i] * f[k] + c * f[k+1];
				if( ok.count(tmp) && tmp > s[i] ) seen.insert(tmp);
			}
			int tot = 0;
			for( int i = 0; i < n; i++ )
			{
				if( seen.count(s[i]) ) tot++;
				if( tot > a[i] ) a[i] = tot;
			}
			tot = 0;
			for( int i = n-1; i >= 0; i-- )
			{
				if( seen.count(s[i]) ) tot++;
				if( tot > b[i] ) b[i] = tot;
			}
		}
		int ans = 0;
		for( int i = 0; i+1 < n; i++ ) if( a[i] + b[i+1] > ans ) ans = a[i] + b[i+1];
		return ans;
	}
};
