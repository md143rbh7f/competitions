typedef long long ll;

struct OddDivisors
{
	ll findSum( int n )
	{
		if(n==0) return 0;
		return (ll)((n+1)/2)*((n+1)/2)+findSum(n/2);
	}
};
