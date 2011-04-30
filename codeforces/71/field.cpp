#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 40010

string plants[3] = { "Carrots", "Kiwis", "Grapes" };
int n, m, k, t, x, y, prev[MAX];
vector<int> waste[MAX];

int main()
{
	cin >> n >> m >> k >> t;
	while(k--)
	{
		cin >> x >> y;
		x--, y--;
		waste[x].push_back(y);
	}
	rep(i,n) sort(waste[i].begin(),waste[i].end());
	rep(i,n-1) prev[i+1] = prev[i] + waste[i].size();
	while(t--)
	{
		cin >> x >> y;
		x--, y--;
		int p = 0;
		if( waste[x].size() )
		{
			p = waste[x].size()-1;
			for( int d = 1<<16; d; d >>= 1 ) if( p-d >= 0 && waste[x][p-d] >= y ) p -= d;
			if( waste[x][p] == y )
			{
				cout << "Waste" << endl;
				continue;
			}
		}
		cout << plants[ ( x * m - prev[x] + y - p + 3 ) % 3 ] << endl;
	}
	return 0;
}
