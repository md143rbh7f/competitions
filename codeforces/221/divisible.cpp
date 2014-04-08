#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

#define MOD 7
#define N 1000005
#define K 4

char buf[N];
int want[] = {1, 8, 6, 9};

int main()
{
	scanf("%s", buf);
	int n = strlen(buf);
	rep(i, n) buf[i] -= '0';
	rep(j, K) rep(i, n) if(buf[i] == want[j])
	{
		swap(buf[j], buf[i]);
		break;
	}
	int r = 0, p = 1;
	for(int i = n - 1; i >= K; i--) r = M(r + p * buf[i]), p = M(3 * p);
	do
	{
		int k = 0;
		rep(i, K) k = M(3 * k + buf[i]);
		if(!M(p * k + r)) break;
	}
	while(next_permutation(buf, buf + K));
	rep(i, n) buf[i] += '0';
	printf("%s\n", buf);
	return 0;
}
