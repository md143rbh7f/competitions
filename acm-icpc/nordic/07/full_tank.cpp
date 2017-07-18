#include <cstring>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define CLR(i,n) memset(i,n,sizeof(i))

#define MAX 1000
#define INF 123456789

int n, m, o, p[MAX], d[101][MAX], x, y, z, u, v, w;
vi g[MAX], h[MAX], U;
set<vi> q;

vi tri( int a, int b, int c )
{
	vi ret(3);
	ret[0] = a, ret[1] = b, ret[2] = c;
	return ret;
}

int main()
{
	scanf( "%d%d", &n, &m );
	rep(i,n)
	{
		scanf( "%d", &p[i] );
		g[i].push_back(i), h[i].push_back(0);
	}
	rep(i,m)
	{
		scanf( "%d%d%d", &x, &y, &z );
		g[x].push_back(y), h[x].push_back(z);
		g[y].push_back(x), h[y].push_back(z);
	}
	scanf( "%d", &o );
	while(o--)
	{
		scanf( "%d%d%d", &z, &x, &y );
		CLR(d,INF);
		d[0][x] = 0;
		q.clear();
		// cost, fuel amt, node
		q.insert(tri(0,0,x));
		while(!q.empty())
		{
			U = *q.begin(), q.erase(q.begin()), u = U[2];
			if(U[0]>d[U[1]][U[2]]) continue;
			if(u==y) break;
			// go to other city
			rep(i,g[u].size())
			{
				v = U[1]-h[u][i], w = g[u][i];
				if( v>=0 && U[0]<d[v][w] )
				{
					d[v][w] = U[0];
					q.insert(tri(d[v][w],v,w));
				}
			}
			// get gas
			v = U[1]+1;
			if( v<=z && U[0]+p[u]<d[v][u] )
			{
				d[v][u] = U[0]+p[u];
				q.insert(tri(d[v][u],v,u));
			}
		}
		if(d[0][y]<INF) printf( "%d\n", d[0][y] );
		else printf( "impossible\n" );
	}
	return 0;
}
