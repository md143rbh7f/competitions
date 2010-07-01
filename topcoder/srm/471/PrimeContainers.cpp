#include <cmath>

using namespace std;

#define MAX 1000000

bool isPrime[MAX+1];

void generate()
{
	for( int i = 2; i <= MAX; i++ ) isPrime[i] = true;
	for( int i = 2; i <= sqrt(MAX); i++ )
		if( isPrime[i] )
			for( int j = 2*i; j <= MAX; j += i )
				isPrime[j] = false;
}

class PrimeContainers
{
	public:
	int containerSize( int n )
	{
		generate();
		int ans = 0;
		while( n )
		{
			if( isPrime[n] ) ans++;
			n >>= 1;
		}
		return ans;
	}
};
