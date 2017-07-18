#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define irep(i,n) REP(i,1,n+1)

#define MAX 111
#define INF 9001

int cases, k, K, ans, t, dx, dy, s;
char b[MAX][MAX];
bool works;

int main()
{
	cin >> cases;
	irep(caseNum,cases)
	{
		ans = INF, dx = INF, dy = INF;
		cin >> k;
		K = 2*k-1;
		cin.getline( b[0], MAX );
		rep(i,MAX) rep(j,MAX) b[i][j] = 0;
		rep(i,K) cin.getline( b[i], MAX );
		rep(i,K)
		{
			rep(x,K) rep(y,K) if( b[x][y]>='0' )
			{
				t = 2*i-x;
				if( t>=0 && t<K && b[t][y]>='0' && b[t][y]!=b[x][y] ) goto badx;
			}
			dx = min( dx, abs(k-1-i) );
			badx:;
		}
		rep(j,K)
		{
			rep(x,K) rep(y,K) if( b[x][y]>='0' )
			{
				t = 2*j-y;
				if( t>=0 && t<K && b[x][t]>='0' && b[x][t]!=b[x][y] ) goto bady;
			}
			dy = min( dy, abs(k-1-j) );
			bady:;
		}
		s = k+dx+dy;
		ans = s*s-k*k;
		printf( "Case #%d: %d\n", caseNum, ans );
	}
	return 0;
}
