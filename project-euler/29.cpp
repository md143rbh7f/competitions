#include <cstdio>
#include <set>
#include <vector>

using namespace std;

#define P 25
#define MIN 2
#define MAX 100

int p[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 }, f[P], a, b, c, i;
set< vector<int> > nums;

int main()
{
	for( a = MIN; a <= MAX; a++ )
	{
		c = a;
		for( i = 0; i < P; i++ ) f[i] = 0;
		for( i = 0; i < P; i++ ) while(c%p[i]==0) f[i]++, c /= p[i];
		for( b = MIN; b <= MAX; b++ )
		{
			vector<int> v(f,f+P);
			for( i = 0; i < P; i++ ) v[i] *= b;
			nums.insert(v);
		}
	}
	printf( "%d\n", (int)nums.size() );
	return 0;
}
