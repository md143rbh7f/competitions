#include <vector>
#include <string>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

int q[50], p[50];
bool s[50][50];

struct NetworkSecurity
{
	int secureNetwork( vector<string> cc, vector<string> sc )
	{
		int n = sc.size(), m = sc[0].size(), qptr = 0, ans = 0;
		rep(i,n) rep(j,n) if(cc[i][j]=='Y') p[j]++;
		rep(i,n) if(p[i]==0) q[qptr++] = i;
		rep(i,n) rep(j,n) if(cc[q[i]][j]=='Y')
		{
			p[j]--;
			if(p[j]==0) q[qptr++] = j;
		}
		for( int i=n-1; i>=0; i-- )
		{
			int v = q[i];
			rep(j,n) if(cc[v][j]=='Y') rep(k,m) if(s[j][k]) s[v][k] = true;
			rep(j,m) if(sc[v][j]=='Y'&&!s[v][j]) s[v][j] = true, ans++;
		}
		return ans;
	}
};
