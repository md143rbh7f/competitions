#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 100

int n, a, b, c, k, prev, cur, best = 11111, tot = 0;
vi g[MAX], d[MAX];

int main()
{
	cin >> n;
	rep(i,n)
	{
		cin >> a >> b >> c;
		a--, b--;
		g[a].push_back(b), d[a].push_back(c);
		g[b].push_back(a), d[b].push_back(-c);
	}
	rep(s,2)
	{
		tot = 0, cur = 0, prev = g[cur][s];
		do
		{
			rep(i,2) if( g[cur][i]!=prev ) k = i;
			if( d[cur][k]>0 ) tot += d[cur][k];
			prev = cur, cur = g[cur][k];
		}
		while(cur);
		if( tot < best ) best = tot;
	}
	cout << best<< endl;
	return 0;
}
