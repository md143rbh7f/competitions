#include <vector>

using namespace std;

int v[500];

struct MafiaGame
{
	double probabilityToLose( int N, vector<int> d )
	{
		int n = d.size();
		for( int i = 0; i < n; i++ ) v[d[i]]++;
		int maxv = 0, vuln = 0;
		for( int i = 0; i < N; i++ )
		{
			if( v[i] == maxv ) vuln++;
			if( v[i] > maxv ) maxv = v[i], vuln = 1;
		}
		if( maxv <= 1 ) return 0;
		double ans = 1.0/vuln;
		while( true )
		{
			if( vuln == 1 ) break;
			if( vuln == 0 ) return 0;
			vuln = ( N - vuln * maxv ) % vuln;
		}
		return ans;
	}
};
