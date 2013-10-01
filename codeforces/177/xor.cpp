#include <iostream>

using namespace std;

#define N 1000005

int n, k = 1, p[N];
long long ans;

int main()
{
	cin >> n;
	while(k < n) k = 2 * k + 1;
	for(int i = n; i; i--)
	{
		if(k / 2 >= i) k /= 2;
		if(!p[i]) p[i] = k^i, p[k^i] = i, ans += k;
	}
	cout << 2 * ans << endl;
	for(int i = 0; i < n; i++) cout << p[i] << " ";
	cout << p[n] << endl;
	return 0;
}
