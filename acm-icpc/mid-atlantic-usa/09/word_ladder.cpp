#include <iostream>
#include <string>

using namespace std;

#define MAX 505

int n, g[MAX][MAX];
string w[MAX];

int main()
{
	while(1)
	{
		cin >> n;
		if(!n) break;
		for( int i = 0; i < n; i++ ) cin >> w[i];
		for( int i = 0; i < n; i++ ) for( int j = i+1; j < n; j++ )
		{
			int edge = MAX;
			string s = w[i], t = w[j];
			if( s.size() > t.size() ) s = w[j], t = w[i];
			if( s.size() == t.size() )
			{
				int d = 0;
				for( int i = 0; i < s.size(); i++ ) if( s[i] != t[i] ) d++;
				if( d <= 1 ) edge = 1;
			}
			else if( s.size() + 1 == t.size() )
			{
				for( int i = 0; i < t.size(); i++ )
				{
					bool ok = true;
					for( int j = 0; j < i; j++ ) if( s[j] != t[j] ) ok = false;
					for( int j = i; j < s.size(); j++ ) if( s[j] != t[j+1] ) ok = false;
					if( ok ) edge = 1;
				}
			}
			g[i][j] = g[j][i] = edge;
		}
		for( int k = 0; k < n; k++ ) for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
		if( g[i][k] + g[k][j] < g[i][j] )
			g[i][j] = g[i][k] + g[k][j];
		int ans = 0;
		for( int i = 0; i < n; i++ ) for( int j = i+1; j < n; j++ )
		if( g[i][j] < MAX && g[i][j] > ans )
			ans = g[i][j];
		cout << ans + 1 << endl;
	}
	return 0;
}
