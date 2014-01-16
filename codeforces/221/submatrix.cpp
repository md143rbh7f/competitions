#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

#define N 5005

int len[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	rep(i, n)
	{
		string buf;
		cin >> buf;
		for(int j = m - 1; j >= 0; j--) if(buf[j] - '0') len[i][j] = len[i][j+1] + 1;
	}
	int best = 0;
	rep(j, m)
	{
		vi l;
		rep(i, n) if(len[i][j]) l.push_back(len[i][j]);
		sort(all(l)), reverse(all(l));
		int cnt = 0;
		for(int & k : l) best = max(best, k * (++cnt));
	}
	cout << best << endl;
	return 0;
}
