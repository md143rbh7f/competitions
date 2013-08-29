/*
 * The code in this file can be used to estimate the largest number of factors
 * that a number <= MAX can have.
 *
 * A number is called `highly composite' if it has more factors than any number
 * less than it. The function `largest_highly_composite' returns the largest
 * highly composite number less than `bound', as well as the number of factors
 * that it has.
 *
 * Due to the low recursion depth and branching factor, the function runs
 * instantaneously for almost all long longs.
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define N 1000
#define INF 9001
#define MAX 1e13

vector<int> primes;
bool is_prime[N+1];

void generate_primes()
{
	for( int i = 2; i <= N; i++ ) is_prime[i] = true;
	for( int i = 2; i <= N; i++ ) if( is_prime[i] )
	{
		primes.push_back(i);
		for( int j = 2 * i; j <= N; j += i ) is_prime[j] = false;
	}
}

pair< long long, int > rec( long long bound, int index, long long prod, int max_pow )
{
	long long best = prod;
	int num_div = 1;
	prod *= primes[index];
	for( int i = 1; i <= max_pow && prod <= bound; i++, prod *= primes[index] )
	{
		pair< long long, int > next = rec( bound, index + 1, prod, i );
		if( ( i + 1 ) * next.second > num_div )
		{
			best = next.first;
			num_div = ( i + 1 ) * next.second;
		}
	}
	return make_pair( best, num_div );
}

pair< long long, int > largest_highly_composite( long long bound )
{
	return rec( bound, 0, 1, INF );
}

int main()
{
	generate_primes();

	pair<long long,int> ans = largest_highly_composite( MAX );
	cout << "The largest highly composite number <= " << MAX;
	cout << " is " << ans.first;
	cout << " which has " << ans.second << " factors." << endl;

	return 0;
}
