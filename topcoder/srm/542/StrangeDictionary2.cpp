#include <string>
#include <vector>

using namespace std;

#define N 16
#define M 55

vector<string> strs;
int n, m, next[1<<N][M];
double prob[1<<N];

double get_prob( int cur )
{
	int good = 1<<cur, mask = good;
	prob[mask] = 1;
	while(1)
	{
		mask = ( mask + 1 ) | good;
		if( mask >= 1<<n ) break;
		prob[mask] = 0;
		int c = 0;
		for( int s = 0; s < m; s++ ) if( next[mask][s] < mask )
		{
			if( next[mask][s] & good ) prob[mask] += prob[next[mask][s]];
			c++;
		}
		prob[mask] /= c;
	}
	return prob[(1<<n)-1];
}

struct StrangeDictionary2
{
	vector<double> getProbabilities( vector<string> _strs )
	{
		strs = _strs, n = strs.size(), m = strs[0].size();
		
		for( int mask = 0; mask < 1<<n; mask++ ) for( int s = 0; s < m; s++ )
		{
			char c = 'z';
			for( int i = 0; i < n; i++ ) if( ( mask >> i ) & 1 )
			{
				if( strs[i][s] < c ) c = strs[i][s], next[mask][s] = 0;
				if( strs[i][s] == c ) next[mask][s] |= 1<<i;
			}
		}
		
		vector<double> ans;
		for( int i = 0; i < n; i++ ) ans.push_back( get_prob(i) );
		return ans;
	}
};
