#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(int i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)
#define acc(f,x,y) x=f(x,y)

#define N 105
#define INF 123456789

int x[N], y[N];
bool shot[N], used[N];
map<string,int> id;
string name[N];
double dist[N][N], dt[N][N];

void run()
{
	int n, m;
	cin >> n >> m;
	clr(x), clr(y), clr(shot), clr(used);
	id.clear();
	rep(i, n)
	{
		cin >> name[i] >> x[i] >> y[i];
		id[name[i]] = i;
	}
	rep(i, n) rep(j, n) dist[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
	rep(i, n) rep(j, n) dt[i][j] = (i != j) * INF;
	rep(i, m)
	{
		string s0, heard, s1, firing, before, s2;
		cin >> s0 >> heard >> s1 >> firing >> before >> s2;
		int i0 = id[s0], i1 = id[s1], i2 = id[s2];
		shot[i1] = shot[i2] = true;
		acc(min, dt[i2][i1], dist[i0][i2] - dist[i0][i1]);
	}
	m = 0;
	rep(i, n) m += shot[i];
	rep(k, n) rep(i, n) rep(j, n) acc(min, dt[i][j], dt[i][k] + dt[k][j]);
	rep(i, n) if(dt[i][i] < 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	vi seq;
	rep(t, m)
	{
		int it = -1;
		rep(i, n) if(shot[i] && !used[i])
		{
			bool ok = true;
			rep(j, n) if(shot[j] && !used[j] && j != i && dt[j][i] >= 0)
				ok = false;
			if(ok)
			{
				it = i;
				break;
			}
		}
		if(it == -1)
		{
			cout << "UNKNOWN" << endl;
			return;
		}
		used[it] = true;
		seq.push_back(it);
	}
	rep(i, m) cout << (i ? " " : "") << name[seq[i]];
	cout << endl;
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--) run();
	return 0;
}
