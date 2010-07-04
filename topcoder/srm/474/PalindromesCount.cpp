#include <string>

using namespace std;

char temp[111];

class PalindromesCount
{
	public:
	int count( string a, string b )
	{
		int n = a.size(), m = b.size(), p = n+m, ans = 0;
		for( int i = 0; i <= n; i++ )
		{
			for( int j = 0; j < i; j++ ) temp[j] = a[j];
			for( int j = 0; j < m; j++ ) temp[j+i] = b[j];
			for( int j = i; j < n; j++ ) temp[j+m] = a[j];
			bool works = true;
			for( int j = 0; j < p/2; j++ ) if( temp[j] != temp[p-j-1] ) works = false;
			if( works ) ans++;
		}
		return ans;
	}
};
