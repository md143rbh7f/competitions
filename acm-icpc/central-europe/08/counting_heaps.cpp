#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr(i) CLR(i,0)

#define N 500005
#define M 42000

int np, pid[N], pri[M];
vector<int> fac[N], ex[N];

int n, m, par[N], sz[N], cnt[N], exs[M];

ll mod_pow(ll a, int b)
{
	if(!b) return 1;
	return (b % 2 ? a : 1) * mod_pow(a * a % m, b / 2) % m;
}

void run()
{
	cin >> n >> m;
	range(i,1,n) cin >> par[i];
	for(int i = n - 1; i >= 0; i--)
	{
		cnt[++sz[i]]--;
		if(i) sz[par[i]-1] += sz[i];
		sz[i] = 0;
	}
	range(i,2,n+1)
	{
		cnt[i]++;
		if(!cnt[i]) continue;
		rep(j,fac[i].size()) exs[fac[i][j]] += cnt[i] * ex[i][j];
		cnt[i] = 0;
	}
	ll ans = 1;
	rep(i,np) ans = ans * mod_pow(pri[i], exs[i]) % m, exs[i] = 0;
	cout << ans << endl;
}

int main()
{
	pid[0] = pid[1] = -1;
	range(i,2,N) if(pid[i] >= 0)
	{
		pid[i] = np, pri[np] = i, np++;
		for(int j = 2 * i; j < N; j += i) pid[j] = -1;
	}
	range(i,2,N)
	{
		int x = i;
		rep(k,np)
		{
			int p = pri[k];
			if(x % p == 0)
			{
				int c = 0;
				while(x % p == 0) x /= p, c++;
				fac[i].push_back(pid[p]), ex[i].push_back(c);
			}
			if(x == 1) break;
		}
	}

	int t;
	for(cin >> t; t--; run());
	return 0;
}
