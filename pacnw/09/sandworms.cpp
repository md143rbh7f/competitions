#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> worm;
#define mp(a,b) make_pair((a),(b))
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define L 55
#define OVER_NINE_THOUSAND 9001

char buf[L];
vs g;
set< pair<int,worm> > q;
map<worm,int> dist;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 }, n, m;

int main()
{
	while(1)
	{
		g.clear();
		while(1)
		{
			cin.getline(buf,L);
			if(!buf[0]) break;
			if(buf[0]=='e') return 0;
			g.push_back(string(buf));
		}
		n = g.size(), m = g[0].size();
		worm w;
		rep(i,n) w.push_back(mp(i,0));
		q.insert(mp(0,w));
		dist.clear();
		while(!q.empty())
		{
			int di = q.begin()->first;
			worm v = q.begin()->second;
			q.erase(q.begin());
			if(di==dist[v]) rep(S,2)
			{
				int s = S*(n-1), sx = v[s].first, sy = v[s].second;
				rep(d,4)
				{
					int tx = sx+dx[d], ty = sy+dy[d];
					if(tx<0||tx>=n||ty<0||ty>=m) continue;
					bool ok = true;
					rep(i,n) if( i!=n-1-s && ( (v[i].first==tx&&v[i].second==ty) || g[v[i].first][v[i].second]==g[tx][ty] ) ) ok = false;
					if(!ok) continue;
					worm u;
					if(S==0) u.push_back(mp(tx,ty));
					rep(i,n) if(i!=n-1-s) u.push_back(v[i]);
					if(S==1) u.push_back(mp(tx,ty));
					if( dist.find(u)==dist.end() || di+1<dist[u] ) dist[u] = di+1, q.insert(mp(di+1,u));
				}
			}
		}
		int ans = OVER_NINE_THOUSAND;
		worm e;
		rep(i,n) e.push_back(mp(i,m-1));
		if(dist.find(e)!=dist.end()) ans = min(ans,dist[e]);
		reverse(e.begin(),e.end());
		if(dist.find(e)!=dist.end()) ans = min(ans,dist[e]);
		cout << ( ans==OVER_NINE_THOUSAND ? -1 : ans ) << endl;
	}
	return 0;
}
