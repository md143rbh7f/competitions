#define N 5000005

bool com[N], bad[N];

struct SumAndProductPuzzle
{
long long getSum(int a, int b)
{
	b++;
	for(int i = 2; i * i < b; i++) if(!com[i])
	for(int j = 2; i * j < b; j++)
		com[i * j] = true;
	
	for(int i = 2; i * i < b; i++)
	for(int j = 2; i * j < b; j++)
		bad[i * j + 1] |= com[i + j - 1];
	
	long long ans = 0;
	for(int s = a; s < b; s++)
		ans += (com[s - 1] && !bad[s]) * s;
	return ans;
}
};
