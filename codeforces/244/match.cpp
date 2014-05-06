#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)

#define N 5005

string s, t;
int ms[N], mt[N], dp[N];

void shortest(string & s, int m[N])
{
	clr0(dp);
	for(int i = s.size() - 1; i >= 0; i--) rep(j, s.size())
	if(s[i] == s[j] && i != j)
		m[i] = max(m[i], dp[j] = dp[j + 1] + 1);
	else dp[j] = 0;
}

int main()
{
	cin >> s >> t;
	shortest(s, ms), shortest(t, mt);

	clr0(dp);
	int ans = N;
	for(int i = s.size() - 1; i >= 0; i--) rep(j, t.size())
	if(s[i] == t[j])
	{
		dp[j] = dp[j + 1] + 1;
		if(dp[j] > ms[i] && dp[j] > mt[j])
			ans = min(ans, 1 + max(ms[i], mt[j]));
	}
	else dp[j] = 0;

	cout << (ans < N ? ans : -1) << endl;

	return 0;
}
