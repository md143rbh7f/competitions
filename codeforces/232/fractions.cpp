#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

bool is_prime(ll n)
{
	for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;
	return true;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		ll v = n, u = n + 1;
		while(!is_prime(v)) v--;
		while(!is_prime(u)) u++;
		ll num = 2 * (n - 1) + (v - 2) * (u - 2);
		ll den = 2 * v * u;
		ll g = __gcd(num, den);
		num /= g, den /= g;
		cout << num << "/" << den << endl;
	}
	return 0;
}
