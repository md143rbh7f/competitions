#include <string>
#include <vector>

using namespace std;

long long len[101];

struct MagicalGirlLevelThreeDivTwo
{
	int theCount( vector<string> first, int N, long long a, long long b )
	{
		int k = first.size();
		for( int i = 0; i < k; i++ ) len[i] = first[i].size();
		for( int i = k; i <= N; i++ ) for( int j = i-1; j >= 0; j -= k ) len[i] = min( b+1, len[i] + len[j] );
		int ans = 0;
		for( long long I = a; I <= b; I++ )
		{
			int n = N;
			long long i = I;
			while( n >= k )
			{
				n--;
				while( i >= len[n] )
				{
					i -= len[n];
					n -= k;
				}
			}
			if( first[n][i] == '1' ) ans++;
		}
		return ans;
	}
};
