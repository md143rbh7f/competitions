#include <iostream>
#include <map>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%1000000007)

#define N 16666
#define K 555

int ncr[N][K];

int main()
{
	rep(i, N) ncr[i][0] = 1;
	range(i, 1, N) range(j, 1, K) ncr[i][j] = M(ncr[i-1][j] + ncr[i-1][j-1]);

	int n;
	cin >> n;

	map<int,int> ps;
	rep(i, n)
	{
		int a;
		cin >> a;
		for(int p = 2; p * p <= a; p++) while(a % p == 0) ps[p]++, a /= p;
		if(a > 1) ps[a]++;
	}

	long long ans = 1;
	for(auto & p : ps) ans = M(ans * ncr[p.second + n - 1][n - 1]);
	cout << ans << endl;

	return 0;
}
