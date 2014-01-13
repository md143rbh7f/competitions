#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 4005
#define M 36005

int tot[N], a, n;
string s;
ll cnt[M];

int main()
{
	cin >> a >> s;
	n = s.size();
	rep(i, n) tot[i+1] = tot[i] + s[i] - '0';
	rep(i, n) range(j, i, n) cnt[tot[j + 1] - tot[i]]++;
	ll ans = 0;
	if(!a) ans = cnt[0] * (n * (n + 1) - cnt[0]);
	else range(i, 1, M) if(!(a % i) && a/i < M) ans += cnt[i] * cnt[a/i];
	cout << ans << endl;
	return 0;
}
