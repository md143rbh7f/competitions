#include <set>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

set<int> primes;
set<vi> nums;
vi ZERO(1,-1);

vi powers( int x )
{
	vi ans;
	foreach(p,primes)
	{
		int c = 0;
		while( x%(*p) == 0 )
		{
			x /= *p;
			c++;
		}
		ans.push_back(c);
	}
	return ans;
}

void do_sequence( int b, int q, int n )
{
	if( b == 0 )
	{
		nums.insert(ZERO);
		return;
	}
	vi B = powers(b);
	if( q == 0 )
	{
		nums.insert(B);
		if( n > 1 ) nums.insert(ZERO);
		return;
	}
	vi Q = powers(q);
	while(n--)
	{
		nums.insert(B);
		for( int i = 0; i < B.size(); i++ ) B[i] += Q[i];
	}
}

void get_primes( int x )
{
	if( x==0 || x==1 ) return;
	for( int p = 2; p*p <= x; p++ ) if( x%p == 0 )
	{
		primes.insert(p);
		while( x%p == 0 ) x /= p;
	}
	if( x>1 ) primes.insert(x);
}

struct GeometricProgressions
{
	int count( int b1, int q1, int n1, int b2, int q2, int n2 )
	{
		get_primes(b1);
		get_primes(q1);
		get_primes(b2);
		get_primes(q2);
		do_sequence(b1,q1,n1);
		do_sequence(b2,q2,n2);
		return nums.size();
	}
};
