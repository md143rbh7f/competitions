#include <string>
#include <vector>

using namespace std;

struct ColoredStrokes
{
	int getLeast( vector<string> a )
	{
		int n = a.size(), m = a[0].size(), ans = 0;
		for( int i = 0; i < n; i++ ) for( int j = 0; j < m; )
		{
			if( a[i][j]=='R' || a[i][j]=='G' )
			{
				int k = j;
				while( k < m && ( a[i][k]=='R' || a[i][k]=='G' ) ) k++;
				ans++;
				j = k;
			}
			else j++;
		}
		for( int j = 0; j < m; j++ ) for( int i = 0; i < n; )
		{
			if( a[i][j]=='B' || a[i][j]=='G' )
			{
				int k = i;
				while( k < n && ( a[k][j]=='B' || a[k][j]=='G' ) ) k++;
				ans++;
				i = k;
			}
			else i++;
		}
		return ans;
	}
};
