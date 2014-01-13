#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

int c[100005][3], d[3];

int main()
{
	string s;
	int m;
	cin >> s >> m;
	rep(i, s.size()) rep(j,3) c[i+1][j] = c[i][j] + (s[i] == 'x' + j);
	rep(i, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		rep(j, 3) d[j] = c[b][j] - c[a][j];
		sort(d, d + 3);
		cout << (b - a <3 || d[2] - d[0] <= 1 ? "YES" : "NO") << endl;
	}
	return 0;
}
