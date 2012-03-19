#include <vector>

using namespace std;

#define L 30
#define N 55

double p[2][N];

struct KingXMagicSpells
{
	double expectedNumber( vector<int> d, vector<int> s1, vector<int> s2, int k )
	{
		int n = d.size();
		double ans = 0;
		for( int b = 0; b < L; b++ )
		{
			for( int i = 0; i < n; i++ ) p[0][i] = ( d[i] >> b ) & 1;
			for( int t = 0; t < k; t++ )
			{
				int T = t%2;
				for( int i = 0; i < n; i++ ) p[1-T][i] = 0;
				for( int i = 0; i < n; i++ )
				{
					p[1-T][i] += ( ( s1[i] >> b ) & 1 ? 1 - p[T][i] : p[T][i] ) / 2;
					p[1-T][s2[i]] += p[T][i] / 2;
				}
			}
			ans += p[k%2][0] * ( 1 << b );
		}
		return ans;
	}
};
