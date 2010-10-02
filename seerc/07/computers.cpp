#include <iostream>

using namespace std;

typedef long long ll;
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)

#define MAX 3000

int c,n;
ll m[MAX][MAX],dp[MAX][MAX];

int main()
{
	while(1)
	{
		cin >> c >> n;
		if(cin.fail()) break;
		rep(i,n) REP(j,i,n) cin >> m[i][j];
		rep(i,n) dp[i][n-1]=m[i][n-1];
		for(int j=n-2;j>=0;j--) rep(i,j+1) dp[i][j]=min(dp[i][j+1],m[i][j]+dp[j+1][j+1]+c);
		cout << dp[0][0]+c << endl;
	}
	return 0;
}
