#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)

#define N 100005

bool p[N], used[N];

int main()
{
	int n;
	scanf("%d", &n);

	range(i, 2, n + 1) p[i] = true;
	range(i, 2, n + 1) if(p[i]) for(int j = 2 * i; j <= n; j += i)
		p[j] = false;

	vector<pii> ans;
	int last = -1;
	for(int i = n / 2; i >= 2; i--) if(p[i])
	{
		vector<int> xs;
		for(int j = 2 * i; j <= n; j += i) if(!used[j])
		{
			used[j] = true;
			xs.push_back(j);
		}
		xs.push_back(i);
		for(int j = xs.size() % 2; j < xs.size(); j += 2)
			ans.push_back({xs[j], xs[j + 1]});
		if(xs.size() % 2)
		{
			if(last == -1) last = 2 * i;
			else ans.push_back({last, 2 * i}), last = -1;
		}
	}

	printf("%d\n", (int) ans.size());
	for(auto p : ans) printf("%d %d\n", p.first, p.second);

	return 0;
}
