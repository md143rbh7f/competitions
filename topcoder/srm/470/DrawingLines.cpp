#include <vector>

using namespace std;

#define MAX 10000

int from[MAX+1], before[MAX+1];
bool used[MAX+1];

class DrawingLines
{
	public:
	double countLineCrossings( int n, vector<int> A, vector<int> B )
	{
		double ans = 0;
		int m = A.size();
		for( int i = 0; i < m; i++ )
		{
			from[B[i]] = A[i];
			used[A[i]] = true;
		}
		for( int i = 2; i <= n; i++ ) before[i] = before[i-1]+(used[i-1]?0:1);
		for( int i = 1; i <= n; i++ ) for( int j = i+1; j <= n; j++ )
		{
			if( from[i] && from[j] ) ans += from[i]>from[j] ? 1 : 0;
			else if( from[i] ) ans += 1.0*before[from[i]]/(n-m);
			else if( from[j] ) ans += 1.0*(n-m-before[from[j]])/(n-m);
			else ans += 0.5;
		}
		return ans;
	}
};
