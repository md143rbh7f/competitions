#include <string>
#include <vector>

using namespace std;

#define MAX 1001

vector<int> ans;
bool p[MAX];
int a[50], b[50];

struct ColorfulCards
{
	vector<int> theCards( int n, string c )
	{
		for( int i = 2; i <= n; i++ ) p[i] = true;
		for( int i = 2; i <= n; i++ ) if(p[i]) for( int j = 2*i; j <= n; j += i ) p[j] = false;
		int m = c.size();
		for( int i = 0; i < m; i++ ) c[i] = c[i]=='R';
		for( int i = 0; i < m; i++ )
		{
			a[i] = i ? a[i-1]+1 : 1;
			while( c[i] != p[a[i]] ) a[i]++;
		}
		for( int i = m-1; i >= 0; i-- )
		{
			b[i] = i<m-1 ? b[i+1]-1 : n;
			while( c[i] != p[b[i]] ) b[i]--;
		}
		for( int i = 0; i < m; i++ ) ans.push_back( a[i]==b[i] ? a[i] : -1 );
		return ans;
	}
};
