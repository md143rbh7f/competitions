#define M(x) ((x)%MOD)

long x[5005] = {1, 1}, MOD = 1000000007;

struct LongWordsDiv1
{
	int count(int n)
	{
		for(int i = 2; i <= n; i++) for(int j = 0; j < i - 1; j++)
			x[i] = M(x[i] + M(x[j] * x[i - 1 - j]));
		long ans = x[n];
		for(int i = 2; i <= n; i++) ans = M(i * ans);
		return ans;
	}
};
