#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define top 10

int t, n, N, tmp, win[top] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };
char buf[50];
map<string,int> pts;
map<string,map<int,int> > place;
set<string> names;
string sorted[50];

bool c1( string a, string b )
{
	if( pts[a]!=pts[b] ) return pts[a]>pts[b];
	if( place[a][0]!=place[b][0] ) return place[a][0]>place[b][0];
	REP(i,1,n) if( place[a][i]!=place[b][i] ) return place[a][i]>place[b][i];
	return false;
}

bool c2( string a, string b )
{
	if( place[a][0]!=place[b][0] ) return place[a][0]>place[b][0];
	if( pts[a]!=pts[b] ) return pts[a]>pts[b];
	REP(i,1,n) if( place[a][i]!=place[b][i] ) return place[a][i]>place[b][i];
	return false;
}

int main()
{
	cin >> t;
	rep(i,t)
	{
		cin >> n;
		rep(j,n)
		{
			cin >> buf;
			names.insert(buf);
			if( j<top ) pts[buf] += win[j];
			place[buf][j]++;
		}
	}
	N = names.size();
	foreach(i,names) sorted[tmp++] = *i;
	sort( sorted, sorted+N, c1 );
	cout << sorted[0] << endl;
	sort( sorted, sorted+N, c2 );
	cout << sorted[0] << endl;
	return 0;
}
