#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define MAX 30

map< vector<int>, map<int, double> > mem;
int n;

double rec( vector<int> & comps, int bad )
{
	if( mem.count( comps ) && mem[comps].count( bad ) ) return mem[comps][bad];

	double & ans = mem[comps][bad];
	if( comps[n] == 1 ) return ans = 0;

	double acc = 0;
	int tot = bad;
	for( int i = 1; i <= n; i++ ) if( comps[i] )
	{
		if( comps[i] >= 2 )
		{
			int good = i * i * comps[i] * ( comps[i] - 1 ) / 2;
			tot += good;

			comps[i] -= 2, comps[2*i]++;
			acc += rec( comps, bad + i * i - 1 ) * good;
			comps[i] += 2, comps[2*i]--;
		}

		for( int j = i + 1; j <= n; j++ ) if( comps[j] )
		{
			int good = i * j * comps[i] * comps[j];
			tot += good;

			comps[i]--, comps[j]--, comps[i+j]++;
			acc += rec( comps, bad + i * j - 1 ) * good;
			comps[i]++, comps[j]++, comps[i+j]--;
		}
	}
	ans = 1 + ( acc + ( bad ? rec( comps, bad - 1 ) * bad : 0 ) ) / tot;

	return ans;
}

void generate()
{
	for( n = 1; n <= MAX; n++ )
	{
		vector<int> comps(n+1);
		comps[1] = n;
		printf( "%d\n", (int) rec( comps, 0 ) );
	}
}

int answers[] = { 0, 0, 1, 2, 3, 4, 6, 7, 9, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 37, 39, 41, 44, 46, 48, 51, 53, 55 };

int main()
{
	scanf( "%d", &n );
	printf( "%d\n", answers[n] );
	return 0;
}
