#include <vector>

using namespace std;

double p_end[80010];

struct FoxListeningToMusic
{
	vector<double> getProbabilities( vector<int> len, int T )
	{
		int n = len.size();
		vector<double> ans(n);
		p_end[0] = 1;
		for( int t = 0; t < T; t++ ) for( int i = 0; i < n; i++ ) if( t+len[i] <= T ) p_end[t+len[i]] += p_end[t] / n;
		for( int i = 0; i < n; i++ ) for( int t = 0; t < len[i] && t <= T; t++ ) ans[i] += p_end[T-t] / n;
		return ans;
	}
};
